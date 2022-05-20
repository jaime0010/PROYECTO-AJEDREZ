#include "Torre.h"
#include "freeglut.h"

Torre::Torre(float x, float y, float r, int c)
{
    radio = r;
    posicion.x = x;
    posicion.y = y;
    color = c;
}

void Torre::dibuja()
{
    glColor3ub(color, color, color);
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidCube(radio);
    glTranslatef(-posicion.x, -posicion.y, 0);
}
