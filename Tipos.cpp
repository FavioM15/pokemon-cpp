#include "Tipos.h"

double Tipos::calcularEfectividad(
    std::string atacante,
    std::string defensor
) {

    // FUEGO
    if (atacante == "Fuego" && defensor == "Planta") return 2.0;
    if (atacante == "Fuego" && defensor == "Bicho") return 2.0;
    if (atacante == "Fuego" && defensor == "Hielo") return 2.0;
    if (atacante == "Fuego" && defensor == "Acero") return 2.0;

    if (atacante == "Fuego" && defensor == "Agua") return 0.5;
    if (atacante == "Fuego" && defensor == "Roca") return 0.5;
    if (atacante == "Fuego" && defensor == "Fuego") return 0.5;
    if (atacante == "Fuego" && defensor == "Dragon") return 0.5;

    // AGUA
    if (atacante == "Agua" && defensor == "Fuego") return 2.0;
    if (atacante == "Agua" && defensor == "Roca") return 2.0;
    if (atacante == "Agua" && defensor == "Tierra") return 2.0;

    if (atacante == "Agua" && defensor == "Planta") return 0.5;
    if (atacante == "Agua" && defensor == "Agua") return 0.5;
    if (atacante == "Agua" && defensor == "Dragon") return 0.5;

    // PLANTA
    if (atacante == "Planta" && defensor == "Agua") return 2.0;
    if (atacante == "Planta" && defensor == "Tierra") return 2.0;
    if (atacante == "Planta" && defensor == "Roca") return 2.0;

    if (atacante == "Planta" && defensor == "Fuego") return 0.5;
    if (atacante == "Planta" && defensor == "Planta") return 0.5;
    if (atacante == "Planta" && defensor == "Volador") return 0.5;
    if (atacante == "Planta" && defensor == "Veneno") return 0.5;
    if (atacante == "Planta" && defensor == "Bicho") return 0.5;
    if (atacante == "Planta" && defensor == "Acero") return 0.5;

    // ELECTRICO
    if (atacante == "Electrico" && defensor == "Agua") return 2.0;
    if (atacante == "Electrico" && defensor == "Volador") return 2.0;

    if (atacante == "Electrico" && defensor == "Planta") return 0.5;
    if (atacante == "Electrico" && defensor == "Electrico") return 0.5;
    if (atacante == "Electrico" && defensor == "Dragon") return 0.5;

    if (atacante == "Electrico" && defensor == "Tierra") return 0.0;

    // TIERRA
    if (atacante == "Tierra" && defensor == "Fuego") return 2.0;
    if (atacante == "Tierra" && defensor == "Electrico") return 2.0;
    if (atacante == "Tierra" && defensor == "Veneno") return 2.0;
    if (atacante == "Tierra" && defensor == "Roca") return 2.0;
    if (atacante == "Tierra" && defensor == "Acero") return 2.0;

    if (atacante == "Tierra" && defensor == "Planta") return 0.5;
    if (atacante == "Tierra" && defensor == "Bicho") return 0.5;

    if (atacante == "Tierra" && defensor == "Volador") return 0.0;

    // ROCA
    if (atacante == "Roca" && defensor == "Fuego") return 2.0;
    if (atacante == "Roca" && defensor == "Hielo") return 2.0;
    if (atacante == "Roca" && defensor == "Volador") return 2.0;
    if (atacante == "Roca" && defensor == "Bicho") return 2.0;

    if (atacante == "Roca" && defensor == "Agua") return 0.5;
    if (atacante == "Roca" && defensor == "Planta") return 0.5;
    if (atacante == "Roca" && defensor == "Lucha") return 0.5;
    if (atacante == "Roca" && defensor == "Tierra") return 0.5;
    if (atacante == "Roca" && defensor == "Acero") return 0.5;

    // VOLADOR
    if (atacante == "Volador" && defensor == "Planta") return 2.0;
    if (atacante == "Volador" && defensor == "Lucha") return 2.0;
    if (atacante == "Volador" && defensor == "Bicho") return 2.0;

    if (atacante == "Volador" && defensor == "Electrico") return 0.5;
    if (atacante == "Volador" && defensor == "Roca") return 0.5;
    if (atacante == "Volador" && defensor == "Acero") return 0.5;

    // BICHO
    if (atacante == "Bicho" && defensor == "Planta") return 2.0;
    if (atacante == "Bicho" && defensor == "Psiquico") return 2.0;
    if (atacante == "Bicho" && defensor == "Siniestro") return 2.0;

    if (atacante == "Bicho" && defensor == "Fuego") return 0.5;
    if (atacante == "Bicho" && defensor == "Lucha") return 0.5;
    if (atacante == "Bicho" && defensor == "Veneno") return 0.5;
    if (atacante == "Bicho" && defensor == "Volador") return 0.5;
    if (atacante == "Bicho" && defensor == "Fantasma") return 0.5;
    if (atacante == "Bicho" && defensor == "Acero") return 0.5;

    // DRAGON
    if (atacante == "Dragon" && defensor == "Dragon") return 2.0;
    if (atacante == "Dragon" && defensor == "Acero") return 0.5;
    if (atacante == "Dragon" && defensor == "Hada") return 0.0;

    // FANTASMA
    if (atacante == "Fantasma" && defensor == "Fantasma") return 2.0;
    if (atacante == "Fantasma" && defensor == "Psiquico") return 2.0;

    if (atacante == "Fantasma" && defensor == "Siniestro") return 0.5;
    if (atacante == "Fantasma" && defensor == "Normal") return 0.0;

    // PSIQUICO
    if (atacante == "Psiquico" && defensor == "Lucha") return 2.0;
    if (atacante == "Psiquico" && defensor == "Veneno") return 2.0;

    if (atacante == "Psiquico" && defensor == "Psiquico") return 0.5;
    if (atacante == "Psiquico" && defensor == "Acero") return 0.5;

    if (atacante == "Psiquico" && defensor == "Siniestro") return 0.0;

    // HIELO
    if (atacante == "Hielo" && defensor == "Planta") return 2.0;
    if (atacante == "Hielo" && defensor == "Tierra") return 2.0;
    if (atacante == "Hielo" && defensor == "Volador") return 2.0;
    if (atacante == "Hielo" && defensor == "Dragon") return 2.0;

    if (atacante == "Hielo" && defensor == "Agua") return 0.5;
    if (atacante == "Hielo" && defensor == "Hielo") return 0.5;
    if (atacante == "Hielo" && defensor == "Fuego") return 0.5;
    if (atacante == "Hielo" && defensor == "Acero") return 0.5;

    // LUCHA
    if (atacante == "Lucha" && defensor == "Normal") return 2.0;
    if (atacante == "Lucha" && defensor == "Hielo") return 2.0;
    if (atacante == "Lucha" && defensor == "Roca") return 2.0;
    if (atacante == "Lucha" && defensor == "Siniestro") return 2.0;
    if (atacante == "Lucha" && defensor == "Acero") return 2.0;

    if (atacante == "Lucha" && defensor == "Veneno") return 0.5;
    if (atacante == "Lucha" && defensor == "Volador") return 0.5;
    if (atacante == "Lucha" && defensor == "Psiquico") return 0.5;
    if (atacante == "Lucha" && defensor == "Bicho") return 0.5;
    if (atacante == "Lucha" && defensor == "Hada") return 0.5;
    if (atacante == "Lucha" && defensor == "Fantasma") return 0.0;

    return 1.0;
}