#include "Hole.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"

//�R���X�g���N�^
CHole::CHole(int y, int x)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;

}

//������
void CHole::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

}

//�X�V
void CHole::Action()
{

}

//�`��
void CHole::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//�`��ʒu
	RectSet(&dst, m_fPos_y, m_fPos_x, HOLE_SIZE, HOLE_SIZE);
	
	//�`��
	Draw::Draw(OBJ_HOLE, &src, &dst, m_fColor, 0.0f);

}