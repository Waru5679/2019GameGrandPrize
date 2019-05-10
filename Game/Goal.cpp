#include "Goal.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"
#include "GameL/UserData.h"

//�R���X�g���N�^
CGoal::CGoal(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CGoal::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�����蔻��
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, GOAL_SIZE, GOAL_SIZE, ELEMENT_STAGE, OBJ_GOAL, 1);
}

//�X�V
void CGoal::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//�X�N���[�������̎����֓���
	if (m_bScroll == SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//�c�Ȃ牺�֓���
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}

	//��l���Ƃ̓����蔻��
	CHitBox* hit_b = Hits::GetHitBox(this);
	//��l���Ɠ�����΃Q�[���N���A��
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�Q�[���N���A��
		Scene::SetScene(new CSceneGameClear());
	}
}

//�`��
void CGoal::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, GOAL_SIZE, GOAL_SIZE);

	//�`��
	Draw::Draw(OBJ_GOAL, &src, &dst, m_fColor, 0.0f);

}