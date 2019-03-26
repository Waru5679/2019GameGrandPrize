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
			CEnemyBullet* pBullet = new CEnemyBullet(m_vPos, CVector::Create(1.0f, 0.0f));
			Objs::InsertObj(pBullet, OBJ_ENEMY_BULLET, 10);
		}
	}
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
