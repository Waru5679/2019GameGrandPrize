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