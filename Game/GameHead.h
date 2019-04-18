#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	OBJ_BACK_GROUND,//�w�i
	OBJ_MAP,		//�}�b�v
	OBJ_HOLE,		//��
	OBJ_CHARA,		//�L�����N�^
	OBJ_ENEMY,		//�G
	OBJ_ENEMY_BULLET,//�G�̒e
	OBJ_CHARA_BULLET,//��l���̒e
	OBJ_STAR,		 //���I�u�W�F�N�g
	OBJ_ITEM_BIG,	 //���W�A�C�e���I�u�W�F�N�g(��)
	OBJ_ITEM_SMALL,	 //���W�A�C�e���I�u�W�F�N�g(��)
	OBJ_SCORE,		 //�X�R�A
	OBJ_SCROLL_CHANGE,//�X�N���[���̐؂�ς��I�u�W�F�N�g
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM_BIG,
	ELEMENT_ITEM_SMALL,
	ELEMENT_CHARA_BULLET,
	ELEMENT_ENEMY_BULLET,
	ELEMENT_STAR,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int m_iScore;	//�X�R�A
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--


//�X�N���[��
#define SIDE true		//��
#define VERTICAL false	//�c

//�}�b�v
#define MAX_X 10
#define MAX_Y 10

//�ő�A�C�e����
#define MAX_ITEM 4

//�}�b�v���l
enum MAP_NUM
{
	MAP_NONE,		//�����Ȃ�
	MAP_HOLE,		//��
	MAP_ENEMY,		//�G
	MAP_STAR,		//��
	MAP_ITEM_BIG,	//���W�A�C�e��(��)
	MAP_ITEM_SMALL,	//���W�A�C�e��(��)
	MAP_SCROLL_CHANGE,//�X�N���[���̐؂�ւ�
};

//�A�C�e���p���l
enum ITEM_NUM
{
	ITEM_BIG,		//�A�C�e��(��)
	ITEM_SMALL,		//�A�C�e��(��)
};

//�I�u�W�F�N�g�T�C�Y
#define OBJ_SIZE		32.0f
#define HOLE_SIZE		32.0f
#define ENEMY_SIZE		64.0f
#define BULLET_SIZE		32.0f
#define CHARA_SIZE		64.0f
#define STAR_SIZE		64.0f
#define ITEM_BIG_SIZE	64.0f
#define ITEM_SMALL_SIZE	32.0f
#define SCROLL_CHANGE_SIZE 64.0f

//�X�R�A
#define SCORE_BIG		1000;
#define SCORE_SMALL		 500;
#define SCORE_BONUS		 250;

//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "BackGround.h"
#include "Map.h"
#include "Hole.h"
#include "SceneMain.h"
#include "ObjMainChara.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "CharaBullet.h"
#include "ObjStar.h"
#include "ObjCollectionItemBig.h"
#include "ObjCollectionItemSmall.h"
#include "ScrollChange.h"
#include "Score.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneMain 
//-----------------------------------------------