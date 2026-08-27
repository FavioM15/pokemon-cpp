#include "Batalla.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Batalla::Batalla(Pokemon& jugador, Pokemon& oponente)
    : jugador(jugador), oponente(oponente) {

    esTurnoJugador = true;
    batallaTerminada = false;

    srand(time(0));
}

void Batalla::iniciar() {

    cout << "\n=== ¡COMIENZA LA BATALLA! ===\n" << endl;

    cout << jugador.getNombreMostrar()
         << " vs "
         << oponente.getNombreMostrar()
         << endl;

    while (!batallaTerminada) {

        mostrarEstado();

        if (esTurnoJugador) {
            turnoJugador();
        }
        else {
            turnoOponente();
        }

        batallaTerminada = terminarBatalla();

        if (!batallaTerminada) {
            esTurnoJugador = !esTurnoJugador;
        }
    }
}

void Batalla::turnoJugador() {

    cout << "\n--- Turno de "
         << jugador.getNombreMostrar()
         << " ---" << endl;

    jugador.mostrarAtaques();

    int seleccion;

    cout << "Selecciona un ataque (1-"
         << jugador.getAtaques().size()
         << "): ";

    cin >> seleccion;

    if (cin.fail() ||
        seleccion < 1 ||
        seleccion > (int)jugador.getAtaques().size()) {

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Selección inválida. Turno perdido." << endl;

        return;
    }

    jugador.atacar(oponente, seleccion - 1);
}

void Batalla::turnoOponente() {

    cout << "\n--- Turno de "
         << oponente.getNombreMostrar()
         << " ---" << endl;

    int numAtaques = oponente.getAtaques().size();

    int seleccion = rand() % numAtaques;

    cout << oponente.getNombreMostrar()
         << " usa "
         << oponente.getAtaques()[seleccion].getNombre()
         << "!" << endl;

    oponente.atacar(jugador, seleccion);
}

bool Batalla::terminarBatalla() {

    if (jugador.estaDebilitado()) {

        cout << "\n¡"
             << jugador.getNombreMostrar()
             << " se ha debilitado!" << endl;

        cout << "¡"
             << oponente.getNombreMostrar()
             << " gana la batalla!" << endl;

        return true;
    }

    if (oponente.estaDebilitado()) {

        cout << "\n¡"
             << oponente.getNombreMostrar()
             << " se ha debilitado!" << endl;

        cout << "¡"
             << jugador.getNombreMostrar()
             << " gana la batalla!" << endl;

        return true;
    }

    return false;
}

void Batalla::mostrarEstado() const {

    cout << "\n=== ESTADO DE LA BATALLA ===" << endl;

    cout << jugador.getNombreMostrar()
         << ": "
         << jugador.getVida()
         << "/"
         << jugador.getVidaMaxima()
         << " HP"
         << endl;

    cout << oponente.getNombreMostrar()
         << ": "
         << oponente.getVida()
         << "/"
         << oponente.getVidaMaxima()
         << " HP"
         << endl;

    cout << "=============================\n"
         << endl;
}