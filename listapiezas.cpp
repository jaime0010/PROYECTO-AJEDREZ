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

bool listapiezas::agregar(Pieza* p)
{
    if (numero_p >= MAX_PIEZAS)// Si nuestro lista esta llena, ya no puede devolver mas
        return false;

    lista_piezas[numero_p] = p;
    numero_p++;
    return true;
}

void listapiezas::dibuja()
{
    for (int i = 0; i < numero_p; i++)
    {
        lista_piezas[i]->dibuja();
    }
}

void listapiezas::mover(int h)
{
    bool val = false;
    Vector2D a;
    cout<<"donde la quieres mover "<< endl;  cin >> a.x >> a.y;

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
            val=validar_reina(a,h);
        if (h > 27 && h < 30)//28, y 29
            val = validar_caballo(a, h);



        int k = donde_esta(a);
        bool j, w;
        if (val && k < numero_p)
        {
            destruir(k);
            lista_piezas[h]->posicion.x = a.x;
            lista_piezas[h]->posicion.y = a.y;
        }
        else if (val && k == numero_p)//si no detecta que hay alguna pieza, tambien mueve
        {
            lista_piezas[h]->posicion.x = a.x;
            lista_piezas[h]->posicion.y = a.y;
        }
        else
            cout << "movimineto invalido" << endl;
        bool jk_n = jaque_negro();
        bool jk_b = jaque_blanco();
        if (jk_n)
        {
            cout <<endl<< "estas en jake, mueve el rey negro";
            if (jaquemate_negro())
                cout <<endl<< "HAS PERDIDO NEGRO";
        }
        if (jk_b)
        {
            cout << endl << "estas en jake, mueve el rey blancoo"<<endl;
            if (jaquemate_blanco())
                cout << endl << "HAS PERDIDO BLANCO"<<endl;
        }
            

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
    if (es_blanca(i))
    {
        if (y_fuera_blanca > 8)
        {
            x_fuera_blanca = 12;
            y_fuera_blanca = 1;
        }


        lista_piezas[i]->posicion.x = x_fuera_blanca;
        lista_piezas[i]->posicion.y = y_fuera_blanca;
        y_fuera_blanca++;
    }
    else
    {
        if (y_fuera_negra > 8)
        {
            x_fuera_negra = -3.5;
            y_fuera_negra = 1;
        }


        lista_piezas[i]->posicion.x = x_fuera_negra;
        lista_piezas[i]->posicion.y = y_fuera_negra;
        y_fuera_negra++;
    }
}

bool listapiezas::es_blanca(int i)
{
    if (lista_piezas[i]->color == 255)
        return true;
    else
        return false;

}

