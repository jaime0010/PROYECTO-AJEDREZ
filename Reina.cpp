#include "Reina.h"
#include "freeglut.h"
#include"ETSIDI.h"

Reina::Reina(Vector2D pos, float r, int c) : Pieza(pos, r, c) //Constructor
{

}

void Reina::dibuja()
{
    int k, j;
    j = (int)posicion.x % 2;
    k = (int)posicion.y % 2;

    if (color == 0)
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

        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("reina-negrap.png").id);
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


        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("reina-blancap.png").id);
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
        glColor3ub(color, color, color);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);

    }
    glColor3ub(color, color, color);
    glTranslatef(posicion.x, posicion.y, 0);
   // glutWireCone(radio, 2, 10,10);
    glTranslatef(-posicion.x, -posicion.y, 0);

}

bool Reina::validar_movimiento(Vector2D p_fin, ListaPiezas* lista)
{
    Vector2D dist = Vector2D(0, 0);
    dist.x = p_fin.x - posicion.x;
    dist.y = p_fin.y - posicion.y;
    //Es una combinación entre TORRE y ALFIL, por lo que podemos combinar sus métodos

    //TORRE:
    //Movimiento vertical hacia arriba (positivo). Por ejemplo: Desde (1,1) hasta (1,5)
    if (dist.y > 0)
    {
        if (dist.x != 0)
        {
            return false;
        }
        else
        {
            for (int posy = 1; posy <= dist.y; posy++) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_y = posicion.y + posy; //Responde a la pregunta: ¿A qué coordenada y corresponde posy?

                Vector2D posiciones = Vector2D(posicion.x, coordenada_y); //Vector posiciones (de intermedia a final)
                Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                //Criterios:
                //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                if (lista->hay_pieza(posiciones) && posy != dist.y) //Hay pieza en esa posición && esa posición no es la final
                    return false;
                //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                else if (lista->hay_pieza(posiciones) && posy == dist.y && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                    return false;
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }
    //Movimiento horizontal hacia la derecha (positivo). Por ejemplo: Desde (1,3) hasta (5,3)
    else if (dist.x > 0)
    {
        if (dist.y != 0)
        {
            return false;
        }
        else
        {
            for (int posx = 1; posx <= dist.x; posx++) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_x = posicion.x + posx; //Responde a la pregunta: ¿A qué coordenada y corresponde posy?

                Vector2D posiciones = Vector2D(coordenada_x, posicion.y); //Vector posiciones (de intermedia a final)
                Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                //Criterios:
                //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                if (lista->hay_pieza(posiciones) && posx != dist.x) //Hay pieza en esa posición && esa posición no es la final
                    return false;
                //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                else if (lista->hay_pieza(posiciones) && posx == dist.x && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                    return false;
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }
    //Movimiento vertical hacia abajo (negativo). Por ejemplo: Desde (1,5) hasta (1,1)
    else if (dist.y < 0)
    {
        if (dist.x != 0)
        {
            return false;
        }
        else
        {
            for (int posy = -1; posy >= dist.y; posy--) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_y = posicion.y + posy; //Responde a la pregunta: ¿A qué coordenada y corresponde posy?

                Vector2D posiciones = Vector2D(posicion.x, coordenada_y); //Vector posiciones (de intermedia a final)
                Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                //Criterios:
                //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                if (lista->hay_pieza(posiciones) && posy != dist.y) //Hay pieza en esa posición && esa posición no es la final
                    return false;
                //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                else if (lista->hay_pieza(posiciones) && posy == dist.y && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                    return false;
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }
    //Movimiento horizontal hacia la izquierda (negativo). Por ejemplo: Desde (5,3) hasta (1,3)
    else if (dist.x < 0)
    {
        if (dist.y != 0)
        {
            return false;
        }
        else
        {
            for (int posx = -1; posx >= dist.x; posx--) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_x = posicion.x + posx; //Responde a la pregunta: ¿A qué coordenada y corresponde posy?

                Vector2D posiciones = Vector2D(coordenada_x, posicion.y); //Vector posiciones (de intermedia a final)
                Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                //Criterios:
                //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                if (lista->hay_pieza(posiciones) && posx != dist.x) //Hay pieza en esa posición && esa posición no es la final
                    return false;
                //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                else if (lista->hay_pieza(posiciones) && posx == dist.x && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
                    return false;
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }

    //ALFIL
    else if (abs(dist.x) == abs(dist.y)) //Movimiento diagonal
    {
        //Movimiento en el primer cuadrante (X hacia la derecha, Y hacia arriba)
        if (dist.x > 0 && dist.y > 0)
        {
            for (int posx = 1; posx <= dist.x; posx++)
            {
                for (int posy = 1; posy <= dist.y; posy++)
                {
                    if (abs(posx) == abs(posy))
                    {
                        Vector2D posiciones = Vector2D(0, 0); //Vector posiciones (de intermedia a final)
                        posiciones.x = posicion.x + posx;
                        posiciones.y = posicion.y + posy;
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && posy != dist.y) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && posx == dist.x && posy == dist.y && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
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
                    if (abs(posx) == abs(posy))
                    {
                        Vector2D posiciones = Vector2D(0, 0); //Vector posiciones (de intermedia a final)
                        posiciones.x = posicion.x + posx;
                        posiciones.y = posicion.y + posy;
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && posy != dist.y) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && posx == dist.x && posy == dist.y && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
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
                    if (abs(posx) == abs(posy))
                    {
                        Vector2D posiciones = Vector2D(0, 0); //Vector posiciones (de intermedia a final)
                        posiciones.x = posicion.x + posx;
                        posiciones.y = posicion.y + posy;
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && posy != dist.y) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && posx == dist.x && posy == dist.y && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
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
                    if (abs(posx) == abs(posy))
                    {
                        Vector2D posiciones = Vector2D(0, 0); //Vector posiciones (de intermedia a final)
                        posiciones.x = posicion.x + posx;
                        posiciones.y = posicion.y + posy;
                        Pieza* presa = lista->obtener(posiciones); //Obtiene posible pieza en las posiciones (de intermedia a final)
                        //Criterios:
                        //No se pueden saltar piezas: solo puede haber piezas en la posición final:
                        if (lista->hay_pieza(posiciones) && posy != dist.y) //Hay pieza en esa posición && esa posición no es la final
                            return false;
                        //Comer: en caso de haber pieza en la posición final, esta ha de ser de distinto color:
                        else if (lista->hay_pieza(posiciones) && posx == dist.x && posy == dist.y && mismo_color(presa)) //Hay pieza en posicion final && Mismo color
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