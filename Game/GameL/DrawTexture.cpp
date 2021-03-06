#include "DrawTexture.h"
using namespace GameL;

#define SAFE_RELEASE(p)      { if (p) { (p)->Release();    (p)=nullptr;  }	}
#define SAFE_RESET(p)		 { if (p) { (p).reset(nullptr);				 }  }

//ポリゴン構造体
struct DRAW_POLYGON
{
	float		   pos[3];	//x-y-z頂点情報
	unsigned int   id[2];	//ＵＶのＩＤ
};

//Draw2DTex.hlslグローバル
struct DRAW_2D_TEX
{
	float size[4];		//画面サイズ
	float color[4];		//カラー情報
	float rect_in[4];	//切り取り位置
	float rect_out[4];	//貼り付け位置
};


//デバイス
ID3D11DeviceContext*CDrawTexture::m_pDeviceContext;
ID3D11Device*		CDrawTexture::m_pDevice; 

//テクスチャ情報
vector< shared_ptr<C_TEX_DATA> > CDrawTexture::vec_tex_data;

//ウィンドウ情報
int CDrawTexture::m_width ;
int CDrawTexture::m_height; 

//取得イメージ最大数
int CDrawTexture::m_img_max;

//シェーダ関係
ID3D11VertexShader* CDrawTexture::m_pVertexShader;		//バーテックスシェーダー
ID3D11PixelShader*  CDrawTexture::m_pPixelShader;		//ピクセルシェーダー
ID3D11SamplerState* CDrawTexture::m_pSampleLinear;		//テクスチャーサンプラー
ID3D11InputLayout*  CDrawTexture::m_pVertexLayout;		//頂点入力レイアウト
//バッファ
ID3D11Buffer*		CDrawTexture::m_pVertexBuffer;		//２Ｄポリゴン用バーティクスバッファ
ID3D11Buffer*		CDrawTexture::m_pConstantBuffer;	//アプリ←→シェーダー架け橋 コンスタントバッファ
ID3D11Buffer*		CDrawTexture::m_pIndexBuffer;		//インデックスバッファ


//テクスチャ保存用クラスメソッド郡----------------
C_TEX_DATA::C_TEX_DATA()
{	
	m_pSRV		= nullptr;
	m_tex_size	= TEX_SIZE_128;
}

C_TEX_DATA::~C_TEX_DATA()
{
	SAFE_RELEASE(m_pSRV);
	m_tex_size	= TEX_SIZE_128;
}

ID3D11ShaderResourceView** C_TEX_DATA::GetTexData()
{
	return &m_pSRV;
}

TEX_SIZE C_TEX_DATA::GetTexSize()
{
	return m_tex_size;
}
			
void C_TEX_DATA::SetTexData(ID3D11ShaderResourceView* tex)
{
	m_pSRV=tex;
}

void C_TEX_DATA::SetTexSize(TEX_SIZE size)
{
	m_tex_size=size;
}
	
//テクスチャ読み込み・表示クラスメソッド郡-------
//２D使用設定
void  CDrawTexture::Set2DDraw()
{
	//頂点レイアウト
	m_pDeviceContext->IASetInputLayout( m_pVertexLayout );

	//輸送バッファ固定
	m_pDeviceContext->VSSetConstantBuffers(0,1,&m_pConstantBuffer );
	m_pDeviceContext->PSSetConstantBuffers(0,1,&m_pConstantBuffer );

	//使用するシェーダーの登録
	m_pDeviceContext->VSSetShader(m_pVertexShader,NULL,0);
	m_pDeviceContext->PSSetShader(m_pPixelShader,NULL,0);

	//プリミティブ・トポロジーをセット
	m_pDeviceContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP  );

	//テクスチャーをシェーダーに渡す
	m_pDeviceContext->PSSetSamplers(0,1,&m_pSampleLinear);

	//バーテックスバッファ登録
	UINT stride = sizeof( DRAW_POLYGON ),offset = 0;
	m_pDeviceContext->IASetVertexBuffers( 0, 1, &m_pVertexBuffer, &stride, &offset );

	//インデックスバッファ登録
	m_pDeviceContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
}

