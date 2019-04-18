#include "SceneTitle.h"
#include "Title.h"
//初期化
void CSceneTitle::InitScene()
{
	//テクスチャ読み込み
	LoadTexture();
	
	//音楽読み込み
	LoadAudio();

	//タイトルObj作成
	CTitle* pTitle = new CTitle();
	Objs::InsertObj(pTitle, OBJ_TITLE, 0);

}

//テクスチャ読み込み
void CSceneTitle::LoadTexture()
{

}

//音楽読み込み
void CSceneTitle::LoadAudio()
{

}
