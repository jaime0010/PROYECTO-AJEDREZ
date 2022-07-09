#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza(Vector2D v, bool b) //Constructor
{
	posicion.x = v.x;
	posicion.y = v.y;
	blanca = b;
}

bool Pieza::mismo_color(Pieza* otra)
{
	return (blanca == otra->blanca);
}

//NOTA: Innecesarios al ser virtuales puros (=0 en su declaración)
//void Pieza::dibuja(){}
//bool Pieza::validar_movimiento(Vector2D a, ListaPiezas* s)

bool Pieza::get_blanca()
{
	return blanca;
}

Vector2D Pieza::get_posicion()
{
	return posicion;
}

void Pieza::set_posicion(Vector2D p_fin)
{
	posicion = p_fin;
}
