#include "ObjStar.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"

//�R���X�g���N�^
CStar::CStar(int x, int y)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
}

//������
void CStar::Init()
{
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//�X�V
void CStar::Action()
{

}

//�`��
void CStar::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_fPos_y, m_fPos_x, STAR_SIZE, STAR_SIZE);

	//�`��
	Draw::Draw(OBJ_STAR, &src, &dst, m_fColor, 0.0f);
}