#include "Map.h"
#include "Function.h"
#include "main.h"


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
}

//�X�V
void CMap::Action()
{
	//�I�u�W�F�N�g����
	Create();
}

//�`��
void CMap::Draw()
{
	
}

//����
void CMap::Create()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
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
				//��
				case MAP_HOLE:
				{
					CHole* pHole = new CHole(x, y);
					Objs::InsertObj(pHole, OBJ_HOLE, 10);

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
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_BIG;
					break;
				}
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_SMALL;
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