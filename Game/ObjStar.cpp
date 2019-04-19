#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjStar.h"
#include "GameHead.h"
#include "Function.h"


//�R���X�g���N�^
CStar::CStar(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CStar::Init()
{
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x , m_vPos.y, STAR_SIZE / 2.0f, STAR_SIZE / 2.0f, ELEMENT_STAR, OBJ_STAR, 1);
}

//�X�V
void CStar::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//�X�N���[�������̎����֓���
	if (m_bScroll = SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//�c�Ȃ牺�֓���
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);

	//�����蔻��̈ʒu�𐯂̒��Ɏ��߂�悤�Ɉړ�
	hit_b->SetPos( m_vPos.x + (STAR_SIZE / 4.0f), m_vPos.y + (STAR_SIZE / 4.0f));

	//�L�����N�^�[�ɓ���������΃Q�[���I�[�o�[��
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//����
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�Q�[���I�[�o�[��
		Scene::SetScene(new CSceneGameOver());
	}
}

//�`��
void CStar::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, STAR_SIZE, STAR_SIZE);

	//�`��
	Draw::Draw(OBJ_STAR, &src, &dst, m_fColor, 0.0f);
}