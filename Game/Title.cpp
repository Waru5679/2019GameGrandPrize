#include "Title.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//������
void CTitle::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�^�C�g��");

	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

}

//�X�V
void CTitle::Action()
{
	//Enter�Ń��C����
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain());
		this->SetStatus(false);
	}
}

//�`��
void CTitle::Draw()
{
	RECT_F Src, Dst;

	//�؂���
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//�`��ʒu
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//�`��
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

}
