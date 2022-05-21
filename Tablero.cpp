#include "tablero.h"
#include<iostream>
using namespace std;

tablero::tablero()
{

}

void tablero::inicializa()
{
    
    for (int i = 1; i < 9; i++)//peones 

    {
        Peon* aux = new Peon(i, 2, 0.25, 255);//blancos
        piezas.agregar(aux);//esto lo agregas
        Peon* aux1 = new Peon(i, 7, 0.25, 0);//negros
        piezas.agregar(aux1);//esto lo agregas
    }
    for (int i = 1; i <9 ; i++)//torres
    {
        if (i == 1 || i == 8)
        {
            Torre* aux = new Torre(i, 1, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Torre* aux1 = new Torre(i, 8, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//alfiles
    {
        if (i == 3 || i == 6)
        {
            Alfil* aux = new Alfil(i, 1, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Alfil* aux1 = new Alfil(i, 8, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//reyes
    {
        if (i == 5)
        {
            Rey* aux = new Rey(i, 1, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Rey* aux1 = new Rey(i, 8, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//reinas
    {
        if (i == 4)
        {
            Reina* aux = new Reina(i, 1, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Reina* aux1 = new Reina(i, 8, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//caballos
    {
        if (i == 2 || i == 7)
        {
            Caballo* aux = new Caballo(i, 1, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Caballo* aux1 = new Caballo(i, 8, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }

}

void tablero::dibuja()
{

    int i, j, r, g, b;
    for (i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            r = 80;
            g = 7;
            b = 45;

        }

        else if (i % 2 != 0)
        {
            r = 128;
            g = 64;
            b = 0;

        }

        for (j = 0; j < 8; j++)
        {
            glColor3ub(r, g, b);
            glBegin(GL_POLYGON);
            glVertex3f(0.5 + i, 0.5 + j, 0.0f);
            glVertex3f(0.5 + i, 1.5 + j, 0.0f);
            glVertex3f(1.5 + i, 1.5 + j, 0.0f);
            glVertex3f(1.5 + i, 0.5 + j, 0.0f);
            glEnd();
            if (r == 80)
            {
                r = 128;
                g = 64;
                b = 0;
            }

            else if (r == 128)
            {
                r = 80;
                g = 7;
                b = 45;

            }
        }
    }

    glColor3ub(255,0,128);
    glBegin(GL_POLYGON);
    glVertex3f(10.5,0.5 , 0.0f);
    glVertex3f(10.5, 8.5, 0.0f);
    glVertex3f(12.5, 8.5 , 0.0f);
    glVertex3f(12.5 , 0.5 , 0.0f);
    glEnd();


    
    piezas.dibuja();

}

Vector2D tablero::preguntar()
{
    Vector2D a;
    cout << "Que pieza quieres mover? " << endl;
    cin >> a.x >> a.y;
    return a;
}

void tablero::esta_ocupada(Vector2D a)
{
    if (piezas.donde_esta(a) != MAX_PIEZAS)//la pieza esta ahi, en la 'i' que devuelve
    {
        cout << "\nHay una pieza " << endl;
        piezas.mover(piezas.donde_esta(a));
    }

}
