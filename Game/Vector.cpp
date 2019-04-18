#include "Vector.h"
#include <math.h>

//â¡éZ
Vector CVector::Add(Vector Vec1, Vector Vec2)
{
	Vector vOut;

	vOut.x = Vec1.x + Vec2.x;
	vOut.y = Vec1.y + Vec2.y;

	return vOut;
}

//å∏éZ
Vector CVector::Sub(Vector Vec1, Vector Vec2)
{
	Vector vOut;

	vOut.x = Vec1.x - Vec2.x;
	vOut.y = Vec1.y - Vec2.y;

	return vOut;

}

//ÉxÉNÉgÉãê∂ê¨
Vector CVector::Create(float x, float y)
{
	Vector vOut;

	vOut.x = x;
	vOut.y = y;

	return vOut;
}

//ê≥ãKâª
Vector CVector::Normalize(Vector Vec)
{
	Vector vOut;
	
	float Size = 0.0f;
	Size = fabs(Vec.x) + fabs(Vec.y);

	vOut.x = Vec.x/Size;
	vOut.y = Vec.y/Size;

	return vOut;
}
