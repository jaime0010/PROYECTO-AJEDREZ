
#include "Vector2D.h"

Vector2D::Vector2D(float xv, float yv)
{
    x = xv;
    y = yv;
}

bool Vector2D::operator==(Vector2D* pos)
{
    return (x == pos->x && y == pos->y);
}