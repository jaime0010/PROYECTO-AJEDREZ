#pragma once
#include <math.h>
class Vector2D
{
public:
    //Atributos (coordenadas)
    float x;
    float y;

    //Constructor
    Vector2D(float xv = 0.0f, float yv = 0.0f); //Inicializamos a 0, sino nos da fallo??

    //Sobrecarga de operadores
    //Compara dos vectores (es decir, sus componentes) y devuelve el resultado (true si x1==x2 && y1==y2; false si no se cumple alguna)
    bool operator==(Vector2D);
    //Devuelve el vector resultado dela suma/resta de un vector y otro
    Vector2D operator+(Vector2D&);
    Vector2D operator-(Vector2D&);
    //Compara los componentes de un vector con los componentes de un vector limite (true si x1<x2 && y1<y2)
    bool operator<(Vector2D);

    //Otros métodos
    //Método que compara los valores absolutoscomponentes de un vector para ver si son son iguales (true si |x|==|y|)
    bool comp_abs_iguales();
    //Método que devuelve un nuevo vector cuyos componentes son los valores absolutos del vector a través del cual se llama al método.
    Vector2D abs_v();
};
