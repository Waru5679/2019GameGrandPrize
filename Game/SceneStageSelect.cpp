#include "SceneStageSelect.h"
#include "StageSelect.h"

//������
void CSceneStageSelect::InitScene()
{
	//�X�e�[�WObj�쐬
	CStageSelect* pStageSelect = new CStageSelect();
	Objs::InsertObj(pStageSelect, OBJ_STAGE_SELECT, 0);
}