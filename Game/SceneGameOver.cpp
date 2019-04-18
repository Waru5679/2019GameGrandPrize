#include "SceneGameOver.h"
#include "GameOver.h"

//初期化
void CSceneGameOver::InitScene()
{
	//テクスチャ読み込み
	LoadTexture();

	//音楽読み込み
	LoadAudio();

	//タイトルObj作成
	CGameOver* pGameOver = new CGameOver();
	Objs::InsertObj(pGameOver, OBJ_GAME_OVER, 0);

}

//テクスチャ読み込み
void CSceneGameOver::LoadTexture()
{

}

//音楽読み込み
void CSceneGameOver::LoadAudio()
{

}
