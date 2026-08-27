#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

using namespace std;

class Pokemon {
private:
    string especie;
    string apodo;
    string tipo;
    int vida;
    int ataque;
    int defensa;
    int ataque_esp;
    int defensa_esp;
public:  
    Pokemon(string especie, string tipo, int vida, int ataque, int defensa, int ataque_esp, int defensa_esp, string apodo = "");

    void setNombre(string nombre);
    void mostrar();
    void atacar(Pokemon &objetivo);
    void recibirDano(int dano);
    string getNombre() const;
    string getNombreMostrar() const;


};

#endif