#include "Title.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
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
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain());
		this->SetStatus(false);
	}
}

//�`��
void CTitle::Draw()
{
	Font::StrDraw(L"�^�C�g��", 100.0f, 100.0f, 32.0f, m_fColor);
}
