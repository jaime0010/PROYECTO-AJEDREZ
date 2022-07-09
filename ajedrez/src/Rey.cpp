#include "Rey.h"
#include "freeglut.h"
#include"ETSIDI.h"

Rey::Rey(Vector2D pos, bool b) : Pieza(pos, b) //Constructor
{

}

void Rey::dibuja()
{
    int k, j;
    j = (int)posicion.x % 2;
    k = (int)posicion.y % 2;

    if (blanca == false)
    {
        if (j == 0)
        {
            if (k == 0)
                glColor3ub(46, 97, 158);//color azul oscuro
            else
                glColor3ub(156, 198, 249);//color azul claro

        }
        else if (j == 1)
        {
            if (k == 0)
                glColor3ub(156, 198, 249);//color azul claro

            else
                glColor3ub(46, 97, 158);//color azul oscuro
        }
        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey-negrop.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);


        glTexCoord2d(0, 1); ;glVertex3f(posicion.x - 0.5, posicion.y - 0.5, 0.01f);
        glTexCoord2d(1, 1); ;glVertex3f(posicion.x + 0.5, posicion.y - 0.5, 0.01f);
        glTexCoord2d(1, 0);   glVertex3f(posicion.x + 0.5, posicion.y + 0.5, 0.01f);
        glTexCoord2d(0, 0); glVertex3f(posicion.x - 0.5, posicion.y + 0.5, 0.01f);
        //
        glEnd();
        glEnable(GL_LIGHTING);

        //Liberar memoria de la textura
        glBindTexture(GL_TEXTURE_2D, 0);
        glColor3ub(0,0,0);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);
    }
    else if (blanca == true)
    {
        if (j == 0)
        {
            if (k == 0)
                glColor3ub(46, 97, 158);//color azul oscuro
            else
                glColor3ub(156, 198, 249);//color azul claro

        }
        else if (j == 1)
        {
            if (k == 0)
                glColor3ub(156, 198, 249);//color azul claro

            else
                glColor3ub(46, 97, 158);//color azul oscuro
        }


        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey-blancop.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);

        glTexCoord2d(0, 1); ;glVertex3f(posicion.x - 0.5, posicion.y - 0.5, 0.01f);
        glTexCoord2d(1, 1); ;glVertex3f(posicion.x + 0.5, posicion.y - 0.5, 0.01f);
        glTexCoord2d(1, 0);   glVertex3f(posicion.x + 0.5, posicion.y + 0.5, 0.01f);
        glTexCoord2d(0, 0); glVertex3f(posicion.x - 0.5, posicion.y + 0.5, 0.01f);

        glEnd();
        glEnable(GL_LIGHTING);

        //Liberar memoria de la textura
        glBindTexture(GL_TEXTURE_2D, 0);
        glColor3ub(255,255,255);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);

    }
}

bool Rey::validar_movimiento(Vector2D p_fin, ListaPiezas* lista)
{
    Vector2D d = p_fin - posicion; //Vector2D: operador - sobrecargado
    Vector2D dist = d.abs_v();
    Vector2D lim_desplaz = Vector2D(2, 2); //Puede moverse 0 o 1 en cada dirección. Fijarse en el if
    Pieza* presa = lista->obtener(p_fin);

    if (dist < lim_desplaz)
    {
        if (lista->hay_pieza(p_fin) && mismo_color(presa)) //Hay pieza PERO es del mismo color
            return false;
        else
            return true;
    }
    else
        return false;
}
