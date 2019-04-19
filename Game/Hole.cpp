#include "Hole.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

//�R���X�g���N�^
CHole::CHole(int y, int x)
{
	m_vPos.x = 400.0f;// (float)y * OBJ_SIZE;
	m_vPos.y = 400.0f;//(float)x * OBJ_SIZE;

}

//������
void CHole::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//HitBox�Z�b�g
	Hits::SetHitBox(this, m_vPos.x- HOLE_SIZE, m_vPos.y-HOLE_SIZE, HOLE_SIZE*3.0f, HOLE_SIZE*3.0f, ELEMENT_HOLE, OBJ_HOLE, 0);
}

//�X�V
void CHole::Action()
{
	//�V�[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//�R�����g�A�E�g����ƃX�N���[���̌�������ō������֓���-----
	////�X�N���[�������̎����֓���
	//if (m_bScroll == SIDE)
	//{
	//	m_vPos.x -= SCROLL_SPEED;
	//}
	////�c�̎����֓���
	//else
	//{
	//	m_vPos.y += SCROLL_SPEED;
	//}
	//------------------------------------------------------------

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x - HOLE_SIZE, m_vPos.y -HOLE_SIZE);

	//�v���C���[���������Ă���Ƃ�
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//�L�����̈ʒu�擾
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));
		Vector vCharaPos = pChara->GetPos();

		//�L�����N�^�[���猩�����̕���(���K��)
		Vector vHoleDir=CVector::Sub(m_vPos, vCharaPos);
		vHoleDir = CVector::Normalize(vHoleDir);

		//�L�����Ɉړ��x�N�g���ǉ�
		pChara->SetMove(vHoleDir);
	}

	//������ʊO�֏o��ƍ폜
	//
	if (m_vPos.x + (HOLE_SIZE * 2.0f) < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//��ʉ��[
	if (m_vPos.y - HOLE_SIZE > WINDOW_SIZE_H)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�`��
void CHole::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, HOLE_SIZE, HOLE_SIZE);
	
	//�`��
	Draw::Draw(OBJ_HOLE, &src, &dst, m_fColor, 0.0f);

}