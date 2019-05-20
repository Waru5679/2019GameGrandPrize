#include "Map.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"
#include "GameL/UserData.h"

//�R���X�g���N�^
CMap::CMap(int* pSideMap,int* pVarticalMap)
{
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_SideMap, pSideMap, sizeof(int)*(SIDE_MAX_Y * SIDE_MAX_X));
	memcpy(m_VarticalMap,pVarticalMap,sizeof(int)*(VARTICAL_MAX_Y*VARTICAL_MAX_X));
}

//������
void CMap::Init()
{
	//�`��F�ݒ�
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�}�b�v�z��T���p�ϐ�������
	m_iMapItem[MAX_ITEM];
	m_iMapLoop = 0;

	//�X�N���[���ړ�
	m_fScroll = SCROLL_SPEED;

	//�����t���O���I���ɂ���
	m_bFirstTimeSide = true;
	m_bFirstTimeVertical = true;
	//�X�N���[���`�F���W���I�t�ɂ���
	m_bScrollChangeIs = false;

	//�}�b�v�̓ǂݍ��ݗ�
	((UserData*)Save::GetData())->m_iMap_x = 0;
	((UserData*)Save::GetData())->m_iMap_y = 0;

	//���}�b�v�쐻
	CreateSideFirst();
}

//�X�V
void CMap::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	if (m_bScroll == SIDE)
	{
		m_fMovePos_x += SCROLL_SPEED;
	}
	else
	{
		m_fMovePos_y -= SCROLL_SPEED;
	}
}

//�`��
void CMap::Draw()
{
	
}

//��������(��)
void CMap::CreateSideFirst()
{
	for (int x =0; x < SIDE_MAX_X; x++)
	{
		for (int y = 0; y < SIDE_MAX_Y; y++)
		{
			switch (m_SideMap[y][x])
			{
				//�n��
				case MAP_PLANE:
				{
					CPlane* pPlane = new CPlane(x, y);
					Objs::InsertObj(pPlane, OBJ_PLANE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//�u���b�N�z�[��
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
 				}
				//�G
				case MAP_ENEMY:
 				{
					CEnemy* pEnemy = new CEnemy(x, y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//��
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x, y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//�X�N���[���`�F���W
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, y, SIDE);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					//�����ꏊ���L��
					((UserData*)Save::GetData())->m_iMap_x = x;
					m_bScrollChangeIs = true;
					break;
						
				}
				//�S�[��
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y);
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}

			}

		}
		if (m_bScrollChangeIs == true)
		{
			//���񐶐����I�t�ɂ���
			m_bFirstTimeSide = false;
			break;
		}
		
	}
	
}

void CMap::CreateSideSecond()
{
	m_bScrollChangeIs = false;

	for (int x = ((UserData*)Save::GetData())->m_iMap_x; x <= SIDE_MAX_X; x++)
	{
		for (int y = 0; y < SIDE_MAX_Y; y++)
		{
			//�X�N���[���̈ʒu�����p���l�i��ʍ��[�Ɉړ�������j
			m_fMoveAddPos_x = ((UserData*)Save::GetData())->m_iMap_x;

			switch (m_SideMap[y][x])
			{
				//�n��
				case MAP_PLANE:
				{
					CPlane* pPlane = new CPlane(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pPlane, OBJ_PLANE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//�u���b�N�z�[��
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//�G
				case MAP_ENEMY:
				{
					CEnemy* pEnemy = new CEnemy(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//��
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x - m_fMoveAddPos_x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x - m_fMoveAddPos_x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//�X�N���[���`�F���W
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x - m_fMoveAddPos_x, y, SIDE);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;

					//�����ꏊ���L��
					((UserData*)Save::GetData())->m_iMap_x = x;
					m_bScrollChangeIs = true;
					break;

				}
				//�S�[��
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}

			}

		}
		if (m_bScrollChangeIs == true)
		{
			//���񐶐����I�t�ɂ���
			m_bFirstTimeSide = false;
			break;
		}

	}
}

//��������(�c)
void CMap::CreateVerticalFirst()
{
	m_bScrollChangeIs = false;

	for (int y = VARTICAL_MAX_Y; y >= 0; y--)
	{
		for (int x = 0; x< VARTICAL_MAX_X; x++)
		{
			switch (m_VarticalMap[y][x])
			{
				//�u���b�N�z�[��
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//�G
				case MAP_ENEMY:
				{
					CEnemy* pEnemy = new CEnemy(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//��
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y - VARTICAL_MAX_Y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y - VARTICAL_MAX_Y, m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//�X�N���[���`�F���W
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, y - VARTICAL_MAX_Y,VARTICAL);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					((UserData*)Save::GetData())->m_iMap_y = y;
					m_bScrollChangeIs = true;
					break;
				}
				//�㉺�ړ��G
				case MAP_ENEMY_UPDOWN:
				{
					CEnemyUpDown* pEnemyUpDown = new CEnemyUpDown(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pEnemyUpDown, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//�S�[��
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
			}

		}

		if (m_bScrollChangeIs == true)
		{
			//���񐶐����I�t�ɂ���
			m_bFirstTimeSide = false;
			break;
		}
	}
}

//�c�����i2��ڈȍ~�j
void CMap::CreateVerticalSecond()
{
	m_bScrollChangeIs = false;

	for (int y = ((UserData*)Save::GetData())->m_iMap_y - 1; y >= 0; y--)
	{
		for (int x = 0; x < VARTICAL_MAX_X; x++)
		{

			m_fMoveAddPos_y = ((UserData*)Save::GetData())->m_iMap_y;

			switch (m_VarticalMap[y][x])
			{
				//�u���b�N�z�[��
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y ));
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//�G
				case MAP_ENEMY: 
				{
					CEnemy* pEnemy = new CEnemy(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//��
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x,((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y), m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y), m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					//�}�b�v���̃A�C�e���̎�ގ���
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//�X�N���[���`�F���W
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y), VARTICAL);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;

					((UserData*)Save::GetData())->m_iMap_y = y;
					m_bScrollChangeIs = true;
					break;
				}
				//�㉺�ړ��G
				case MAP_ENEMY_UPDOWN:
				{
					CEnemyUpDown* pEnemyUpDown = new CEnemyUpDown(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pEnemyUpDown, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//�S�[��
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
			}

		}
		if (m_bScrollChangeIs == true)
		{
			//���񐶐����I�t�ɂ���
			m_bFirstTimeSide = false;
			break;
		}
	}
}