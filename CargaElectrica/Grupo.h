#ifndef CARGAELECTRICA_GRUPO_H
#define CARGAELECTRICA_GRUPO_H

#include <string>

using namespace std;

class Grupo
{
private:
	string nombreGrupo;
	float pkGrupo;
	int cargaGrupo;

public:
	Grupo()
	{
		nombreGrupo = "";
		pkGrupo = 0;
		cargaGrupo = 0;
	}
	Grupo(string nom, float pk, int carga);

	float getpk() const;
	int getcarga() const;
};

#endif //CARGAELECTRICA_GRUPO_H