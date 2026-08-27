#include "Pokemon.h"
#include "Tipos.h"

Pokemon::Pokemon(string especie, string tipo, int vida, int ataque, int defensa, int ataque_esp, int defensa_esp, string apodo) {
    this->especie = especie;
    this->apodo = apodo;
    this->tipo = tipo;
    this->vida = vida;
    this->ataque = ataque;
    this->defensa = defensa;
    this->ataque_esp = ataque_esp;
    this->defensa_esp = defensa_esp;
}
void Pokemon::setNombre(string nombre) { this->apodo = nombre; } ;
string Pokemon::getNombre() const { return apodo;};

string Pokemon::getNombreMostrar() const {
    if (!apodo.empty()) {
        return apodo+"("+especie+")";
    }
    return especie;};

void Pokemon::mostrar() {
    cout << "\n============================" << endl;
    cout << getNombreMostrar() << endl;
    cout << "Tipo: " << tipo;
    cout << "\tVida: " << vida << endl;
    cout << "Ataque: " << ataque;
    cout << "\tDefensa: " << defensa << endl;
    cout << "Ataque Especial: " << ataque_esp;
    cout << "\tDefensa Especial: " << defensa_esp << endl;
    cout << "============================\n" << endl;
}

void Pokemon::atacar(Pokemon &objetivo) {

    if (vida <= 0) {
        cout << apodo << " no puede atacar porque esta debilitado." << endl;
        return;
    }

    if (objetivo.vida <= 0) {
        cout << objetivo.apodo << " ya esta debilitado." << endl;
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

    cout << apodo << " ataca a "
         << objetivo.apodo
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