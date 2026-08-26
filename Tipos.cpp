#include "Tipos.h"

double Tipos::calcularEfectividad(string atacante, string defensor) {

    if (atacante == "Planta" && defensor == "Agua") {
        return 2;
    }

    if (atacante == "Planta" && defensor == "Fuego") {
        return 0.5;
    }

    if (atacante == "Fuego" && defensor == "Planta") {
        return 2;
    }

    if (atacante == "Fuego" && defensor == "Agua") {
        return 0.5;
    }

    if (atacante == "Agua" && defensor == "Fuego") {
        return 2;
    }

    if (atacante == "Agua" && defensor == "Planta") {
        return 0.5;
    }

    return 1;
}