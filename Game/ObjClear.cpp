#include "ObjClear.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"

//�R���X�g���N�^
CObjClear::CObjClear(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CObjClear::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�����蔻��
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, CLEAR_SIZE, CLEAR_SIZE, ELEMENT_STAGE, OBJ_GAME_CLEAR, 1);
}

//�X�V
void CObjClear::Action()
{
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
void CObjClear::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, CLEAR_SIZE, CLEAR_SIZE);

	//�`��
	Draw::Draw(OBJ_GAME_CLEAR, &src, &dst, m_fColor, 0.0f);
}