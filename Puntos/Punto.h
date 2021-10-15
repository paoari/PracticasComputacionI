//
// Created by Paola on 14/10/2021.
//

#ifndef PUNTOS_PUNTO_H
#define PUNTOS_PUNTO_H

class Punto2D {
public:
    Punto2D();// Constructor

    //Getters
    float GetX ();
    float GetY ();

    //Metodos
    void SetPosicion(float x_, float y_); // Variables a recibir
    void Trasladar(float tx, float ty);
    void RotarRespectoAlOrigen(float a);
    void Escalar(float ex, float ey);

private:
    float x,y; // Variables de la clase

};

#endif //PUNTOS_PUNTO_H

