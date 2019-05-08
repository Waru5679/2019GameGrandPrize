#include "SceneMain.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "main.h"
#include "GameL/UserData.h"
#include "Csv.h"
#include "GameL/Audio.h"

//������
void CSceneMain::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();

	//���y�ǂݍ���
	LoadAudio();

	//�}�b�v���ǂݍ���
	m_pSideMap=CCsv::LoadCsv("Map/Stage1/Side.csv",SIDE_MAX_X,SIDE_MAX_Y);
	m_pVarticalMap = CCsv::LoadCsv("Map/Stage1/Vartical.csv", VARTICAL_MAX_X, VARTICAL_MAX_Y);

	//�J�E���^������
	m_Count = 0;


	//�X�N���[������
	m_bScroll = SIDE;

	//�w�i�I�u�W�F�N�g1
	m_pBack1 = new CBackGround(0.0f, 0.0f, SIDE);
	Objs::InsertObj(m_pBack1, OBJ_BACK_GROUND, 1);

	//�w�i�I�u�W�F�N�g2
	m_pBack2 = new CBackGround(WINDOW_SIZE_W, 0.0f, SIDE);
	Objs::InsertObj(m_pBack2, OBJ_BACK_GROUND, 1);

	//�}�b�v�I�u�W�F�N�g
	CMap* pMap = new CMap(m_pSideMap,m_pVarticalMap);
	Objs::InsertObj(pMap, OBJ_MAP, 100);

	//�L�����N�^�[�I�u�W�F�N�g
	CObjMainChara* pChara = new CObjMainChara();
	Objs::InsertObj(pChara, OBJ_CHARA, 10);

	//�X�R�A�\���I�u�W�F�N�g
	CScore* pScore = new CScore();
	Objs::InsertObj(pScore, OBJ_SCORE, 10);

	//Debug�p�@�X�N���[���`�F���W
	//CScrollChange* pScroll = new CScrollChange(0, 0,VARTICAL);
	//Objs::InsertObj(pScroll, OBJ_SCROLL_CHANGE, 10);

	//�{�����[������
	Audio::Volume(-0.8f, 0);
	
	//�X�^�[�g
	Audio::Start(0);

}

//���s��
void CSceneMain::Scene()
{
	
}


//�X�N���[���؂�ւ�
void CSceneMain::ScrollChange()
{
	//�X�N���[�������̐؂�ւ�
	m_bScroll = !(m_bScroll);

	//�w�i�̈ʒu�ƃX�N���[�������̕ύX

	//�����c�ɕύX
	if (m_bScroll == VARTICAL)
	{
		m_pBack1->SetScroll(0.0f, 0.0f, VARTICAL);
		m_pBack2->SetScroll(0.0f, WINDOW_SIZE_H, VARTICAL);
	}
	//�c�����ɕύX
	else
	{
		m_pBack1->SetScroll(0.0f, 0.0f, SIDE);
		m_pBack2->SetScroll(WINDOW_SIZE_W, 0.0f, SIDE);
	}
}

//�e�N�X�`���ǂݍ���
void CSceneMain::LoadTexture()
{
	//�w�i
	Draw::LoadImageW(L"Texture/BackGround.png", OBJ_BACK_GROUND, TEX_SIZE_512);

	//��
	Draw::LoadImageW(L"Texture/BlackHole.png", OBJ_BLACK_HOLE, TEX_SIZE_128);

	//��l��
	Draw::LoadImageW(L"Texture/MainCharacter.png",OBJ_CHARA, TEX_SIZE_128);
	//�G
	Draw::LoadImageW(L"Texture/Enemy.png", OBJ_ENEMY, TEX_SIZE_256);

	//�G�e��
	Draw::LoadImageW(L"Texture/EnemyBullet.png", OBJ_ENEMY_BULLET, TEX_SIZE_128);

	//��l���e��
	Draw::LoadImageW(L"Texture/PlayerBullet.png", OBJ_CHARA_BULLET, TEX_SIZE_128);

	//��
	Draw::LoadImageW(L"Texture/Planet.png", OBJ_STAR, TEX_SIZE_128);

	//���W�A�C�e��
	Draw::LoadImageW(L"Texture/Collection.png", OBJ_ITEM_BIG, TEX_SIZE_128);
	Draw::LoadImageW(L"Texture/Collection.png", OBJ_ITEM_SMALL, TEX_SIZE_128);

	//�X�N���[���̃`�F���W
	Draw::LoadImageW(L"Texture/ScrollChange.png", OBJ_SCROLL_CHANGE, TEX_SIZE_128);

	//��
	Draw::LoadImageW(L"Texture/Plane.png", OBJ_PLANE, TEX_SIZE_128);

	//�N���A�A�C�e���ǂݍ���
	Draw::LoadImageW(L"Texture/Clear.png", OBJ_GAME_CLEAR, TEX_SIZE_128);

	//�㉺�ړ�����G�ǂݍ���
	Draw::LoadImageW(L"Texture/Enemy2.png", OBJ_ENEMY_UPDOWN, TEX_SIZE_256);

}

//���y�ǂݍ���
void CSceneMain::LoadAudio()
{
	//BGMtest
	Audio::LoadAudio(0, L"Audio/Test2.wav", BACK_MUSIC);
}