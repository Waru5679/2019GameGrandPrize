#include "SceneNameInput.h"
#include "NameInput.h"
#include "GameHead.h"
#include "GameL/UserData.h"

//初期化
void CSceneNameInput::InitScene()
{
	//名前入力Obj作成
	CNameInput* pNameInpit = new CNameInput();
	Objs::InsertObj(pNameInpit, OBJ_NAME_INPUT, 0);
}