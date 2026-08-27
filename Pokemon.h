#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "Ataque.h"

class Pokemon {
private:
    std::string especie;
    std::string apodo;
    std::string tipo;

    int vida;
    int vidaMaxima;
    int ataque;
    int defensa;
    int ataque_esp;
    int defensa_esp;
    int nivel;

    bool debilitado;

    std::vector<Ataque> ataques;

public:
    Pokemon(
        std::string especie,
        std::string tipo,
        int vida,
        int ataque,
        int defensa,
        int ataque_esp,
        int defensa_esp,
        std::string apodo = ""
    );

    std::string getEspecie() const;
    std::string getApodo() const;
    std::string getNombreMostrar() const;
    std::string getTipo() const;

    int getVida() const;
    int getVidaMaxima() const;
    int getAtaque() const;
    int getDefensa() const;

    bool estaDebilitado() const;

    void setApodo(std::string nuevoApodo);
    void recibirDano(int dano);
    void curar(int cantidad);

    void agregarAtaque(Ataque ataque);
    void mostrarAtaques() const;

    const std::vector<Ataque>& getAtaques() const;

    void mostrar() const;
    void atacar(Pokemon& objetivo, int indiceAtaque);
};

#endif