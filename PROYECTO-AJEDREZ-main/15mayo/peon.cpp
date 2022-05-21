#include "peon.h"
#include "freeglut.h"
#include "ETSIDI.h"

Peon::Peon(float x, float y, float r, int c)
{

    radio = r;
    posicion.x = x;
    posicion.y = y;
    color = c;
}

void Peon::dibuja()

{
    int k, j;
    j = (int) posicion.x % 2;
    k = (int)posicion.y % 2;
    if (color == 0)
    {
        if ( j == 0 )
        {
            if (k == 0)
                glColor3ub(80, 7, 45);//color morado

            else 
                glColor3ub(128, 64, 0);//color marron
        }
        else if (j == 1)
        {
            if (k == 0)
                glColor3ub(128, 64, 0);//color marron

            else
            glColor3ub(80, 7, 45);//color morado
        }
        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("peon.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
       

        glTexCoord2d(0, 1); ;glVertex3f(posicion.x - 0.5, posicion.y - 0.5, 0.05f);
        glTexCoord2d(1, 1); ;glVertex3f(posicion.x + 0.5, posicion.y - 0.5, 0.05f);
        glTexCoord2d(1, 0);   glVertex3f(posicion.x + 0.5, posicion.y + 0.5, 0.05f);
        glTexCoord2d(0, 0); glVertex3f(posicion.x - 0.5, posicion.y + 0.5, 0.05f);
        //
        glEnd();
        glEnable(GL_LIGHTING);

        //Liberar memoria de la textura
        glBindTexture(GL_TEXTURE_2D, 0);
        glColor3ub(color, color, color);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);
    }
    if (color == 255)
    {
        
        if (j == 0)
        {
            if (k == 0)
                glColor3ub(80, 7, 45);//color morado

            else
                glColor3ub(128, 64, 0);//color marron
        }
        else if (j == 1)
        {
            if (k == 0)
                glColor3ub(128, 64, 0);//color marron

            else
                glColor3ub(80, 7, 45);//color morado
        }
       
        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("peonblanco.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
    
        glTexCoord2d(0, 1); ;glVertex3f(posicion.x - 0.5, posicion.y - 0.5, 0.05f);
        glTexCoord2d(1, 1); ;glVertex3f(posicion.x + 0.5, posicion.y - 0.5, 0.05f);
        glTexCoord2d(1, 0);   glVertex3f(posicion.x + 0.5, posicion.y + 0.5, 0.05f);
        glTexCoord2d(0, 0); glVertex3f(posicion.x - 0.5, posicion.y + 0.5, 0.05f);
        //
        glEnd();
        glEnable(GL_LIGHTING);

        //Liberar memoria de la textura
        glBindTexture(GL_TEXTURE_2D, 0);
        glColor3ub(color, color, color);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);

    }
   

}



