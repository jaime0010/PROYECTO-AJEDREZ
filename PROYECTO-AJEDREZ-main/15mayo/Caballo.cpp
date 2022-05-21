#include "Caballo.h"
#include "freeglut.h"

Caballo::Caballo(float x, float y, float r, int c)
{

    radio = r;
    posicion.x = x;
    posicion.y = y;
    color = c;
}

void Caballo::dibuja()
{
    glColor3ub(color, color, color);
    glTranslatef(posicion.x, posicion.y, 0);
    glutWireCube(radio);
    glTranslatef(-posicion.x, -posicion.y, 0);

}