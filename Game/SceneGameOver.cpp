#include "SceneGameOver.h"
#include "GameOver.h"
#include "GameL/DrawTexture.h"

//������
void CSceneGameOver::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();

	//���y�ǂݍ���
	LoadAudio();

	//�Q�[���I�[�o�[Obj�쐬
	CGameOver* pGameOver = new CGameOver();
	Objs::InsertObj(pGameOver, OBJ_GAME_OVER, 0);

}

//�e�N�X�`���ǂݍ���
void CSceneGameOver::LoadTexture()
{
	Draw::LoadImageW(L"Texture/GameOver.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//���y�ǂݍ���
void CSceneGameOver::LoadAudio()
{

}
