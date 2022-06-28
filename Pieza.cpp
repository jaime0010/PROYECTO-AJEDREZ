#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza(Vector2D v, float r, int c) //Constructor
{
	posicion.x = v.x;
	posicion.y = v.y;
	radio = r;
	color = c;
	if (color == 255)
		blanca = true;
	else
		blanca = false;
}

//Innecesario al ser virtual puro (=0 en su declaraci�n)
//void Pieza::dibuja()
//{
//
//}

bool Pieza::mismo_color(Pieza* otra)
{
	return (blanca == otra->blanca);
}

//Innecesario al ser virtual puro (=0 en su declaraci�n)
//bool Pieza::validar_movimiento(Vector2D a, ListaPiezas* s)
//{
//	return false;
//}


