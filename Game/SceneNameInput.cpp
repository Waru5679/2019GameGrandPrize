#include "SceneNameInput.h"
#include "NameInput.h"
#include "GameHead.h"
#include "GameL/UserData.h"

//������
void CSceneNameInput::InitScene()
{
	//���O����Obj�쐬
	CNameInput* pNameInpit = new CNameInput();
	Objs::InsertObj(pNameInpit, OBJ_NAME_INPUT, 0);
}