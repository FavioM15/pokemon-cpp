#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

using namespace std;

class Pokemon {
public:
    string nombre;
    string tipo;
    int vida;
    int ataque;
    int defensa;

    Pokemon(string nombre, string tipo, int vida, int ataque, int defensa);

    void mostrar();
    void atacar(Pokemon &objetivo);
    void recibirDano(int dano);
};

#endif