//
// Created by Paola on 14/10/2021.
//

#include <iostream>
#include <array>
#include "Punto.h"
#include <math.h>

Punto2D::Punto2D() {

}

float Punto2D::GetX() {
    return x;
}

float Punto2D::GetY() {
    return y;
}

void Punto2D::SetPosicion(float x_, float y_){
    x = x_;
    y = y_;
}

void Punto2D:: Trasladar(float tx, float ty){
    x += tx;
    y += ty;
}

void Punto2D:: RotarRespectoAlOrigen(float a){
    a *= 3.14159/ 180.0;
    float xp;
    xp = x * cos (a) -  y * sin(a);
    y = x * sin(a) + y * cos(a);
    x = xp;
}
void Punto2D:: Escalar(float ex, float ey){
    x *= ex;
    y *= ey;
}