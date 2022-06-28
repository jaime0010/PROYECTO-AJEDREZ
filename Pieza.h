#pragma once
#include "Vector2D.h"

//forward declaration
class ListaPiezas;

#include "listapiezas.h"

class Pieza
{
protected:
	bool blanca;
	//Vector2D posicion; //creo que debe ser protected!!!!
public:
	//Atributos
	Vector2D posicion;
	float radio;
	int color;


	//Constructor
	Pieza(Vector2D, float, int);


	//M�todos
	virtual void dibuja() = 0; //M�todo virtual puro -> Pieza == clase abstracta (no instancia concreta)
	//Este es el correcto:
	virtual bool validar_movimiento(Vector2D, ListaPiezas*) = 0; //M�todo virtual puro -> Pieza == clase abstracta (no instancia concreta)
	bool mismo_color(Pieza*);

	//Este incorrecto
	//virtual bool validar_movimiento(Vector2D, Vector2D, Pieza*) = 0;




};