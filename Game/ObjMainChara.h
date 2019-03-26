#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "Vector.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjMainChara : public CObj
{
public:
	CObjMainChara() {};
	~CObjMainChara() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	Vector GetPos() { return m_vPos; }
private:
	Vector m_vPos;//位置
	//float m_fpx;	//位置
	//float m_fpy;
	float m_fvx;	//移動ベクトル
	float m_fvy;
	float m_fposture;	//向き

	//描画色
	float m_fColor[4];
};