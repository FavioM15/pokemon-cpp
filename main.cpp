#include <iostream>
#include <string>

using namespace std;

class Tipos {
public:
    string nombre;
    string efectividad;
    string debilidad;
};

class Pokemon {
public:
    string nombre;
    string tipo;
    int vida;
    int ataque;
    int defensa;

    void mostrar() {
        cout << "\n======================" << endl;
        cout << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Defensa: " << defensa << endl;
        cout << "======================\n" << endl;
    }

    double calcularEfectividad(Pokemon &objetivo) {

        if (tipo == "Planta" && objetivo.tipo == "Agua") {
            cout << "¡Ataque super efectivo!" << endl;
            return 2;
        }

        if (tipo == "Planta" && objetivo.tipo == "Fuego") {
            cout << "¡Ataque no muy efectivo!" << endl;
            return 0.5;
        }

        if (tipo == "Fuego" && objetivo.tipo == "Planta") {
            cout << "¡Ataque super efectivo!" << endl;
            return 2;
        }

        if (tipo == "Fuego" && objetivo.tipo == "Agua") {
            cout << "¡Ataque no muy efectivo!" << endl;
            return 0.5;
        }

        if (tipo == "Agua" && objetivo.tipo == "Fuego") {
            cout << "¡Ataque super efectivo!" << endl;
            return 2;
        }

        if (tipo == "Agua" && objetivo.tipo == "Planta") {
            cout << "¡Ataque no muy efectivo!" << endl;
            return 0.5;
        }

        return 1;
    }

    void atacar(Pokemon &objetivo) {

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

        double efectividad = calcularEfectividad(objetivo);

        dano *= efectividad;

        objetivo.recibirDano(dano);

        cout << nombre << " ataca a "
             << objetivo.nombre
             << " y causa "
             << dano
             << " de dano." << endl;

        objetivo.mostrar();
    }

    void recibirDano(int dano) {
        vida -= dano;

        if (vida < 0) {
            vida = 0;
        }
    }
};

int main() {

    cout << "===== Torre de Batalla Pokemon =====\n" << endl;

    Pokemon bulbasaur = {"Bulbasaur", "Planta", 100, 20, 15};
    Pokemon charmander = {"Charmander", "Fuego", 100, 20, 15};
    Pokemon squirtle = {"Squirtle", "Agua", 110, 22, 18};

    Tipos planta = {"Planta", "Agua", "Fuego"};
    Tipos fuego = {"Fuego", "Planta", "Agua"};
    Tipos agua = {"Agua", "Fuego", "Planta"};

    bulbasaur.mostrar();
    charmander.mostrar();
    squirtle.mostrar();

    cout << "\n--- Batalla ---\n" << endl;

    bulbasaur.atacar(charmander);

    bulbasaur.atacar(squirtle);

    squirtle.atacar(bulbasaur);

    squirtle.atacar(charmander);

    return 0;
}