//当たり判定描画
void CDrawTexture::DrawHitBox(float x,float y,float h,float w,float col[4])
{
	//２D使用設定
	Set2DDraw();
	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=0.0f;				data.size[1]=0.0f;
		data.size[2]=(float)m_width;	data.size[3]=(float)m_height;

		data.rect_out[0]=(float)x;		data.rect_out[1]=(float)y;
		data.rect_out[2]=(float)x+w;	data.rect_out[3]=(float)y+h;

		data.rect_in[0]=0.0f;			data.rect_in[1]=0.0f;
		data.rect_in[2]=0.0f;			data.rect_in[3]=0.0f;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

//文字描画
void CDrawTexture::DrawStr(ID3D11ShaderResourceView* ptex_res_view,float x,float y,float size,float col[4])
{
	//２D使用設定
	Set2DDraw();
	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=1.0f;				data.size[1]=0.0f;
		data.size[2]=(float)m_width;	data.size[3]=(float)m_height;

		data.rect_out[0]=(float)x;		data.rect_out[1]=(float)y;
		data.rect_out[2]=(float)x+size;	data.rect_out[3]=(float)y+size;

		data.rect_in[0]=0.0f;			data.rect_in[1]=0.0f;
		data.rect_in[2]=1.0f;			data.rect_in[3]=1.0f;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//テクスチャ設定
	m_pDeviceContext->PSSetShaderResources(0,1, &ptex_res_view);

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

//描画
void CDrawTexture:: Draw(int id,RECT_F* src,RECT_F* dst,float col[4],float r)
{
	if(m_img_max < id ) return ;
	if(vec_tex_data[id]->GetTexData()==nullptr) return ; 

	//２D使用設定
	Set2DDraw();

	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=(float)vec_tex_data[id]->GetTexSize();	data.size[1]=r;
		data.size[2]=(float)m_width;		data.size[3]=(float)m_height;

		data.rect_out[0]=dst->m_left;		data.rect_out[1]=dst->m_top;
		data.rect_out[2]=dst->m_right;		data.rect_out[3]=dst->m_bottom;

		data.rect_in[0]=src->m_left;		data.rect_in[1]=src->m_top;
		data.rect_in[2]=src->m_right;		data.rect_in[3]=src->m_bottom;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//テクスチャ設定
	m_pDeviceContext->PSSetShaderResources(0,1,vec_tex_data[id].get()->GetTexData());

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);

}


//描画環境構築する
void CDrawTexture::InitDraw(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context,int w,int h,int img_max)
{

	m_pDevice		= p_device;
	m_pDeviceContext= p_device_context;

	//ウィンドウ情報取得
	m_width =w;
	m_height=h; 

	//取得イメージ最大数を元に許容量と要素数を設定
	m_img_max=img_max;
	vec_tex_data.reserve(m_img_max);//配列の許容量設定
	vec_tex_data.resize(m_img_max);	//配列の要素数設定
	

	//取得テクスチャメモリ確保
	for(int i=0; i<m_img_max;i++)
	{
		vec_tex_data[i].reset(new C_TEX_DATA());
	}

	//hlslファイル名
	const wchar_t* hlsl_name=L"GameL\\Draw2DTex.hlsl";
	
	//hlslファイル読み込み ブロブ作成　ブロブとはシェーダーの塊みたいなもの。
	//XXシェーダーとして特徴を持たない。後で各種シェーダーとなる
	ID3DBlob *pCompiledShader=NULL;
	ID3DBlob *pErrors		 =NULL;
	//ブロブからバーテックスシェーダー作成
	if(FAILED(D3DX11CompileFromFile(hlsl_name,NULL,NULL,"vs","vs_4_0",0,0,NULL,&pCompiledShader,&pErrors,NULL)))
	{
		wchar_t* c=(wchar_t*)pErrors->GetBufferPointer();
		MessageBox(0,L"hlsl読み込み失敗",NULL,MB_OK);
		return ;
    }
	SAFE_RELEASE(pErrors);
	
	if(FAILED(m_pDevice->CreateVertexShader(pCompiledShader->GetBufferPointer(),pCompiledShader->GetBufferSize(),NULL,&m_pVertexShader)))
	{
		SAFE_RELEASE(pCompiledShader);
		MessageBox(0,L"バーテックスシェーダー作成失敗",NULL,MB_OK);
		return ;
	}
	
	//頂点インプットレイアウトを定義	
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_UINT	, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
	};
	UINT numElements = sizeof(layout)/sizeof(layout[0]);
	//頂点インプットレイアウトを作成・レイアウトをセット
	if( FAILED(m_pDevice->CreateInputLayout( layout, numElements, pCompiledShader->GetBufferPointer(), pCompiledShader->GetBufferSize(), &m_pVertexLayout ) ) )
		return ;
	SAFE_RELEASE(pCompiledShader);

	//ブロブからピクセルシェーダー作成
	if(FAILED(D3DX11CompileFromFile(hlsl_name,NULL,NULL,"ps","ps_4_0",0,0,NULL,&pCompiledShader,&pErrors,NULL)))
	{
		MessageBox(0,L"hlsl読み込み失敗",NULL,MB_OK);
		return ;
    }
	SAFE_RELEASE(pErrors);
	if(FAILED(m_pDevice->CreatePixelShader(pCompiledShader->GetBufferPointer(),pCompiledShader->GetBufferSize(),NULL,&m_pPixelShader)))
	{
		SAFE_RELEASE(pCompiledShader);
		MessageBox(0,L"ピクセルシェーダー作成失敗",NULL,MB_OK);
		return ;
	}
	SAFE_RELEASE(pCompiledShader);


	//バーテックスバッファ作成
	DRAW_POLYGON vertices[] =
	{
		{ 1.0f, 1.0f, 0.0f,		1,3},	//頂点1
		{ 1.0f, 0.0f, 0.0f,		1,2},	//頂点2
		{ 0.0f, 1.0f, 0.0f,		0,3},	//頂点3
		{ 0.0f, 0.0f, 0.0f,		0,2},	//頂点4	
	};

	D3D11_BUFFER_DESC bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( DRAW_POLYGON ) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = vertices;
	if( FAILED( m_pDevice->CreateBuffer( &bd, &InitData, &m_pVertexBuffer ) ) )
		return ;

	//インデックスバッファ作成
	unsigned short hIndexData[4] = 
	{
		0,1,2,3,
	};

	D3D11_BUFFER_DESC hBufferDesc;
	hBufferDesc.ByteWidth = sizeof(hIndexData);
	hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	hBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	hBufferDesc.CPUAccessFlags = 0;
	hBufferDesc.MiscFlags = 0;
	hBufferDesc.StructureByteStride = sizeof(unsigned short);

	D3D11_SUBRESOURCE_DATA hSubResourceData;
	hSubResourceData.pSysMem = hIndexData;
	hSubResourceData.SysMemPitch = 0;
	hSubResourceData.SysMemSlicePitch = 0;

	//そのインデックスバッファを作成
	m_pDevice->CreateBuffer(&hBufferDesc, &hSubResourceData, &m_pIndexBuffer);

	//コンスタントバッファー作成 シェーダにデータ受け渡し用
	D3D11_BUFFER_DESC cb;
	cb.BindFlags			=D3D11_BIND_CONSTANT_BUFFER;
	cb.ByteWidth			=sizeof( DRAW_2D_TEX );
	cb.CPUAccessFlags		=D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags			=0;
	cb.StructureByteStride	=0;
	cb.Usage				=D3D11_USAGE_DYNAMIC;
	if( FAILED(m_pDevice->CreateBuffer( &cb,NULL,&m_pConstantBuffer)))
	{
		return ;
	}

	//テクスチャー用サンプラー作成
	D3D11_SAMPLER_DESC SamDesc;
	ZeroMemory(&SamDesc,sizeof(D3D11_SAMPLER_DESC));

	SamDesc.Filter   = D3D11_FILTER_ANISOTROPIC;
    SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.BorderColor[0] = 0.0f;
	SamDesc.BorderColor[1] = 0.0f;
	SamDesc.BorderColor[2] = 0.0f;
	SamDesc.BorderColor[3] = 0.0f;
	SamDesc.MipLODBias = 0.0f;
	SamDesc.MaxAnisotropy = 2;
	SamDesc.MinLOD = 0.0f;
	SamDesc.MaxLOD = D3D11_FLOAT32_MAX;
	SamDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    m_pDevice->CreateSamplerState( &SamDesc, &m_pSampleLinear);
}