//YA ESTÁ IMPLEMENTADA PARA JAQUE
bool listapiezas::validar_peon(Vector2D a, int i)
{
    int distx = a.x - lista_piezas[i]->posicion.x;
    int disty = a.y - lista_piezas[i]->posicion.y;

    //Peones blancos
    if (lista_piezas[i]->color == 255)
    {
        //Avance 2 vertical (solo primer movimiento)
        if (distx == 0 && disty == 2 && lista_piezas[i]->posicion.y == 2)
        {
            //El peón NO puede comer hacia adelante.
            for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
            {
                if ((lista_piezas[j]->posicion.y == a.y - 1 || lista_piezas[j]->posicion.y == a.y) && lista_piezas[j]->posicion.x == a.x)
                    return false; //Si hay alguna pieza en la posicion final o intermedia, NO valida el movimiento.
            }
        }
        //Avance 1 vertical
        else if (distx == 0 && disty == 1)
        {
            //El peón NO puede comer hacia adelante.
            for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
            {
                if (lista_piezas[j]->posicion.y == a.y && lista_piezas[j]->posicion.x == a.x)
                    return false; //Si hay alguna pieza en la posición final, NO valida el movimiento.
            }
            return true;
        }
        //Movimiento diagonal hacia adelante (+1 si hacia la derecha, -1 si a la izquierda).
        else if ((distx == 1 || distx == -1) && disty == 1)
        {
            //Solo puede moverse en diagonal si es para comerse a otra pieza.
            for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
            {
                if (lista_piezas[j]->posicion.y == a.y && lista_piezas[j]->posicion.x == a.x && !es_blanca(j))
                    return true; //Si hay alguna pieza en la posición de destino, SÍ valida el movimiento.
            }
            return false;
        }
        else
            return false;
    }
    //Peones negros
    else if (lista_piezas[i]->color == 0)
    {
        //Avance 2 vertical (solo primer movimiento)
        if (distx == 0 && disty == -2 && lista_piezas[i]->posicion.y == 7)
        {
            //El peón NO puede comer hacia adelante.
            for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
            {
                if ((lista_piezas[j]->posicion.y == a.y + 1 || lista_piezas[j]->posicion.y == a.y) && lista_piezas[j]->posicion.x == a.x)
                    return false; //Si hay alguna pieza en la posicion final o intermedia, NO valida el movimiento.
            }
        }
        //Avance 1 vertical
        else if (distx == 0 && disty == -1)
        {
            //El peón NO puede comer hacia adelante.
            for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
            {
                if (lista_piezas[j]->posicion.y == a.y && lista_piezas[j]->posicion.x == a.x)
                    return false; //Si hay alguna pieza en la posición final, NO valida el movimiento.
            }
            return true;
        }
        //Movimiento diagonal hacia adelante (+1 si hacia la derecha, -1 si a la izquierda).
        else if ((distx == 1 || distx == -1) && disty == -1)
        {
            //Solo puede moverse en diagonal si es para comerse a otra pieza.
            for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
            {
                if (lista_piezas[j]->posicion.y == a.y && lista_piezas[j]->posicion.x == a.x && es_blanca(j))
                    return true; //Si hay alguna pieza en la posición de destino, SÍ valida el movimiento.
            }
            return false;
        }
        else
            return false;
    }
}

