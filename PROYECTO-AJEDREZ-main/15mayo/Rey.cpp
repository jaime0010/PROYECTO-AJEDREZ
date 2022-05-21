#include "Rey.h"
#include "freeglut.h"

Rey::Rey(float x, float y, float r, int c)
{

    radio = r;
    posicion.x = x;
    posicion.y = y;
    color = c;
}

void Rey::dibuja()
{
    glColor3ub(color, color, color);
    glTranslatef(posicion.x, posicion.y, 0);
    glutWireTeapot(radio);
    glTranslatef(-posicion.x, -posicion.y, 0);

}