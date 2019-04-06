#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "Enemy.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CEnemy::CEnemy(int x, int y)
{
	//�ʒu
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CEnemy::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//�J�E���^
	m_Count = 0;

	//�e�ۗp���x
	m_fSpeed.x = 1.0f;
	m_fSpeed.y = 1.0f;

	//��l���̈ʒu�擾
	CObjMainChara* obj_pChara = new CObjMainChara();
	m_fChara = obj_pChara->GetPos();

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, ENEMY_SIZE, ENEMY_SIZE, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//�X�V
void CEnemy::Action()
{
	//�J�E���^�X�V
	m_Count++;
	if (m_Count > 10000)
		m_Count = 0;

	if (m_Count % SHOT_TIME == 0)
	{
		//�L�����N�^�̃|�C���^
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));

		//�L�����N�^�̈ʒu���擾
		if (pChara != nullptr)
		{
			Vector vCharaPos = pChara->GetPos();


			//�e����
			CEnemyBullet* pBullet = new CEnemyBullet(m_vPos, CVector::Create(1.0f , 0.0f));
			Objs::InsertObj(pBullet, OBJ_ENEMY_BULLET, 10);
		}
	}

	//�����蔻��-----------------------------------------------------

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//��l���̒e�ɓ�����Ə���
	if (hit_b->CheckElementHit(ELEMENT_CHARA_BULLET) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//--------------------------------------------------------------
}

//�`��
void CEnemy::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x,ENEMY_SIZE ,ENEMY_SIZE);

	//�`��
	Draw::Draw(OBJ_ENEMY, &src, &dst, m_fColor, 0.0f);
}
