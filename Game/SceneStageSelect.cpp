#include "SceneStageSelect.h"
#include "StageSelect.h"

//初期化
void CSceneStageSelect::InitScene()
{
	//ステージObj作成
	CStageSelect* pStageSelect = new CStageSelect();
	Objs::InsertObj(pStageSelect, OBJ_STAGE_SELECT, 0);
}