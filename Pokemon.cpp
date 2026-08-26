#include "Pokemon.h"
#include "Tipos.h"

Pokemon::Pokemon(string nombre, string tipo, int vida, int ataque, int defensa) {
    this->nombre = nombre;
    this->tipo = tipo;
    this->vida = vida;
    this->ataque = ataque;
    this->defensa = defensa;
}

void Pokemon::mostrar() {
    cout << "\n======================" << endl;
    cout << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Vida: " << vida << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Defensa: " << defensa << endl;
    cout << "======================\n" << endl;
}

void Pokemon::atacar(Pokemon &objetivo) {

    if (vida <= 0) {
        cout << nombre << " no puede atacar porque esta debilitado." << endl;
        return;
    }

    if (objetivo.vida <= 0) {
        cout << objetivo.nombre << " ya esta debilitado." << endl;
        return;
    }

    int dano = ataque - objetivo.defensa;

    if (dano < 1) {
        dano = 1;
    }

    double efectividad = Tipos::calcularEfectividad(tipo, objetivo.tipo);

    if (efectividad == 2) {
        cout << "¡Ataque super efectivo!" << endl;
    }
    else if (efectividad == 0.5) {
        cout << "¡Ataque no muy efectivo!" << endl;
    }

    dano *= efectividad;

    objetivo.recibirDano(dano);

    cout << nombre << " ataca a "
         << objetivo.nombre
         << " y causa "
         << dano
         << " de dano." << endl;

    objetivo.mostrar();
}

void Pokemon::recibirDano(int dano) {
    vida -= dano;

    if (vida < 0) {
        vida = 0;
    }
}