#include "SceneGameClear.h"
#include "GameClear.h"
#include "GameL/DrawTexture.h"

//������
void CSceneGameClear::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();

	//���y�ǂݍ���
	LoadAudio();

	//�Q�[���N���AObj�쐬
	CGameClear* pGameClear = new CGameClear();
	Objs::InsertObj(pGameClear, OBJ_GAME_CLEAR, 0);
}

//�e�N�X�`���ǂݍ���
void CSceneGameClear::LoadTexture()
{
	Draw::LoadImageW(L"Texture/GameClear.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//���y�ǂݍ���
void CSceneGameClear::LoadAudio()
{

}