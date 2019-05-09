#include "SceneGameOver.h"
#include "GameOver.h"
#include "GameL/DrawTexture.h"

//初期化
void CSceneGameOver::InitScene()
{
	//テクスチャ読み込み
	LoadTexture();

	//音楽読み込み
	LoadAudio();

	//ゲームオーバーObj作成
	CGameOver* pGameOver = new CGameOver();
	Objs::InsertObj(pGameOver, OBJ_GAME_OVER, 0);

}

//テクスチャ読み込み
void CSceneGameOver::LoadTexture()
{
	Draw::LoadImageW(L"Texture/GameOver.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//音楽読み込み
void CSceneGameOver::LoadAudio()
{

}
