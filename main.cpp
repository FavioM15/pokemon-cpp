#include <iostream>
#include "Pokemon.h"

using namespace std;

int main() {

    cout << "===== Torre de Batalla Pokemon =====\n" << endl;

    Pokemon bulbasaur("Bulbasaur", "Planta", 100, 20, 15);
    Pokemon charmander("Charmander", "Fuego", 100, 20, 15);
    Pokemon squirtle("Squirtle", "Agua", 110, 22, 18);

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