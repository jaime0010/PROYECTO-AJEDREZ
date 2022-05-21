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
    bool val;
        Vector2D a;
        cout << "donde la quieres mover: " << endl;  cin >> a.x >> a.y;
        //se revisa si se puede mover
        if (h < 16)//es un peon
            val=validar_peon(a, h);


        int k=donde_esta(a);
        bool j, w;
        if (val)
        {


            if (k != numero_p)
            {
                j = es_blanca(h);//la que queremos mover
                w = es_blanca(k);//a donde va
                if (j == w)//vemos si son del mismo color
                    cout << "no se puede mover" << endl;
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
            cout << "movimineto invalido"<<endl;
       
}

int listapiezas::donde_esta(Vector2D a)
{
for (int i = 0; i < numero_p; i++)
    {
        if (lista_piezas[i]->posicion.x == a.x && lista_piezas[i]->posicion.y == a.y)//REVISAMOS LA POSCION DE LOS PEONES
        {
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
        x_fuera = 10;
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



