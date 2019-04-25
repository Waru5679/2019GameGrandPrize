#include "BlackHole.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

//�R���X�g���N�^
CBlackHole::CBlackHole(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CBlackHole::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//�z����
	m_fSuctionPower=1.2f;

	//���S����̈ʒu�@(�I�u�W�F�N�g�̒��S�Ǝ��S����̒��S�������ɂȂ�ʒu�ɂ��Ă�)
	m_vDeathPos.x = (m_vPos.x - (BLACK_HOLE_SIZE / 2.0f))- (HOLE_DEATH_SIZE / 2.0f);
	m_vDeathPos.y = (m_vPos.y - (BLACK_HOLE_SIZE / 2.0f)) - (HOLE_DEATH_SIZE / 2.0f);

	//�z������
	m_pSuction = Hits::SetHitBox(this, m_vPos.x, m_vPos.y, BLACK_HOLE_SIZE, BLACK_HOLE_SIZE, ELEMENT_STAGE, OBJ_BLACK_HOLE, 0);

	//���S����
	m_pDeath = Hits::SetHitBox(this, m_vDeathPos.x, m_vDeathPos.y, HOLE_DEATH_SIZE, HOLE_DEATH_SIZE, ELEMENT_DEATH, OBJ_BLACK_HOLE, 0);
}

//�X�V
void CBlackHole::Action()
{
	//�V�[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();
	
	//�X�N���[�������̎����֓���
	if (m_bScroll == SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//�c�̎����֓���
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}
	
	//���S����̈ʒu�@(�I�u�W�F�N�g�̒��S�Ǝ��S����̒��S�������ɂȂ�ʒu�ɂ��Ă�)
	m_vDeathPos.x = (m_vPos.x + (BLACK_HOLE_SIZE / 2.0f)) - (HOLE_DEATH_SIZE / 2.0f);
	m_vDeathPos.y = (m_vPos.y + (BLACK_HOLE_SIZE / 2.0f))- (HOLE_DEATH_SIZE / 2.0f);

	//HitBox�X�V
	m_pSuction->SetPos(m_vPos.x, m_vPos.y);
	m_pDeath->SetPos(m_vDeathPos.x,m_vDeathPos.y);	
	
	//�L�����ɓ������Ă���Ƃ��̋z�����ݔ���
	if (m_pSuction->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//�L�����̈ʒu�擾
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));
		Vector vCharaPos = pChara->GetPos();

		//�L�����N�^�[���猩�����̕���(���K��)
		Vector vHoleDir=CVector::Sub(m_vDeathPos, vCharaPos);
		vHoleDir = CVector::Normalize(vHoleDir);

		//�L�����Ɉړ��x�N�g���ǉ�
		pChara->HitBlackHole(CVector::Multiply(vHoleDir,m_fSuctionPower));
	}

	//���S����
	if (m_pDeath->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//����
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�Q�[���I�[�o�[��
		Scene::SetScene(new CSceneGameOver());
	}

	//������ʊO�֏o��ƍ폜
	//��ʍ��[
	if (m_vPos.x + (BLACK_HOLE_SIZE * 2.0f) < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//��ʉ��[
	if (m_vPos.y - BLACK_HOLE_SIZE > WINDOW_SIZE_H)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�`��
void CBlackHole::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, BLACK_HOLE_SIZE, BLACK_HOLE_SIZE);
	
	//�`��
	Draw::Draw(OBJ_BLACK_HOLE, &src, &dst, m_fColor, 0.0f);
}