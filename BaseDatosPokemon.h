#ifndef BASEDATOSPOKEMON_H
#define BASEDATOSPOKEMON_H

#include <vector>
#include <string>
#include "Pokemon.h"

using namespace std;

class BaseDatosPokemon {
public:
    static vector<Pokemon> obtenerPokemonIniciales();
    static Pokemon obtenerPorEspecie(string especie);
};

#endif