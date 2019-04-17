#include "GameL/UserData.h"
#include "GameL/DrawFont.h"

#include "Score.h"
#include "GameHead.h"
#include "Function.h"

//������
void CScore::Init()
{
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//���_�̏�����
	((UserData*)Save::GetData())->m_iScore = 0;
}

//�X�V
void CScore::Action()
{

}

//�`��
void CScore::Draw()
{
	//�X�R�A�\��
	wchar_t m_wSentence[128];
	swprintf_s(m_wSentence, L"Score : %d", ((UserData*)Save::GetData())->m_iScore);
	Font::StrDraw(m_wSentence, WINDOW_SIZE_W - 140.0f, 0.0f, 20.0f, m_fColor);
}