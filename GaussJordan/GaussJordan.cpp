#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz &miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz &miMatriz);

template <typename matriz>
void GaussJordan(matriz &miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz &miMatriz);

template <typename matriz>
array<float, 4> Resta(array<float, 4> a, array<float, 4> b);

template <typename matriz>
array<float, 4> Multiplicacion(array<float, 4> a, float multiplo);

template <typename matriz>
void ReordenarFilas(matriz &miMatriz);

int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array<array<float, columnas>, variables> miMatriz = {0};

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/

template <typename matriz>
void LlenarMatriz(matriz &miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++)
    {
        for (int j = 0; j <= variables; j++)
        {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz &miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++)
    {
        cout << "\n[";
        for (int j = 0; j < variables + 1; j++)
        {
            cout << miMatriz[i][j] << "\t";
        }

        cout << "]";
    }
    cout << "\n";
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz &miMatriz)
{
    cout << "\n";
    cout << "Solucion:"
         << "\n";
    cout << "x0"
         << " "
         << "="
         << " " << miMatriz[0][3] << "\n";
    cout << "x1"
         << " "
         << "="
         << " " << miMatriz[1][3] << "\n";
    cout << "x2"
         << " "
         << "="
         << " " << miMatriz[2][3] << "\n";
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/

template <typename matriz>
array<float, 4> Multiplicacion(array<float, 4> a, float multiplo)
{
    for (int i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] * multiplo;
    }
    return a;
}

template <typename matriz>
void GaussJordan(matriz &miMatriz)
{

    ReordenarFilas<matriz>(miMatriz);

    for (int i = 0; i < miMatriz.size(); ++i)
    {
        if (miMatriz[i][i] == 0)
        {
            cout << "\nNo tiene solucion.";
            return;
        }
    }

    for (int i = 0; i < miMatriz.size(); i++)
    {
        miMatriz[i] = Multiplicacion<matriz>(miMatriz[i], 1 / miMatriz[i][i]);
        for (int j = 0; j < miMatriz.size(); j++)
        {
            if (i != j)
            {
                miMatriz[j] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[i], miMatriz[j][i]), miMatriz[j]);
            }
        }
    }
    for (int i = 0; i < miMatriz.size(); i++)
    {
        miMatriz[i] = Multiplicacion<matriz>(miMatriz[i], 1 / miMatriz[i][i]);
    }

    ImprimirSolucion<matriz>(miMatriz);
}

template <typename matriz>
array<float, 4> Resta(array<float, 4> a, array<float, 4> b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] - b[i];
    }
    return a;
}

template <typename matriz>
void ReordenarFilas(matriz &miMatriz)
{
    for (int i = 0; i < miMatriz.size(); i++)
    {
        if (miMatriz[i][i] == 0)
        {
            for (int j = i; j < miMatriz.size(); j++)
            {
                if (miMatriz[j][i] != 0)
                {
                    array<float, 4> temp = miMatriz[i];
                    miMatriz[i] = miMatriz[j];
                    miMatriz[j] = temp;
                };
            }
        }
    }
}
