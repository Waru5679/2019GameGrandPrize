#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//タイトルシーン
class CSceneTitle :public CScene
{
public:
	void InitScene();	//初期化
	void Scene() {};	//実行中

private:
	void LoadTexture();	//テクスチャ読み込み
	void LoadAudio();	//音楽読み込み
};