//テクスチャロード
void  CDrawTexture::LoadImage(const wchar_t* name,int id,TEX_SIZE hw)
{
	if( 0  > id) 
		return ; 
	
	if(m_img_max < id) 
		return ; 
	
	if(vec_tex_data[id]->GetTexData()!=nullptr)
	{
		vec_tex_data[id].reset(new C_TEX_DATA());
	}
	
	// シェーダーリソースの生成
    D3DX11_IMAGE_LOAD_INFO ImageLoadInfoDesc;
    memset( &ImageLoadInfoDesc, 0, sizeof( D3DX11_IMAGE_LOAD_INFO ) );
    ImageLoadInfoDesc.Width		= hw;
    ImageLoadInfoDesc.Height	= hw;
    ImageLoadInfoDesc.Depth		= D3DX11_DEFAULT;
    ImageLoadInfoDesc.Usage		= D3D11_USAGE_DEFAULT;
    ImageLoadInfoDesc.CpuAccessFlags = 0;
    ImageLoadInfoDesc.MiscFlags	= 0;
    ImageLoadInfoDesc.FirstMipLevel = D3DX11_DEFAULT;
    ImageLoadInfoDesc.MipLevels = 0;
    ImageLoadInfoDesc.Format	= DXGI_FORMAT_FROM_FILE;
    ImageLoadInfoDesc.Filter	= D3DX11_FILTER_POINT;
    ImageLoadInfoDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    ImageLoadInfoDesc.MipFilter = D3DX11_FILTER_POINT;
    ImageLoadInfoDesc.pSrcInfo	= 0;
	ImageLoadInfoDesc.MipLevels = 1;

	//テクスチャー作成
	ID3D11ShaderResourceView* tex;
	D3DX11CreateShaderResourceViewFromFile(m_pDevice,name,&ImageLoadInfoDesc, NULL, &tex, NULL );
	vec_tex_data[id]->SetTexData(tex);
	vec_tex_data[id]->SetTexSize(hw);
	return ;
}

//イメージ情報破棄
void  CDrawTexture::DeleteImage()
{
	//テクスチャメモリのリセット
	for(int i=0; i<m_img_max;i++)
	{
		vec_tex_data[i].reset(new C_TEX_DATA());
	}
}

//描画用オブジェクト破棄
void  CDrawTexture::DeleteDrawTexture()
{
	DeleteImage();
	//ベクター情報破棄
	vec_tex_data.clear();
	vec_tex_data.shrink_to_fit();

	//表示データ破棄
	SAFE_RELEASE(m_pConstantBuffer);
	SAFE_RELEASE(m_pVertexShader);		
	SAFE_RELEASE(m_pPixelShader);	
	SAFE_RELEASE(m_pSampleLinear);
	SAFE_RELEASE(m_pVertexLayout);
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pIndexBuffer);
}