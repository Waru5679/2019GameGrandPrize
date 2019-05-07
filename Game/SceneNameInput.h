#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//名前入力シーン
class CSceneNameInput :public CScene
{
public:
	void InitScene();	//初期化
	void Scene();		//実行中
};