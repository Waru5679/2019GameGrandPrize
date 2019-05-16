#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//名前入力クラス
class CNameInput :public CObj
{
public:
	CNameInput() {};
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

	//キーボードから文字を読み取る関数
	bool KeyInput(int number);

	//文字列の入力が終わっているか(\0があるか)調べる関数
	bool InputEndCheck();

	//文字列の文字ごとの間に半角空白を入れる関数
	void NameCpy(char name[]);

private:
	float m_fColor[4];
	float m_fColor_Red[4];

	char m_cName[6];		//入力された名前の保存用
	char m_cCopy_Name[11];	//wchar_tに変換する用の配列
	bool m_bFirst_Flag;		//最初の1回だけ処理しないようにするためのフラグ
	bool m_bKey_Flag;		//キー入力可能な状態かどうかを表すフラグ
	bool m_bInput_Flag;		//キー入力されたかどうかを表すフラグ
	bool m_bEnd_Flag;		//名前入力が終了しているかどうかのフラグ
	bool m_bNoname_Flag;	//何も入力せずにEnterを押した場合に注意文を出すためのフラグ
	bool m_bTime_Flag;		//文字の点滅用フラグ　true:表示時　false:消えてる時
	int m_iInput_Count;		//入力した回数のカウンター
	int m_iTime;			//文字の点滅用タイム
};