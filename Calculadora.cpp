/* Bienvenides a la mejor calculadora del mundo.
 * Creada por: Paola Arias Martínez
 * 15 de septiembre de 2020
 * como se quitan los comentarios
 * ah ya
 */

using namespace std;
#include <iostream>
#include <math.h>

int main() {
    //Primero vamos a declarar las variables a utilizar; tenemos 1 para almacenar el caracter de la operacion a realizar
    // y 2 para los numeros a introducir.

    char op{1};
    float num1{0}, num2{0};
    float div;
    double result;


    //Vamos a escribir el comando para que el usuario indique las operaciones a realizar.

    cout<< "Bienvenidx a la calculadora que probablemente nunca usarias en tu dia a dia"<<endl;
    cout<< "Introduce el primer numero"<<endl;
    cin>> num1;

    cout << "Introduce el operador" << endl;
    cin >> op;

    cout<< "introduce el segundo numero"<<endl;
    cin>> num2;


    //Ahora vamos a establecer los condicionales.
    if (op == '+')
    {
        result = num1 + num2;
    }
    else if (op == '-')
    {
        result = num1 - num2;
    }
    else if (op == '*')
    {
        result = num1 * num2;
    }
    else if ( op == '/')
    {
        result = num1/num2;
    }
    else if (op == '%')
    {
        result = fmod(num1,num2);
    }

    cout << "yaaasss tu resultado es: "<< result <<endl;

    return 0;
}