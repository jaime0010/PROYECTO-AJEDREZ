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
    
        Vector2D a;
        cout << "donde la quieres mover " << endl;  cin >> a.x >> a.y;

        lista_piezas[h]->posicion.x = a.x;
        lista_piezas[h]->posicion.y = a.y;
    
}

int listapiezas::donde_esta(Vector2D a)
{

    for (int i = 0; i < numero_p; i++)
    {
        if (lista_piezas[i]->posicion.x == a.x && lista_piezas[i]->posicion.y == a.y)//REVISAMOS LA POSCION DE LOS PEONES
            return i;
    }
    return numero_p;
  
}
