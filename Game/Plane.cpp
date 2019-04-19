#include "Plane.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"

CPlane::CPlane(int x, int y)
{
	m_vPos.x = 100.0f;//(float)x * OBJ_SIZE;
	m_vPos.y = 500.0f;//(float)y * OBJ_SIZE;
}

//������
void CPlane::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�����蔻��Z�b�g
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, PLANE_WIDTH , PLANE_HEIGHT, ELEMENT_PLANE, OBJ_PLANE, 1);

}

//�X�V
void CPlane::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//�X�N���[�������̎����֓���
	if (m_bScroll == SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	 //������ʊO�֏o��ƍ폜
	//��ʉ��[
	if (m_vPos.x + PLANE_WIDTH < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�`��
void CPlane::Draw()
{

	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, OBJ_SIZE, OBJ_SIZE);

	//�`��
	Draw::Draw(OBJ_PLANE, &src, &dst, m_fColor, 0.0f);
}