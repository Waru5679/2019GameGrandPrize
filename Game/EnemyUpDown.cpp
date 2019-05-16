#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "EnemyUpDown.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CEnemyUpDown::CEnemyUpDown(int x, int y)
{
	//�ʒu
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CEnemyUpDown::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�J�E���^
	m_Count = 0;

	//�ړ�
	m_fvx = 0.0f;
	m_fvy = SCROLL_SPEED;

	m_vBulletMove.x = 0.0f;
	m_vBulletMove.y = SCROLL_SPEED;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, ENEMY_SIZE, ENEMY_SIZE, ELEMENT_ENEMY,OBJ_ENEMY_UPDOWN, 1);
}

//�X�V
void CEnemyUpDown::Action()
{
	//�ړ�
	if (m_vPos.y >= 0)
	{
		m_Count++;

		if (m_Count >= 360.0f)
		{
			m_fvy = -SCROLL_SPEED;
		}
		else if(m_Count >= 180.0f)
		{
			m_fvy = 0.0f;
		}

	}

	//�ʒu�̍X�V
	m_vPos.x += m_fvx;
	m_vPos.y += m_fvy;

	//�J�E���^�X�V
	m_iBulletCount++;
	if (m_iBulletCount > 10000)
		m_iBulletCount = 0;

	if (m_iBulletCount % SHOT_TIME == 0)
	{
		//�e����
		CEnemyBullet* pBullet = new CEnemyBullet(m_vPos, m_vBulletMove);
		Objs::InsertObj(pBullet, OBJ_ENEMY_BULLET, 50);
		
	}


	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//��l���̒e�ɓ�����Ə���
	if (hit_b->CheckObjNameHit(OBJ_CHARA_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�J�E���g��3�b�ȏ�ŉ�ʊO�ɏo����폜
	if (m_Count >= 180.0f)
	{
		if (m_vPos.y + ENEMY_SIZE < 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

}

//�`��
void CEnemyUpDown::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, ENEMY_SIZE, ENEMY_SIZE);

	//�`��
	Draw::Draw(OBJ_ENEMY_UPDOWN, &src, &dst, m_fColor, 0.0f);
}