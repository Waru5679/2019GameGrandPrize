#include "SceneGameOver.h"
#include "GameOver.h"

//������
void CSceneGameOver::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();

	//���y�ǂݍ���
	LoadAudio();

	//�^�C�g��Obj�쐬
	CGameOver* pGameOver = new CGameOver();
	Objs::InsertObj(pGameOver, OBJ_GAME_OVER, 0);

}

//�e�N�X�`���ǂݍ���
void CSceneGameOver::LoadTexture()
{

}

//���y�ǂݍ���
void CSceneGameOver::LoadAudio()
{

}
