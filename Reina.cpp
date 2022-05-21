#include "Reina.h"
#include "freeglut.h"

Reina::Reina(float x, float y, float r, int c)
{

    radio = r;
    posicion.x = x;
    posicion.y = y;
    color = c;
}

void Reina::dibuja()
{
    glColor3ub(color, color, color);
    glTranslatef(posicion.x, posicion.y, 0);
    glutWireCone(radio, 2, 10,10);
    glTranslatef(-posicion.x, -posicion.y, 0);

}