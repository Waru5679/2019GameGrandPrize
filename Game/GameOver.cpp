#include "GameOver.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"


//������
void CGameOver::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�Q�[���I�[�o�[");

	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//�X�V
void CGameOver::Action()
{
	//Enter�Ń^�C�g����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		this->SetStatus(false);
	}
}

//�`��
void CGameOver::Draw()
{
	Font::StrDraw(L"�Q�[���I�[�o�[", 100.0f, 100.0f, 32.0f, m_fColor);
}
