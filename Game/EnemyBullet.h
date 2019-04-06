#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

//“G’eŠÛƒNƒ‰ƒX
class CEnemyBullet :public CObj
{
public:
	CEnemyBullet(Vector vPos, Vector vMove);
	void Init();
	void Action();
	void Draw();
private:
	float m_fColor[4];	//•`‰æF
	Vector m_vPos;		//ˆÊ’u
	Vector m_vMove;		//ˆÚ“®
	float m_fRot;		//‰ñ“]
	bool m_bInWindow;	//‰æ–Ê“à‚©‚Ç‚¤‚©
	bool m_bShot;		//”­ËŠÇ—
	float m_fvx;
	float m_fvy;
};