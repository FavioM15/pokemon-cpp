#include "Ataque.h"

Ataque::Ataque(std::string nombre, std::string tipo, int potencia, int precision) {

    this->nombre = nombre;
    this->tipo = tipo;
    this->potencia = potencia;
    this->precision = precision;
}

std::string Ataque::getNombre() const {
    return nombre;
}

std::string Ataque::getTipo() const {
    return tipo;
}

int Ataque::getPotencia() const {
    return potencia;
}

int Ataque::getPrecision() const {
    return precision;
}

int Ataque::calcularDano(
    int ataquePokemon,
    int defensaObjetivo,
    double efectividad
) const {

    int dano = (ataquePokemon * potencia) /
               (defensaObjetivo + 10);

    if (dano < 1) {
        dano = 1;
    }

    dano = (int)(dano * efectividad);

    return dano;
}