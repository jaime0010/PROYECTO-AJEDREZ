#include "CoordinadorPang.h"

CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
}
CoordinadorPang::~CoordinadorPang()
{

}



void CoordinadorPang::mueve()
{
	if (estado == EMPEZAR)
		tab.esta_ocupada(tab.preguntar());
}

void CoordinadorPang::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("Bitwise.ttf", 50);
		ETSIDI::printxy("AJEDREZ", -5, 20);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("Bitwise.ttf", 20);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -10, 15);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 10);
		ETSIDI::setTextColor(1,1, 1);
		ETSIDI::setFont("Bitwise.ttf", 14);
		ETSIDI::printxy("Realizado por: Victor Alcolea, Jaime Bustos, Pedro de Martino, Felipe de Gracia ", -17, 5);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("Bitwise.ttf", 12);
		ETSIDI::printxy("NOTA:Para usar la consola, pulsar la letra J  ", -7, 13);
	}
	else if (estado == JUEGO)
	{
		tab.dibuja();

	}
	else if (estado == EMPEZAR)
	{
		tab.dibuja();
	}

}
void CoordinadorPang::teclaEspecial(unsigned char key)
{


}
void CoordinadorPang::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			tab.inicializa();
			estado = JUEGO;


		}
		if (key == 's')
			exit(0);

	}
	if (estado == JUEGO)
	{
		if (key == 'j')
		{

			estado = EMPEZAR;
		}
	}


}