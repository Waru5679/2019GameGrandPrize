#pragma once

//�x�N�g���\����
struct Vector
{
	float x;
	float y;
};

//�x�N�^�[�N���X
class CVector
{
public :
	static Vector Add(Vector Vec1, Vector Vec2);	//���Z
	static Vector Sub(Vector Vec1, Vector Vec2);	//���Z

	static Vector Multiply(Vector Vec, float Num);	//��Z
	static Vector Create(float x, float y);	//�x�N�g������
	static Vector Normalize(Vector Vec);	//���K��
};