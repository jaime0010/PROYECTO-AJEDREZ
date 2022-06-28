#pragma once


class Vector2D
{
public:
    //Atributos (coordenadas)
    float x;
    float y;

    //Constructor
    Vector2D(float xv = 0.0f, float yv = 0.0f); //Inicializamos a 0, sino nos da fallo??

    //Sobrecargar operador ==
    bool operator==(Vector2D*);
    //Hay que sobrecargar también el + y el -, y MODIFICAR LOS validar_movimiento
};

