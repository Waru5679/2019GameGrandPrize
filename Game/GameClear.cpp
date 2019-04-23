#include "GameClear.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"

//������
void CGameClear::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�Q�[���N���A");

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
	Font::StrDraw(L"�Q�[���N���A", 100.0f, 100.0f, 32.0f, m_fColor);
}