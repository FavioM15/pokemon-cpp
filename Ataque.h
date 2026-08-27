#ifndef ATAQUE_H
#define ATAQUE_H

#include <string>

class Ataque {
private:
    std::string nombre;
    std::string tipo;
    int potencia;
    int precision;

public:
    Ataque(std::string nombre, std::string tipo, int potencia, int precision = 100);

    std::string getNombre() const;
    std::string getTipo() const;
    int getPotencia() const;
    int getPrecision() const;

    int calcularDano(int ataquePokemon,int defensaObjetivo,double efectividad) const;

};

#endif