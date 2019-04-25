#include "Map.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"

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

}

//�X�V
void CMap::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//�c
	if (m_bScroll == SIDE)
	{
		//�I�u�W�F�N�g����(��)
		CreateSide();
	}
	else
	{
		//�I�u�W�F�N�g����(�c)
		CreateVertical();
	}
}

//�`��
void CMap::Draw()
{
	
}

//����(��)
void CMap::CreateSide()
{
	for (int x = 0; x < SIDE_MAX_X; x++)
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
					CScrollChange* pScrollChange = new  CScrollChange(x, y);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//�S�[��
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y);
					Objs::InsertObj(pClear, OBJ_GAME_CLEAR, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//�㉺�ړ��G
				case MAP_ENEMY_UPDOWN:
				{
					CEnemyUpDown* pEnemyUpDown = new CEnemyUpDown(x, y);
					Objs::InsertObj(pEnemyUpDown, OBJ_ENEMY_UPDOWN, 10);

					//�������I���΋󔒂�
					m_SideMap[y][x] = MAP_NONE;
					break;
				}

			}

		}
	}
}

//����(�c)
void CMap::CreateVertical()
{
	for (int y = VARTICAL_MAX_Y-1; y >= 0; y--)
	{
		for (int x = 0; x < VARTICAL_MAX_X; x++)
		{
			switch (m_VarticalMap[y][x])
			{
			//�n��
			case MAP_PLANE:
			{
				CPlane* pPlane = new CPlane(x, y);
				Objs::InsertObj(pPlane, OBJ_PLANE, 10);

				//�������I���΋󔒂�
				m_VarticalMap[y][x] = MAP_NONE;
				break;
			}
			//�u���b�N�z�[��
			case MAP_BLACK_HOLE:
			{
				CBlackHole* pBlackHole = new CBlackHole(x, y);
				Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

				//�������I���΋󔒂�
				m_VarticalMap[y][x] = MAP_NONE;
				break;
			}
			//�G
			case MAP_ENEMY:
			{
				CEnemy* pEnemy = new CEnemy(x, y);
				Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

				//�������I���΋󔒂�
				m_VarticalMap[y][x] = MAP_NONE;
				break;
			}
			//��
			case MAP_STAR:
			{
				CStar* pStar = new CStar(x, y);
				Objs::InsertObj(pStar, OBJ_STAR, 10);

				//�������I���΋󔒂�
				m_VarticalMap[y][x] = MAP_NONE;

				break;
			}
			//�A�C�e��(��)
			case MAP_ITEM_BIG:
			{
				CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
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
				CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y, m_iMapLoop);
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
				CScrollChange* pScrollChange = new  CScrollChange(x, y);
				Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

				//�������I���΋󔒂�
				m_VarticalMap[y][x] = MAP_NONE;
				break;
			}
			}

		}
	}
}