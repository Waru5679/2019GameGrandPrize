#include "SceneTitle.h"
#include "Title.h"
#include "GameL/DrawTexture.h"
#include "GameL/Audio.h"

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

	//ボリューム調整
	Audio::Volume(-0.2f, 0);

	//音楽再生
	Audio::Start(0);
}

//テクスチャ読み込み
void CSceneTitle::LoadTexture()
{
	Draw::LoadImageW(L"Texture/Title.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//音楽読み込み
void CSceneTitle::LoadAudio()
{
	Audio::LoadAudio(0, L"Audio/Title.wav", BACK_MUSIC);
}
