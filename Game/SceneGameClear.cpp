#include "SceneGameClear.h"
#include "GameClear.h"
#include "GameL/DrawTexture.h"
#include "GameL/Audio.h"

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

	//ボリューム調整
	Audio::Volume(-0.2f, 0);

	//音楽再生
	Audio::Start(0);
}

//テクスチャ読み込み
void CSceneGameClear::LoadTexture()
{
	Draw::LoadImageW(L"Texture/GameClear.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//音楽読み込み
void CSceneGameClear::LoadAudio()
{
	Audio::LoadAudio(0, L"Audio/GameClear.wav", BACK_MUSIC);
}