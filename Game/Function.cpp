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

