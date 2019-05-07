#include "Ranking.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//������
void CRanking::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�����L���O");

	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

}

//�X�V
void CRanking::Action()
{
	//Enter�Ń��j���[��ʂɖ߂�
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStageSelect());
		this->SetStatus(false);
	}
}

//�`��
void CRanking::Draw()
{
	Font::StrDraw(L"�����L���O", 230.0f, 50.0f, 64.0f, m_fColor);

	//�Z���N�g�V�[���߂�p�ē��\��
	Font::StrDraw(L"Enter �Ŗ߂�",700.0f,580.0f,16.0f,m_fColor);

	//�����L���O�\��
	for (int i = 0; i < MAX_RANKING - 1; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking[i]);
		Font::StrDraw(str, 150, 150 + (45 * i), 32, m_fColor);
	}
}