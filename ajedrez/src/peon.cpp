#include "peon.h"
#include "freeglut.h"
#include "ETSIDI.h"

Peon::Peon(Vector2D pos, bool b) : Pieza(pos, b) //Constructor
{

}

void Peon::dibuja()
{
    int k, j;
    j = (int)posicion.x % 2; //Posición x: si es par, 0; si es impar, 1;
    k = (int)posicion.y % 2; //Posición y: si es par, 0; si es impar, 1;

    if (blanca == false) //Peones Negros
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
        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peon-negrop.png").id);
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
        glColor3ub(0,0,0);
        glTranslatef(posicion.x, posicion.y, 0);
        //glutSolidSphere(radio, 20, 20);
        glTranslatef(-posicion.x, -posicion.y, 0);
    }
    else if (blanca == true) //Peones Blancos
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

        glEnable(GL_TEXTURE_2D);         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peon-blancop.png").id);
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

//Este es el correcto: le pasamos la posicion final y la lista de piezas!
bool Peon::validar_movimiento(Vector2D p_fin, ListaPiezas* lista)
{
    Vector2D dist = p_fin - posicion; //Vector2D: operador - sobrecargado

    //Distinción entre peones blancos y negros
    //También filtramos aquellos movimientos que vayan en el sentido INCORRECTO
    int pos_inicial, pos_intermedia;
    if (blanca == true) //Peones Blancos
    {
        pos_inicial = 2; //Todos los peones blancos empiezan en esta fila
        pos_intermedia = 3;
        if (dist.y <= 0) //Siendo blanco, si NO avanza hacia arriba, NO valida el movimiento.
            return false;
    }
    else //Peones negros
    {
        pos_inicial = 7; //Todos los peones negros empiezan en esta fila.
        pos_intermedia = 6;
        if (dist.y >= 0) //Siendo negro, si NO avanza hacia abajo, NO valida el movimiento.
            return false;
    }

    //Avance de dos casillas vertical (solo primer movimiento).
    if (dist.x == 0 && abs(dist.y) == 2 && posicion.y == pos_inicial) //pos_inicial y |dist.y|: la criba de color se ha hecho antes.
    {
        //El peón NO puede comer hacia adelante, ni saltar piezas.
        Vector2D adelante = Vector2D(posicion.x, pos_intermedia); //Casilla intermedia. También determinada anteriormente por el color
        if (lista->hay_pieza(adelante) || lista->hay_pieza(p_fin))
            return false; //Si hay alguna pieza en la posicion final o intermedia, NO valida el movimiento.
        else
            return true;
    }
    //Avance unitario vertical
    else if (dist.x == 0 && abs(dist.y) == 1) //|dist.y|: la criba de color se ha hecho antes.
    {
        //El peón NO puede comer hacia adelante.
        if (lista->hay_pieza(p_fin))
            return false; //Si hay alguna pieza en la posición final, NO valida el movimiento.
        else
            return true;
    }
    //Movimiento diagonal (+1 si hacia la derecha, -1 si a la izquierda).
    else if ((dist.x == 1 || dist.x == -1) && abs(dist.y) == 1) //+1 si hacia la derecha, -1 si a la izquierda
    {
        //Solo puede moverse en diagonal si es para comerse a otra pieza.
        Pieza* presa = lista->obtener(p_fin);
        if (presa == NULL || mismo_color(presa))
            return false; //Si NO hay pieza en la casilla de destino, o esta es del mismo color que la que movemos, NO valida el movimiento.
        else
            return true;
    }
    else
        return false;
}


