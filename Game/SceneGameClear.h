#pragma once

#include "GameHead.h"
#include "GameL/SceneManager.h"

using namespace GameL;

//ゲームオーバーシーン
class CSceneGameClear : public CScene
{
public:
	void InitScene();	//初期化
	void Scene() {};	//実行中

private:
	void LoadTexture();	//テクスチャ読み込み
	void LoadAudio();	//音楽読み込み
};