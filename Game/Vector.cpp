#include "Vector.h"

//���Z
Vector CVector::Add(Vector Vec1, Vector Vec2)
{
	Vector vOut;

	vOut.x = Vec1.x + Vec2.x;
	vOut.y = Vec1.y + Vec2.y;

	return vOut;
}

//�x�N�g������
Vector CVector::Create(float x, float y)
{
	Vector vOut;

	vOut.x = x;
	vOut.y = y;

	return vOut;
}
