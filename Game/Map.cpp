#include "Map.h"
#include "Function.h"
#include "main.h"


//�R���X�g���N�^
CMap::CMap(int map[MAX_Y][MAX_X])
{
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_Map, map, sizeof(int)*(MAX_Y * MAX_X));
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
				//��
				case MAP_HOLE:
				{
					CHole* pHole = new CHole(y, x);
					Objs::InsertObj(pHole, OBJ_HOLE, 10);

					//�������I���΋󔒂�
					m_Map[y][x] = MAP_NONE;
					break;

				}
			}
		}
	}
}