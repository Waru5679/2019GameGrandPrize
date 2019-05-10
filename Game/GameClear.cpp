#include "GameClear.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"

//������
void CGameClear::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//�X�V
void CGameClear::Action()
{
	//�G���^�[�Ń^�C�g����
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		this->SetStatus(false);
	}
}

//�`��
void CGameClear::Draw()
{
	RECT_F Dst, Src;

	//�؂���ʒu
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//�`��ʒu
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//�`��
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);
	
}