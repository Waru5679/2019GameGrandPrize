#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjStar.h"
#include "GameHead.h"
#include "Function.h"


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
	
	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_fPos_x , m_fPos_y, STAR_SIZE / 2.0f, STAR_SIZE / 2.0f, ELEMENT_STAR, OBJ_STAR, 1);
}

//�X�V
void CStar::Action()
{
	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	//�����蔻��̈ʒu�𐯂̒��Ɏ��߂�悤�Ɉړ�
	hit_b->SetPos(m_fPos_x + (STAR_SIZE / 4.0f), m_fPos_y + (STAR_SIZE / 4.0f));

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