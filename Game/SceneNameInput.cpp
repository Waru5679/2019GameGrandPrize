#include "SceneNameInput.h"
#include "NameInput.h"
#include "GameHead.h"
#include "GameL/UserData.h"

//‰Šú‰»
void CSceneNameInput::InitScene()
{
	//–¼‘O“ü—ÍObjì¬
	CNameInput* pNameInpit = new CNameInput();
	Objs::InsertObj(pNameInpit, OBJ_NAME_INPUT, 0);
}