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
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--

//�x�N�g���\����
struct Vector
{
	float x;
	float y;
};

//�X�N���[��
#define SIDE true		//��
#define VERTICAL false	//�c

//�}�b�v
#define MAX_X 10
#define MAX_Y 10



//�}�b�v���l
enum MAP_NUM
{
	MAP_NONE,	//�����Ȃ�
	MAP_HOLE,	//��
	MAP_ENEMY,	//�G
};

//�I�u�W�F�N�g�T�C�Y
#define OBJ_SIZE	32.0f
#define HOLE_SIZE	32.0f
#define ENEMY_SIZE	32.0f

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
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneMain 
//-----------------------------------------------