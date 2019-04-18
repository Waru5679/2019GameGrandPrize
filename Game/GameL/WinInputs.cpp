#include "WinInputs.h"
using namespace GameL;

int   CWinInputs::m_x,CWinInputs::m_y;		//マウス座標
bool  CWinInputs::m_ButtonL;				//マウスクリック
bool  CWinInputs::m_ButtonR;
BYTE  CWinInputs::m_KeyBoard[256];			//キーボード配列
bool CWinInputs::m_KeyState[256];			//キーの状態


void CWinInputs::Init()
{
	m_x=0;
	m_y=0;
	m_ButtonL=false;
	m_ButtonR=false;
	memset(m_KeyBoard,0x00,sizeof(m_KeyBoard));

	for (int i = 0; i < 256; i++)
		m_KeyState[i] = false;
}

bool CWinInputs::WmInput(HWND hWnd,UINT* uMsg, LPARAM* lParam)
{
	if(*uMsg== WM_MOUSEMOVE )
	{
		POINT point={ LOWORD(*lParam), HIWORD((*lParam))};
		
		m_x = point.x;   // カーソルの x 座標
		m_y = point.y;   // カーソルの y 座標
		return true;
	}
	else if(*uMsg==WM_LBUTTONDOWN)
	{
		m_ButtonL=true;
	}
	else if(*uMsg==WM_LBUTTONUP)
	{
		m_ButtonL=false;
	}
	else if(*uMsg==WM_RBUTTONDOWN)
	{
		m_ButtonR=true;
	}
	else if(*uMsg==WM_RBUTTONUP)
	{
		m_ButtonR=false;
	}
	return false;
}

bool CWinInputs:: GetVKey(int v_key)
{	
	if(GetAsyncKeyState(v_key)&0x8000)
		return true;
	else
		return false;
	return false;
}

bool CWinInputs::GetTrrigerKey(int Key)
{
	//キーが押されていてる場合
	if ((GetAsyncKeyState(Key) & 0x8000))
	{
		//キーのフラグがオフなら
		if (m_KeyState[Key] == false)
		{
			m_KeyState[Key] = true;
			return true;
		}
	}
	//キーが押されていない場合
	else
	{
		m_KeyState[Key] = false;
	}
	return false;
}

bool CWinInputs::GetMouButtonL()
{
	return m_ButtonL;
}
bool CWinInputs::GetMouButtonR()
{
	return m_ButtonR;
}

int CWinInputs:: GetPosX()
{
	return m_x;
}

int CWinInputs::GetPosY()
{
	return m_y;
}