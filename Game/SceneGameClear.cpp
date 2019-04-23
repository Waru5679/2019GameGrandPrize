#include "SceneGameClear.h"
#include "GameClear.h"

//初期化
void CSceneGameClear::InitScene()
{
	//テクスチャ読み込み
	LoadTexture();

	//音楽読み込み
	LoadAudio();

	//ゲームクリアObj作成
	CGameClear* pGameClear = new CGameClear();
	Objs::InsertObj(pGameClear, OBJ_GAME_CLEAR, 0);
}

//テクスチャ読み込み
void CSceneGameClear::LoadTexture()
{

}

//音楽読み込み
void CSceneGameClear::LoadAudio()
{

}