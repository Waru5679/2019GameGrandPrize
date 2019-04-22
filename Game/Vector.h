#pragma once

//ベクトル構造体
struct Vector
{
	float x;
	float y;
};

//ベクタークラス
class CVector
{
public :
	static Vector Add(Vector Vec1, Vector Vec2);	//加算
	static Vector Sub(Vector Vec1, Vector Vec2);	//減算

	static Vector Multiply(Vector Vec, float Num);	//乗算
	static Vector Create(float x, float y);	//ベクトル生成
	static Vector Normalize(Vector Vec);	//正規化
};