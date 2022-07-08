
#include "Vector2D.h"

Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}

bool Vector2D::operator==(Vector2D v)
{
	return (x == v.x && y == v.y);
}


Vector2D Vector2D::operator+(Vector2D& v)
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

Vector2D Vector2D::operator-(Vector2D& v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

bool Vector2D::comp_abs_iguales()
{
	//Hay que hacer eso porque abs() trabaja con ENTEROS, y las coordinadas son FLOAT
	int i_x = x;
	int i_y = y;
	if (abs(i_x) == abs(i_y))
		return true;
	else
		return false;
}

Vector2D Vector2D::abs_v()
{
	int i_x = x;
	int i_y = y;
	Vector2D res = Vector2D(abs(i_x), abs(i_y));
	return res;
}

bool Vector2D::operator<(Vector2D v)
{
	return (x < v.x && y < v.y);
}