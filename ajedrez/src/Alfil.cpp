#include "Alfil.h"
#include "freeglut.h"
#include"ETSIDI.h"

Alfil::Alfil(Vector2D pos, float r, bool b) : Pieza(pos, r, b) //Constructor
{

}

void Alfil::dibuja()
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

        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfil-negrop.png").id);
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
        glColor3ub(0, 0, 0);
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


        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfil-blancop.png").id);
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
        glColor3ub(255,255,255);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);

    }

}

bool Alfil::validar_movimiento(Vector2D p_fin, ListaPiezas* lista)
{
    Vector2D dist = p_fin - posicion; //Vector2D: operador - sobrecargado

    if (dist.comp_abs_iguales()) //Movimiento diagonal
    {
        //Movimiento en el primer cuadrante (X hacia la derecha, Y hacia arriba)
        if (dist.x > 0 && dist.y > 0)
        {
            for (int posx = 1; posx <= dist.x; posx++)
            {
                for (int posy = 1; posy <= dist.y; posy++)
                {
                    Vector2D pos = Vector2D(posx, posy);
                    if (pos.comp_abs_iguales())
                    {
                        //Vector posiciones (de intermedia a final)
                        Vector2D posiciones = posicion + pos; //Vector2D: operador - sobrecargado
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && !(pos == dist)) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && pos == dist && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                            return false;
                    }
                }
            }
            return true;
        }
        //Movimiento en el segundo cuadrante (X hacia la iquierda, Y hacia arriba)
        else if (dist.x < 0 && dist.y > 0)
        {
            for (int posx = -1; posx >= dist.x; posx--)
            {
                for (int posy = 1; posy <= dist.y; posy++)
                {
                    Vector2D pos = Vector2D(posx, posy);
                    if (pos.comp_abs_iguales())
                    {
                        //Vector posiciones (de intermedia a final)
                        Vector2D posiciones = posicion + pos; //Vector2D: operador - sobrecargado
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && !(pos == dist)) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && pos == dist && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                            return false;
                    }
                }
            }
            return true;
        }
        //Movimiento en el tercer cuadrante (X hacia la izquierda, Y hacia abajo)
        else if (dist.x < 0 && dist.y < 0)
        {
            for (int posx = -1; posx >= dist.x; posx--)
            {
                for (int posy = -1; posy >= dist.y; posy--)
                {
                    Vector2D pos = Vector2D(posx, posy);
                    if (pos.comp_abs_iguales())
                    {
                        //Vector posiciones (de intermedia a final)
                        Vector2D posiciones = posicion + pos; //Vector2D: operador - sobrecargado
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && !(pos == dist)) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && pos == dist && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                            return false;
                    }
                }
            }
            return true;
        }
        //Movimiento en el cuarto cuadrante (X hacia la derecha, Y hacia abajo)
        else if (dist.x > 0 && dist.y < 0)
        {
            for (int posx = 1; posx <= dist.x; posx++)
            {
                for (int posy = -1; posy >= dist.y; posy--)
                {
                    Vector2D pos = Vector2D(posx, posy);
                    if (pos.comp_abs_iguales())
                    {
                        //Vector posiciones (de intermedia a final)
                        Vector2D posiciones = posicion + pos; //Vector2D: operador - sobrecargado
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && !(pos == dist)) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && pos == dist && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                            return false;
                    }
                }
            }
            return true;
        }
    }
    else
        return false;
}
