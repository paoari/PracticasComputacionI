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
    float result;


    //Vamos a escribir el comando para que el usuario indique las operaciones a realizar.

    cout<< "Este programa hace operaciones basicas entre dos numeros."<<endl;
    cout<< "Primer numero:"<<endl;
    cin>> num1;
    cout << "Operacion:" << endl;
    cin >> op;
    cout<< "Segundo numero:"<<endl;
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

    cout << "Resultado: " <<endl;
    cout << num1 << " " << op  << " " << num2 << "=" << result <<endl;

    return 0;
}