//YA ESTARÍA IMPLEMENTADA PARA JAQUE
bool listapiezas::validar_torre(Vector2D a, int i)
{
    int distx = a.x - lista_piezas[i]->posicion.x;
    int disty = a.y - lista_piezas[i]->posicion.y;

    //Movimiento vertical hacia arriba (positivo). Por ejemplo: Desde (1,1) hasta (1,5)
    if (disty > 0)
    {
        if (distx != 0)
        {
            return false;
        }
        else
        {
            for (int posy = 1; posy <= disty; posy++) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_y = lista_piezas[i]->posicion.y + posy; //Responde a la pregunta: ¿A qué coordenada corresponde posy?

                for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
                {
                    //Importante: la coordenda x se mantiene constante en este tipo de movimiento (al ser una torre)
                    if (lista_piezas[j]->posicion.y == coordenada_y && lista_piezas[j]->posicion.x == a.x)
                    {
                        if ((posy == disty) && (lista_piezas[j]->color != lista_piezas[i]->color))
                            return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                        else
                            return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                    }
                }
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }
    //Movimiento horizontal hacia la derecha (positivo). Por ejemplo: Desde (1,3) hasta (5,3)
    else if (distx > 0)
    {
        if (disty != 0)
        {
            return false;
        }
        else
        {
            for (int posx = 1; posx <= distx; posx++) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_x = lista_piezas[i]->posicion.x + posx; //Responde a la pregunta: ¿A qué cootrdenada corresponde posy?

                for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
                {
                    //Importante: la coordenda y se mantiene constante en este tipo de movimiento (al ser una torre)
                    if (lista_piezas[j]->posicion.x == coordenada_x && lista_piezas[j]->posicion.y == a.y)
                    {
                        if ((posx == distx) && (lista_piezas[j]->color != lista_piezas[i]->color))
                            return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                        else
                            return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                    }
                }
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }
    //Movimiento vertical hacia abajo (negativo). Por ejemplo: Desde (1,5) hasta (1,1)
    else if (disty < 0)
    {
        if (distx != 0)
        {
            return false;
        }
        else
        {
            for (int posy = -1; posy >= disty; posy--) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_y = lista_piezas[i]->posicion.y + posy; //Responde a la pregunta: ¿A qué cootrdenada corresponde posy?

                for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
                {
                    //Importante: la coordenda x se mantiene constante en este tipo de movimiento (al ser una torre)
                    if (lista_piezas[j]->posicion.y == coordenada_y && lista_piezas[j]->posicion.x == a.x)
                    {
                        if ((posy == disty) && (lista_piezas[j]->color != lista_piezas[i]->color))
                            return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                        else
                            return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                    }
                }
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }
    //Movimiento horizontal hacia la izquierda (negativo). Por ejemplo: Desde (5,3) hasta (1,3)
    else if (distx < 0)
    {
        if (disty != 0)
        {
            return false;
        }
        else
        {
            for (int posx = -1; posx >= distx; posx--) //Itera tantas veces como huecos hay entre inicio y destino
            {
                int coordenada_x = lista_piezas[i]->posicion.x + posx; //Responde a la pregunta: ¿A qué cootrdenada corresponde posy?

                for (int j = 0; j < numero_p; j++) //Recorremos todo el array de las piezas
                {
                    //Importante: la coordenda x se mantiene constante en este tipo de movimiento (al ser una torre)
                    if (lista_piezas[j]->posicion.x == coordenada_x && lista_piezas[j]->posicion.y == a.y)
                    {
                        if ((posx == distx) && (lista_piezas[j]->color != lista_piezas[i]->color))
                            return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                        else
                            return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                    }
                }
            }
            return true; //Si es correcto, SÍ valida el movimiento.
        }
    }

}

//YA ESTARÍA IMPLEMENTADA PARA JAQUE
bool listapiezas::validar_alfil(Vector2D a, int i)
{

    int distx = a.x - lista_piezas[i]->posicion.x;
    int disty = a.y - lista_piezas[i]->posicion.y;

    if (abs(distx) == abs(disty))
    {
        //Movimiento en el primer cuadrante (X hacia la derecha, Y hacia arriba)
        if (distx > 0 && disty > 0)
        {
            for (int posx = 1; posx <= distx; posx++)
            {
                for (int posy = 1; posy <= disty; posy++)
                {
                    if (abs(posx) == abs(posy))
                    {
                        int coordenada_x = lista_piezas[i]->posicion.x + posx;
                        int coordenada_y = lista_piezas[i]->posicion.y + posy;
                        for (int j = 0; j < numero_p; j++) //Recorremos TODAS las piezas
                        {
                            if (lista_piezas[j]->posicion.x == coordenada_x && lista_piezas[j]->posicion.y == coordenada_y)
                            {
                                if ((posx == distx) && (posy == disty) && (lista_piezas[j]->color != lista_piezas[i]->color))
                                    return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                                else
                                    return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                            }
                        }
                    }
                }
            }
            return true;
        }
        //Movimiento en el segundo cuadrante (X hacia la iquierda, Y hacia arriba)
        else if (distx < 0 && disty > 0)
        {
            for (int posx = -1; posx >= distx; posx--)
            {
                for (int posy = 1; posy <= disty; posy++)
                {
                    if (abs(posx) == abs(posy))
                    {
                        int coordenada_x = lista_piezas[i]->posicion.x + posx;
                        int coordenada_y = lista_piezas[i]->posicion.y + posy;
                        for (int j = 0; j < numero_p; j++) //Recorremos TODAS las piezas
                        {
                            if (lista_piezas[j]->posicion.x == coordenada_x && lista_piezas[j]->posicion.y == coordenada_y)
                            {
                                if ((posx == distx) && (posy == disty) && (lista_piezas[j]->color != lista_piezas[i]->color))
                                    return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                                else
                                    return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                            }
                        }
                    }
                }
            }
            return true;
        }
        //Movimiento en el tercer cuadrante (X hacia la izquierda, Y hacia abajo)
        else if (distx < 0 && disty < 0)
        {
            for (int posx = -1; posx >= distx; posx--)
            {
                for (int posy = -1; posy >= disty; posy--)
                {
                    if (abs(posx) == abs(posy))
                    {
                        int coordenada_x = lista_piezas[i]->posicion.x + posx;
                        int coordenada_y = lista_piezas[i]->posicion.y + posy;
                        for (int j = 0; j < numero_p; j++) //Recorremos TODAS las piezas
                        {
                            if (lista_piezas[j]->posicion.x == coordenada_x && lista_piezas[j]->posicion.y == coordenada_y)
                            {
                                if ((posx == distx) && (posy == disty) && (lista_piezas[j]->color != lista_piezas[i]->color))
                                    return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                                else
                                    return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                            }
                        }
                    }
                }
            }
            return true;
        }
        //Movimiento en el cuarto cuadrante (X hacia la derecha, Y hacia abajo)
        else if (distx > 0 && disty < 0)
        {
            for (int posx = 1; posx <= distx; posx++)
            {
                for (int posy = -1; posy >= disty; posy--)
                {
                    if (abs(posx) == abs(posy))
                    {
                        int coordenada_x = lista_piezas[i]->posicion.x + posx;
                        int coordenada_y = lista_piezas[i]->posicion.y + posy;
                        for (int j = 0; j < numero_p; j++) //Recorremos TODAS las piezas
                        {
                            if (lista_piezas[j]->posicion.x == coordenada_x && lista_piezas[j]->posicion.y == coordenada_y)
                            {
                                if ((posx == distx) && (posy == disty) && (lista_piezas[j]->color != lista_piezas[i]->color))
                                    return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                                else
                                    return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
                            }
                        }
                    }
                }
            }
            return true;
        }
    }
    else
        return false;
}

bool listapiezas::validar_rey(Vector2D a, int i)
{
    if (abs(lista_piezas[i]->posicion.x - a.x) < 2 && abs(lista_piezas[i]->posicion.y - a.y) < 2)
    {
        for (int j = 0; j < numero_p; j++) //Recorremos TODAS las piezas
        {
            if (lista_piezas[j]->posicion.x == a.x && lista_piezas[j]->posicion.y == a.y)
            {
                if ((lista_piezas[j]->color != lista_piezas[i]->color))
                    return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                else
                    return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
            }
        }
        return true;
    }
    else
        return false;
}

bool listapiezas::validar_reina(Vector2D a, int i)
{
    if (validar_alfil(a, i))
        return true;
    else if (validar_torre(a, i))
        return true;
    else
        return false;
}

bool listapiezas::validar_caballo(Vector2D a, int i)
{
    int distx = abs(a.x - lista_piezas[i]->posicion.x);
    int disty = abs(a.y - lista_piezas[i]->posicion.y);


    if ((distx > 0 && distx < 3) && (disty > 0 && disty < 3) && (distx == 2 * disty || disty == 2 * distx))
    {
        for (int j = 0; j < numero_p; j++) //Recorremos TODAS las piezas
        {
            if (lista_piezas[j]->posicion.x == a.x && lista_piezas[j]->posicion.y == a.y)
            {
                if ((lista_piezas[j]->color != lista_piezas[i]->color))
                    return true; //Si en la posicion final hay una pieza de distinto color, nos la podemos comer
                else
                    return false; //Si hay una pieza en una de las posiciones intermedias, NO nos podemos mover.
            }
        }
        return true;
    }
    else
        return false;
}

bool listapiezas::jaque_negro() //i=25 es rey negro
{
    bool p, a, t, c, reina, rey;
   
    int i,ocupada=0;
    for (i = 0; i < 32; i+=2)//se comprueba si alguna pieza se puede mover a la posicion del rey
    {
        p = a = t = c = reina = rey = false;
        if (i < 16)//0 a 15 es un peon
            p = validar_peon(lista_piezas[25]->posicion, i);
        if (i > 15 && i < 20)// 16 a 19 es una torre
            t = validar_torre(lista_piezas[25]->posicion, i);
        if (i > 19 && i < 24)//20 a 23 es un alfil
            a = validar_alfil(lista_piezas[25]->posicion, i);
        if (i==24)//24 y 25 son los reyes
            rey = validar_rey(lista_piezas[25]->posicion, i);
        if (i > 25 && i < 28)//26 y 27 son las reinas
            reina = validar_reina(lista_piezas[25]->posicion, i);
        if (i > 27 && i < 32)//28, y 29
            c = validar_caballo(lista_piezas[25]->posicion, i);
        if (p || a || t || c || reina || rey)
            ocupada++;
    }
    if (ocupada>0)
        return true;
    else return false;
}

bool listapiezas::jaquemate_negro()//i=25 es rey negro
{
    int i, j,k,tocado=0,casilla=0;
    bool p, al, t, c, reina, rey;
    Vector2D a;

    int reysi=0, piezasi=0;

    for (i = -1; i <= 1; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            a.x = lista_piezas[25]->posicion.x + i; 
            a.y=lista_piezas[25]->posicion.y + j;//generamos las posiciones
            if (a.x > 0 && a.x < 9 && a.y>0 && a.y < 9)
            {


                if (validar_rey(a, 25))//si el rey puede ir a alguna de las casillas de alrededor
                {
                    casilla = 0;
                    reysi++;
                    for (k = 0; k < 32; k += 2)//se comprueba si alguna pieza se puede mover a las casillas que puede el rey
                    {
                        p = al = t = c = reina = rey = false;

                        if (k < 16)//0 a 15 es un peon
                            p = validar_peon(a, k);
                        if (k > 15 && k < 20)// 16 a 19 es una torre
                            t = validar_torre(a, k);
                        if (k > 19 && k < 24)//20 a 23 es un alfil
                            al = validar_alfil(a, k);
                        if (k == 24)//24 y 25 son los reyes
                            rey = validar_rey(a, k);
                        if (k > 25 && k < 28)//26 y 27 son las reinas
                            if (validar_alfil(a, k) || validar_torre(a, k))
                                reina = true;
                        if (k > 27 && k < 32)//28 a 31
                            c = validar_caballo(a, k);
                        if (p || al || t || c || reina || rey)
                            casilla++;
                    }
                    if (casilla > 0)
                        piezasi++;
                }
            }
        }
    }
    if (reysi==piezasi)//no se puede mover a ningun sitio.
        return true;
    else
        return false;
}

bool listapiezas::jaque_blanco()// i=24 es rey blanco
{
    bool p, a, t, c, reina, rey;

    int i, ocupada = 0;
    for (i = 1; i < 32; i += 2)//se comprueba si alguna pieza se puede mover a la posicion del rey
    {
        p = a = t = c = reina = rey = false;
        if (i < 16)//0 a 15 es un peon
            p = validar_peon(lista_piezas[24]->posicion, i);
        if (i > 15 && i < 20)// 16 a 19 es una torre
            t = validar_torre(lista_piezas[24]->posicion, i);
        if (i > 19 && i < 24)//20 a 23 es un alfil
            a = validar_alfil(lista_piezas[24]->posicion, i);
        if (i == 25)//24(blanco) y 25(negro) son los reyes
            rey = validar_rey(lista_piezas[24]->posicion, i);
        if (i > 25 && i < 28)//26 y 27 son las reinas
            reina =validar_reina(lista_piezas[24]->posicion, i);
        if (i > 27 && i < 32)//28, y 29
            c = validar_caballo(lista_piezas[24]->posicion, i);
        if (p || a || t || c || reina || rey)
            ocupada++;
    }
    if (ocupada > 0)
        return true;
    else return false;
}

bool listapiezas::jaquemate_blanco()
{
    int i, j, k, tocado = 0, casilla = 0;
    bool p, al, t, c, reina, rey;
    Vector2D a;

    int reysi = 0, piezasi = 0;

    for (i = -1; i <= 1; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            a.x = lista_piezas[24]->posicion.x + i;
            a.y = lista_piezas[24]->posicion.y + j;//generamos las posiciones
            if (a.x > 0 && a.x < 9 && a.y>0 && a.y < 9)
            {


                if (validar_rey(a, 24))//si el rey puede ir a alguna de las casillas de alrededor
                {
                    casilla = 0;
                    reysi++;
                    for (k = 1; k < 32; k += 2)//se comprueba si alguna pieza se puede mover a las casillas que puede el rey
                    {
                        p = al = t = c = reina = rey = false;

                        if (k < 16)//0 a 15 es un peon
                            p = validar_peon(a, k);
                        if (k > 15 && k < 20)// 16 a 19 es una torre
                            t = validar_torre(a, k);
                        if (k > 19 && k < 24)//20 a 23 es un alfil
                            al = validar_alfil(a, k);
                        if (k == 25)//24 y 25 son los reyes
                            rey = validar_rey(a, k);
                        if (k > 25 && k < 28)//26 y 27 son las reinas
                            if (validar_alfil(a, k) || validar_torre(a, k))
                                reina = true;
                        if (k > 27 && k < 32)//28 a 31
                            c = validar_caballo(a, k);
                        if (p || al || t || c || reina || rey)
                            casilla++;
                    }
                    if (casilla > 0)
                        piezasi++;
                }
            }
        }
    }
    if (reysi == piezasi)//no se puede mover a ningun sitio.
        return true;
    else
        return false;
}
