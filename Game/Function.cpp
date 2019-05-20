#include "Function.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"

//Rect�ɒl���Z�b�g����֐�
//�����@1�`4�F�㉺���E���ꂼ��ɃZ�b�g�������l
//�����@5	�F�l����ꂽ���ꏊ
void RectSet(RECT_F* rect,float top, float left, float Size_x, float Size_y)
{
	rect->m_top		= top;
	rect->m_left	= left;
	rect->m_right	= rect->m_left + Size_x;
	rect->m_bottom	= rect->m_top + Size_y;
}


//�F���Z�b�g����֐�
void ColorSet(float r, float g, float b, float a, float color[4])
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
}

//��ʓ����̃`�F�b�N
bool WindowInCheck(Vector vPos,Vector vSize)
{
	if (vPos.x + vSize.x < 0.0f)
		return false;
	if (vPos.y + vSize.y < 0.0f)
		return false;
	if (vPos.y > WINDOW_SIZE_H)
		return false;
	if (vPos.x > WINDOW_SIZE_W)
		return false;

	return true;
}

//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�B
//����1  float w	�G��
//����2	 float h	�F����
//�߂�l float		�F�p�x(0���`�@360��)
//���e
float GetAtan2Angle(float w, float h)
{
	//atan2�Ŋp�x�����߂�
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180���`-0�� 180���`360���ɕϊ�
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;
}


//---UnitVec�֐�
//����1   float* vx  :�x�N�g����X�����̃|�C���^
//����2   float* vy  :�x�N�g����Y�����̃|�C���^
//�߂�l bool		 :ture=�v�Z�����@false=�v�Z���s
bool UnitVec(float* vx, float* vy)
{
	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}

	//�v�Z����
	return true;
}

//�����L���O�\�[�g���\�b�h
//����1 int[11] :�����L���O�p�z��
//���l���������Ńo�u���\�[�g����
int RankingSort(int rank[11],char name[][6])
{
	//�l�����p�ϐ�
	int change;
	//���ʕۑ��p
	int ranking;
	//���O�����p�z��
	char RankingName[6];

	//�o�u���\�[�g
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 11; j++)
		{
			if (rank[i] < rank[j])
			{
				//�l�̌���
				change = rank[i];
				rank[i] = rank[j];
				rank[j] = change;

				//���O�̌���
				strcpy_s(RankingName, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], RankingName);
			}
		}
	}

	//�����̖͂��O����T���ď��ʂ𒲂ׂ�
	for (int i = 0; i < 11; i++)
	{
		//���O�������͂Ȃ�
		if (strcmp(name[i], NO_NAME) == 0)
		{
			//���ʂ̕ۑ�
			ranking = i + 1;
			break;
		}
	}
	return ranking;
}