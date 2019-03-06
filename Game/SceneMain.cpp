//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"player.png", 0, TEX_SIZE_1024);

	//主人公オブジェクト作成
	CObjMainChara* obj_chara = new CObjMainChara();
	Objs::InsertObj(obj_chara, OBJ_CHARA, 10);
}

//実行中メソッド
void CSceneMain::Scene()
{

}