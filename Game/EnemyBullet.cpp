#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "EnemyBullet.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CEnemyBullet::CEnemyBullet(Vector vPos,Vector vMove)
{
	//�ʒu
	m_vPos = vPos;
	
	//�ړ�
	m_vMove = vMove;
}

//������
void CEnemyBullet::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//��]
	m_fRot = 0.0f;

	//��ʊO
	m_bInWindow=true;

	m_bShot = true;
	m_fShotTime = 0.0f;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, BULLET_SIZE, BULLET_SIZE, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//�X�V
void CEnemyBullet::Action()
{
	if (m_bShot == true)
	{
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));

		//��l���̃|�W�V�����Z�b�g
		Vector m_vPos_Chara = pChara->GetPos();
		m_vPos_Chara.x = m_vPos_Chara.x - m_vPos.x;
		m_vPos_Chara.y = m_vPos_Chara.y - m_vPos.y;

		//��l���̊p�x�����
		float m_fAngle_Chara = GetAtan2Angle(m_vPos_Chara.x, -m_vPos_Chara.y);
		//�����̒e(EnemyBullet)�̊p�x�����
		float m_fAngle_Bullet = GetAtan2Angle(m_vMove.x, -m_vMove.y);


		//�p�x1��
		float r = 3.14f / 180.0f;

		//ar���br���Ⴂ�ꍇ�ړ�������+1��������
		//�Ⴄ�ꍇ�ړ�������-1��������
		if (m_fAngle_Chara < m_fAngle_Bullet)
		{
			m_vMove.x = m_vMove.x * cos(r) - m_vMove.y * sin(r);
			m_vMove.y = m_vMove.y * cos(r) + m_vMove.x * sin(r);
		}
		else
		{
			m_vMove.x = m_vMove.x * cos( r) - m_vMove.y * sin( r);
			m_vMove.y = m_vMove.y * cos(-r) + m_vMove.x * sin(-r);
		}

		//���K��
		UnitVec(&m_vMove.x, &m_vMove.y);	
		m_bShot = false;
	}

	m_vPos = CVector::Add(m_vPos, m_vMove);

	//��ʊO�����ׂ�
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//�����蔻��

	//Hitbox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//��l���ɓ�����ƃQ�[���I�[�o�[�ֈڍs
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//���g���폜
	//	this->SetStatus(false);
	//	Hits::DeleteHitBox(this);
		//�Q�[���I�[�o�[
	//	Scene::SetScene(new CSceneGameOver());
	}

	//��ʊO�Ȃ����
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//�`��
void CEnemyBullet::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, BULLET_SIZE, BULLET_SIZE);

	//�`��
	Draw::Draw(OBJ_ENEMY_BULLET, &src, &dst, m_fColor, m_fRot);
}
