#include "listapiezas.h"
#include<iostream>
#include "freeglut.h"
using namespace std;

listapiezas::listapiezas()
{
    for (int i = 0; i < MAX_PIEZAS; i++)
    {
        lista_piezas[i] = NULL;// ponerlo a null
    }
}

bool listapiezas::agregar(Pieza*p)
{
    if (numero_p >= MAX_PIEZAS)// Si nuestro lista esta llena, ya no puede devolver mas
        return false;

    lista_piezas[numero_p] = p;
    numero_p++;
    return true;
}

void listapiezas::dibuja()
{
    for (int i = 0;i < numero_p;i++)
    {
        lista_piezas[i]->dibuja();
    }
}

void listapiezas::mover(int h)
{
    bool val=false;
        Vector2D a;
        cout << "donde la quieres mover " << endl;  cin >> a.x >> a.y;

        if (a.x > 0 && a.x < 9 && a.y>0 && a.y < 9)
        {



            //se revisa si se puede mover
            if (h < 16)//0 a 15 es un peon
                val = validar_peon(a, h);
            if (h > 15 && h < 20)// 16 a 19 es una torre
                val = validar_torre(a, h);
            if (h > 19 && h < 24)//20 a 23 es un alfil
                val = validar_alfil(a, h);
            if (h > 23 && h < 26)//24 y 25 son los reyes
                val = validar_rey(a, h);
            if (h > 25 && h < 28)//26 y 27 son las reinas
                if (validar_alfil(a, h) || validar_torre(a, h))
                    val = true;
            if (h > 27 && h < 30)//28, y 29
                val = validar_caballo(a, h);



            int k = donde_esta(a);
            bool j, w;
            if (val)
            {


                if (k != numero_p)
                {
                    j = es_blanca(h);//la que queremos mover
                    w = es_blanca(k);//a donde va
                    if (j == w)//vemos si son del mismo color
                        cout << "no se puede mover:" << endl;
                    else//destruimos y movemos
                    {
                        destruir(k);
                        lista_piezas[h]->posicion.x = a.x;
                        lista_piezas[h]->posicion.y = a.y;
                    }
                }

                else//si no detecta que hay alguna pieza, tambien mueve
                {
                    lista_piezas[h]->posicion.x = a.x;
                    lista_piezas[h]->posicion.y = a.y;
                }
            }
            else
                cout << "movimineto invalido" << endl;

        }
}

int listapiezas::donde_esta(Vector2D a)
{

    for (int i = 0; i < numero_p; i++)
    {
        if (lista_piezas[i]->posicion.x == a.x && lista_piezas[i]->posicion.y == a.y)//REVISAMOS LA POSCION DE todas las piezas
        {
            if (i < 16)//es un peon
                cout << "es un peon" << endl;
            if (i > 15 && i < 20)
                cout << "es una torre" << endl;
            if (i > 19 && i < 24)
                cout << "es un alfil" << endl;
            if (i > 23 && i < 26)//24 y 25
                cout << "es un rey" << endl;
            if (i > 25 && i < 28)//26 y 27 son las reinas
                cout << "es una reina" << endl;
            if (i > 27 && i < 30)//28, y 29
                cout << "es un caballo" << endl;
            if (es_blanca(i))
                cout << "es blanca" << endl;
            else
                cout << "es negra" << endl;
            return i;
        }
            
    }
    return numero_p;
  
}

void listapiezas::destruir(int i)
{
    if (y_fuera > 8)
    {
        x_fuera = 12;
        y_fuera = 1;
    }
    lista_piezas[i]->posicion.x=x_fuera;
    lista_piezas[i]->posicion.y = y_fuera;
    y_fuera++;
}

bool listapiezas::es_blanca(int i)
{
    if (lista_piezas[i]->color == 255)
        return true;
    else
        return false;
  
}

bool listapiezas::validar_peon(Vector2D a,int i)
{
    if (lista_piezas[i]->color == 255)//es blanca
    {
        if (a.x - lista_piezas[i]->posicion.x == 0)//que no se mueva en la X
        {
            int dist = a.y - lista_piezas[i]->posicion.y;//vemos cuanto se mueve

            if (dist < 3 && lista_piezas[i]->posicion.y == 2)//se comprueba si es primer movimiento con posicion
                return true;
            else if (dist == 1)
                return true;
            else
                return false;
        }
        else
            return false;

        
    }
    else if (lista_piezas[i]->color == 0)//es negra
    {
        if (a.x - lista_piezas[i]->posicion.x == 0)//que no se mueva en la X
        {
            int dist = lista_piezas[i]->posicion.y-a.y;//vemos cuanto se mueve
            if (dist < 3 && lista_piezas[i]->posicion.y == 7)
                return true;
            else if (dist == 1)
                return true;
            else
                return false;
        }
        else
            return false;
    }
}

bool listapiezas::validar_torre(Vector2D a, int i)
{
    if (lista_piezas[i]->posicion.x-a.x!=0)//se mueve en eje X
    {
        if (lista_piezas[i]->posicion.y - a.y != 0)
        {
            return false;
        }
        else return true;
    }
    else if (lista_piezas[i]->posicion.y - a.y != 0)//se mueve en eje y
    {
        if (lista_piezas[i]->posicion.x - a.x != 0)
        {
            return false;
        }
        else return true;
    }

   
}

bool listapiezas::validar_alfil(Vector2D a, int i)
{
    if (abs(lista_piezas[i]->posicion.x - a.x) == abs(lista_piezas[i]->posicion.y - a.y))
        return true;
    else return false;
}

bool listapiezas::validar_rey(Vector2D a, int i)
{
    if (abs(lista_piezas[i]->posicion.x - a.x) < 2 && abs(lista_piezas[i]->posicion.y - a.y) < 2)
        return true;
    else
        return false;
}

bool listapiezas::validar_reina(Vector2D, int)
{
    return false;
}

bool listapiezas::validar_caballo(Vector2D a, int i)//esto lo hizo pedro
{
    int distx = abs(a.x - lista_piezas[i]->posicion.x);
    int disty = abs(a.y - lista_piezas[i]->posicion.y);
    if ((distx > 0 && distx < 3) && (disty > 0 && disty < 3) && (distx == 2*disty || disty == 2*distx))
        return true;
    else
        return false;
}


