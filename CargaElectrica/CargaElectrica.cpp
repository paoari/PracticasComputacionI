#include <iostream>
#include <array>
#include <string>

// Incluimos nuestra clase Grupo
#include "Grupo.h"

using namespace std;

// Declaración de funciones
void PedirpH(float &ph);
Grupo CrearGrupo(int numGrupo);

template <typename grupos>
int CalcularCargaApH(float &ph, grupos todosGrupos);

int main()
{
	// Indicamos el número de grupos que va a tener nuestra molécula
	const int numGrupos = 3;
	float phMolecula; // pH al que va a estar sometida la molécula
	string nombreMolecula;

	// Pedimos al usuario el nombre de la molécula
	cout << "Nombre de la molecula: ";
	cin >> nombreMolecula;

	// Creamos un arreglo de 'Grupos' para los grupos de la molécula
	array<Grupo, numGrupos> todosGrupos;
	// Pedimos información de cada grupo al usuario
	for (int i = 0; i < numGrupos; i++)
		todosGrupos[i] = CrearGrupo(i);

	// Pedimos al usuario indicar el pH al que está la molécula
	PedirpH(phMolecula);

	// Calculamos la carga neta de la molécula a un cierto pH
	int cargaMolecula = CalcularCargaApH(phMolecula, todosGrupos);
	cout << "Carga neta de la molecula: " << cargaMolecula << endl;

	// Si terminamos correctamente la ejecución del programa, regresamos 0
	return 0;
}

// Crea un nuevo 'Grupo' con la información ingresada por el usuario
Grupo CrearGrupo(int i)
{
	string nombreGrupo;
	float pkGrupo;
	int cargaGrupo;
	cout << "Nombre grupo " << i << ": ";
	cin >> nombreGrupo;
	cout << "pK del grupo " << nombreGrupo << ": ";
	cin >> pkGrupo;
	cout << "Carga del grupo " << nombreGrupo << " a pH mayor a " << pkGrupo << ": ";
	cin >> cargaGrupo;
	Grupo miGrupo(nombreGrupo, pkGrupo, cargaGrupo);
	return miGrupo;
}

// Solicita al usuario el valor de pH
void PedirpH(float &ph)
{
	cout << "pH de la solucion (buffer): ";
	cin >> ph;
}

/* Calcula y regresa la carga eléctrica de la molécula dependiendo de la
 * carga eléctrica de cada uno de sus grupos a un cierto pH.
*/
template <typename grupos>
int CalcularCargaApH(float &ph, grupos todosGrupos)
{
	int CargaMol = 0;
	float infoGrupos[3][2] = {0};
	/*
    infoGrupos[0][0]=todosGrupos[0].getpk();
    infoGrupos[0][1]=todosGrupos[0].getcarga();
    infoGrupos[1][0]=todosGrupos[1].getpk();
    infoGrupos[1][1]=todosGrupos[1].getcarga();
    infoGrupos[2][0]=todosGrupos[2].getpk();
    infoGrupos[2][1]=todosGrupos[2].getcarga();
    if(ph<=infoGrupos[0][0]){CargaMol=CargaMol+infoGrupos[0][1]+1;}
    if(ph<=infoGrupos[1][0]){CargaMol=CargaMol+infoGrupos[1][1]+1;}
    if(ph<=infoGrupos[2][0]){CargaMol=CargaMol+infoGrupos[2][1]+1;}
    if(ph>infoGrupos[0][0]){CargaMol=CargaMol+infoGrupos[0][1];}
    if(ph>infoGrupos[1][0]){CargaMol=CargaMol+infoGrupos[1][1];}
    if(ph>infoGrupos[2][0]){CargaMol=CargaMol+infoGrupos[2][1];}
*/

	for (int i = 0; i < 3; i++)
	{
		infoGrupos[i][0] = todosGrupos[i].getpk();
		infoGrupos[i][1] = todosGrupos[i].getcarga();

		if (ph <= infoGrupos[i][0])
		{
			CargaMol = CargaMol + infoGrupos[i][1] + 1;
		}
		if (ph > infoGrupos[i][0])
		{
			CargaMol = CargaMol + infoGrupos[i][1];
		}
	}
	return CargaMol;
}