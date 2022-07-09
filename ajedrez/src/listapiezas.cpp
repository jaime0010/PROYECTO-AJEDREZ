#include "listapiezas.h"
#include<iostream>
#include "freeglut.h"

//Las ponemos aquí porque en el .h no son realmente necesarias
//No son necesarias en la declaración de los métodos de ListaPiezas, pero sí en su definición. 
#include "peon.h"
#include "Torre.h"
#include "Alfil.h"
#include "Rey.h"
#include "Reina.h"
#include "Caballo.h"

using namespace std;

ListaPiezas::ListaPiezas()
{
    for (int i = 0; i < MAX_PIEZAS; i++)
    {
        lista_piezas[i] = NULL;// ponerlo a null
    }
}

bool ListaPiezas::agregar(Pieza* p)
{
    if (numero_p >= MAX_PIEZAS)// Si nuestro lista esta llena, ya no puede devolver mas
        return false;

    lista_piezas[numero_p] = p;
    numero_p++;
    return true;
}

void ListaPiezas::dibuja() //Nos dibuja cada pieza concreta en su sitio del tablero. La llamamos desde tablero al dibujarse este.
{
    for (int i = 0; i < numero_p; i++)
    {
        lista_piezas[i]->dibuja();
    }
}

//Obtenr una pieza en funcion de su posicion en la lista
Pieza* ListaPiezas::obtener(int h)
{
    return lista_piezas[h];
}

void ListaPiezas::mover(int h)
{
    Vector2D a;
    cout << "donde la quieres mover " << endl;  cin >> a.x >> a.y;
    //El usuario introduce la posición de destino

    if (a.x <= 0 || a.x >= 9 || a.y <= 0 || a.y >= 9) //Si la coordenada de la pieza de destino no existe, no valida.
    {
        return;
    }
    Pieza* pieza = obtener(h); //Obtengo la pieza que hay en esa posicion del array
    if (pieza == NULL)
    {
        return;
    }

    //Se revisa si se puede mover la pieza a través de su método validar_movimiento
    if (pieza->validar_movimiento(a, this))
    {
        int k = donde_esta(a);
        if (k < numero_p)//Si hay una pieza donde nos queremos mover, emite sonido y se come a la pieza
        {
            ETSIDI::play("sonidos/comer.wav"); //Sonido
            destruir(k); //Comer pieza
        }
        pieza->posicion = a; //Mueve la pieza a la posición final
    }
    else
        cout << "¡Movimiento no valido!\n" << endl;



    int i = 0;
    int m, n, suma1 = 0, suma2 = 0, tocado = 0;

    Vector2D posible;
    for (i = 1; i < 32; i += 2)//se comprueba si alguna pieza negra se puede mover a la posicion del rey
    {
        bool jq_b = jaque_total(lista_piezas[24]->posicion, lista_piezas[i]);//usamos la poscion del rey blanco(24) y las distintas piezas negras
        if (jq_b)
        {
            cout << "¡Estas en jaque! Mueve el rey blanco.\n" << endl;
            for (i = 1; i < 32; i += 2)
            {
                if (jaque_mate_total(lista_piezas[24], lista_piezas[i]))
                {
                    ETSIDI::play("sonidos/game_over.mp3");
                    cout << endl << "¡Ha ganado el jugador NEGRO!\n";
                    exit(1);
                }
            }
        }
    }
    for (i = 0; i < 32; i += 2)//se comprueba si alguna pieza blanca se puede mover a la posicion del rey
    {
        bool jq_n = jaque_total(lista_piezas[25]->posicion, lista_piezas[i]);//usamos la poscion del rey negro(25) y las distintas piezas blancas
        if (jq_n)
        {
            cout << "¡Estas en jaque! Mueve el rey negro.\n" << endl;
            for (i = 0; i < 32; i += 2)
            {
                if (jaque_mate_total(lista_piezas[25], lista_piezas[i]))
                {
                    ETSIDI::play("sonidos/game_over.mp3");
                    cout << endl << "¡Ha ganado el jugador BLANCO!\n";
                    exit(1);
                }
            }
        }
    }
}

//Obtener posicion en la lista a partir de coordenadas
int ListaPiezas::donde_esta(Vector2D a)
{
    for (int i = 0; i < numero_p; i++)
    {
        Vector2D posicion = lista_piezas[i]->posicion;
        if (posicion == a) //Revisamos la posicion de todas las piezas
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

//Para obtener una pieza de la lista a partir de unas coordenadas
Pieza* ListaPiezas::obtener(Vector2D a)
{
    for (int i = 0; i < numero_p; i++)
    {
        Vector2D posicion = lista_piezas[i]->posicion;
        if (posicion == a) //Revisamos la posicion de todas las piezas
        {
            return (obtener(i));
        }
    }
    return NULL;
}

//Detectar si en determinadas coordenadas hay una pieza
bool ListaPiezas::hay_pieza(Vector2D a)
{
    for (int i = 0; i < numero_p; i++)
    {
        Vector2D posicion = lista_piezas[i]->posicion;
        if (posicion == a) //Revisamos la posición de todas las piezas
        {
            return true;
        }
    }
    return false;
}

void ListaPiezas::destruir(int i)
{
    if (es_blanca(i))
    {
        if (y_fuera_blanca > 8)
        {
            x_fuera_blanca = 12;
            y_fuera_blanca = 1;
        }
        Vector2D fuera_blanca = Vector2D(x_fuera_blanca, y_fuera_blanca);
        lista_piezas[i]->posicion = fuera_blanca;
        y_fuera_blanca++;
    }
    else
    {
        if (y_fuera_negra > 8)
        {
            x_fuera_negra = -3.5;
            y_fuera_negra = 1;
        }
        Vector2D fuera_negra = Vector2D(x_fuera_negra, y_fuera_negra);
        lista_piezas[i]->posicion = fuera_negra;
        y_fuera_negra++;
    }
}

bool ListaPiezas::es_blanca(int i)
{
    if (lista_piezas[i]->blanca == true)
        return true;
    else
        return false;

}

//Implementados en la propia pieza: peon, torre, alfil, rey, reina, caballo
//NO borramos estos porque sino NO funciona jaque

bool ListaPiezas::jaque_total(Vector2D pos, Pieza* pieza)
{
    return (pieza->validar_movimiento(pos, this));
}

bool ListaPiezas::jaque_mate_total(Pieza* rey, Pieza* pieza)
{
    int i = 0;
    int m, n, suma1 = 0, suma2 = 0, tocado = 0;

    for (m = -1; m <= 1; m++)
    {
        for (n = -1; n <= 1; n++)
        {
            Vector2D mn = Vector2D(m, n);
            Vector2D posible = rey->posicion + mn; //generamos las posiciones posibles a las que se puede mover un rey
            if (posible.x > 0 && posible.x < 9 && posible.y>0 && posible.y < 9)//si la casilla generado esta en el tablero
            {
                if (rey->validar_movimiento(posible, this))//validamos si el rey se puede mover a esa casilla
                {
                    suma1++;
                    if (pieza->validar_movimiento(posible, this))//validamos si la pieza elegida puede ir a esa misma casilla
                        suma2++;
                }
            }
        }
    }
    if (suma1 == suma2)
        return true;
    else
        return false;
}
