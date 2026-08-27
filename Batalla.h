#ifndef BATALLA_H
#define BATALLA_H

#include "Pokemon.h"

class Batalla {
private:
    Pokemon& jugador;
    Pokemon& oponente;
    bool esTurnoJugador;
    bool batallaTerminada;

public:
    Batalla(Pokemon& jugador, Pokemon& oponente);

    void iniciar();
    void turnoJugador();
    void turnoOponente();
    bool terminarBatalla();
    void mostrarEstado() const;
};

#endif