#include "tablero.h"

#include "peon.h"
#include "Torre.h"
#include "Alfil.h"
#include "Rey.h"
#include "Reina.h"
#include "Caballo.h"

#include<iostream>
using namespace std;

Tablero::Tablero()
{

}

void Tablero::inicializa()
{
    for (int i = 1; i < 9; i++)//peones 
    {
        Vector2D coloca_blanca = Vector2D(i, 2);
        Vector2D coloca_negra = Vector2D(i, 7);
        Peon* aux = new Peon(coloca_blanca, 0.25, 255);//blancos
        piezas.agregar(aux);//esto lo agregas
        Peon* aux1 = new Peon(coloca_negra, 0.25, 0);//negros
        piezas.agregar(aux1);//esto lo agregas
    }
    for (int i = 1; i < 9; i++)//torres
    {
        if (i == 1 || i == 8)
        {
            Vector2D coloca_blanca = Vector2D(i, 1);
            Vector2D coloca_negra = Vector2D(i, 8);
            Torre* aux = new Torre(coloca_blanca, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Torre* aux1 = new Torre(coloca_negra, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//alfiles
    {
        if (i == 3 || i == 6)
        {
            Vector2D coloca_blanca = Vector2D(i, 1);
            Vector2D coloca_negra = Vector2D(i, 8);
            Alfil* aux = new Alfil(coloca_blanca, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Alfil* aux1 = new Alfil(coloca_negra, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//reyes
    {
        if (i == 5)
        {
            Vector2D coloca_blanca = Vector2D(i, 1);
            Vector2D coloca_negra = Vector2D(i, 8);
            Rey* aux = new Rey(coloca_blanca, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Rey* aux1 = new Rey(coloca_negra, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//reinas
    {
        if (i == 4)
        {
            Vector2D coloca_blanca = Vector2D(i, 1);
            Vector2D coloca_negra = Vector2D(i, 8);
            Reina* aux = new Reina(coloca_blanca, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Reina* aux1 = new Reina(coloca_negra, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
    for (int i = 1; i < 9; i++)//caballos
    {
        if (i == 2 || i == 7)
        {
            Vector2D coloca_blanca = Vector2D(i, 1);
            Vector2D coloca_negra = Vector2D(i, 8);
            Caballo* aux = new Caballo(coloca_blanca, 0.25, 255);//blancas
            piezas.agregar(aux);//esto lo agregas
            Caballo* aux1 = new Caballo(coloca_negra, 0.25, 0);//negras
            piezas.agregar(aux1);//esto lo agregas
        }
    }
}

void Tablero::dibuja() //Dibuja lo que es el tablero en sí (la cuadrícula)
{

    int i, j, r, g, b;
    for (i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            r = 46;//oscuro
            g = 97;
            b = 158;
        }
        else if (i % 2 != 0)
        {
       
            r = 156;//claro
            g = 198;
            b = 249;

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
            if (r == 46)
            {
                r = 156;
                g = 198;
                b = 249;
            }
            else if (r == 156)
            {
                r = 46;
                g = 97;
                b = 158;
            }
        }
    }

    glColor3ub(79, 39, 170);
    glBegin(GL_POLYGON);
    glVertex3f(10.5, 0.5, 0.0f);
    glVertex3f(10.5, 8.5, 0.0f);
    glVertex3f(12.5, 8.5, 0.0f);
    glVertex3f(12.5, 0.5, 0.0f);
    glEnd();

    glColor3ub(79, 39, 170);
    glBegin(GL_POLYGON);

    glVertex3f(-1.5, 0.5, 0.0f);
    glVertex3f(-1.5, 8.5, 0.0f);
    glVertex3f(-3.5, 8.5, 0.0f);
    glVertex3f(-3.5, 0.5, 0.0f);
    glEnd();

    //Llama al método dibuja de listapiezas
    piezas.dibuja();
}

Vector2D Tablero::preguntar() //Marca los turnos, pregunta las coordenadas de la pieza que queremos mover y nos devuelve esas coordenadas.
{
    turno++;
    float k = turno % 2;
    if (k == 0)
        cout << "TURNO BLANCAS, ";
    else
        cout << "TURNO NEGRAS, ";

    Vector2D a;
    cout << "Que pieza quieres mover? " << endl;
    cin >> a.x >> a.y;
    ETSIDI::play("sonidos/impacto.wav");
    return a;
}

void Tablero::esta_ocupada(Vector2D a) //No entiendo muy bien que hace esto
{
    float j = turno % 2;
    int h = piezas.donde_esta(a); //Devuelve la posicion de la pieza con las coordenadas "a" en el array (equivale al hay)

    if (h != MAX_PIEZAS)//la pieza esta ahi, en la 'i' que devuelve
    {
        float k = h % 2;
        if (j == k)//te toca
        {
            cout << "\nHay una pieza " << endl;
            piezas.mover(piezas.donde_esta(a));
        }
        else
            cout << "NO ES TU TURNO" << endl;
    }
}



