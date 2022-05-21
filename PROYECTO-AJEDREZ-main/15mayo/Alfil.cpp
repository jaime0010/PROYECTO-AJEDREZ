#include "Alfil.h"
#include "freeglut.h"

Alfil::Alfil(float x, float y, float r, int c)
{

    radio = r;
    posicion.x = x;
    posicion.y = y;
    color = c;
}

void Alfil::dibuja()
{
    glColor3ub(color, color, color);
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidTorus(0.1, radio, 100, 100);

    glTranslatef(-posicion.x, -posicion.y, 0);

}
