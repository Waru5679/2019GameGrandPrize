#include "Map.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"

//�R���X�g���N�^
CMap::CMap(int* pMap)
{
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_Map, pMap, sizeof(int)*(MAX_Y * MAX_X));
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
	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			switch (m_Map[y][x])
			{
				//�n��
				case MAP_PLANE:
				{
					CPlane* pPlane = new CPlane(x, y);
					Objs::InsertObj(pPlane, OBJ_PLANE, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//�u���b�N�z�[��
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//�G
				case MAP_ENEMY:
				{
					CEnemy* pEnemy = new CEnemy(x, y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//��
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x, y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;

					break;
				}
				//�A�C�e��(��)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;

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
					m_Map[y][x] = MAP_NONE;

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
					m_Map[y][x] = MAP_NONE;
					break;
				}
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y);
					Objs::InsertObj(pClear, OBJ_GAME_CLEAR, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;
					break;
				}

			}

		}
	}
}

//����(�c)
void CMap::CreateVertical()
{
	for (int y = MAX_Y; y > 0; y--)
	{
		for (int x = MAX_X; x > 0; x--)
		{
			switch (m_Map[y][x])
			{
			//�n��
			case MAP_PLANE:
			{
				CPlane* pPlane = new CPlane(x, y);
				Objs::InsertObj(pPlane, OBJ_PLANE, 10);

				//�������I���΋󔒂�
				m_Map[y][x] = MAP_NONE;
				break;
			}
			//�u���b�N�z�[��
			case MAP_BLACK_HOLE:
			{
				CBlackHole* pBlackHole = new CBlackHole(x, y);
				Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

				//�������I���΋󔒂�
				m_Map[y][x] = MAP_NONE;
				break;
			}
			//�G
			case MAP_ENEMY:
			{
				CEnemy* pEnemy = new CEnemy(x, y);
				Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

				//�������I���΋󔒂�
				m_Map[y][x] = MAP_NONE;
				break;
			}
			//��
			case MAP_STAR:
			{
				CStar* pStar = new CStar(x, y);
				Objs::InsertObj(pStar, OBJ_STAR, 10);

				//�������I���΋󔒂�
				m_Map[y][x] = MAP_NONE;

				break;
			}
			//�A�C�e��(��)
			case MAP_ITEM_BIG:
			{
				CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
				Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

				//�������I���΋󔒂�
				m_Map[y][x] = MAP_NONE;

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
				m_Map[y][x] = MAP_NONE;

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
				m_Map[y][x] = MAP_NONE;
				break;
			}
			}

		}
	}
}