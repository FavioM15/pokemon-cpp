#include <iostream>
#include "Pokemon.h"

using namespace std;

int main() {

    cout << "===== Torre de Batalla Pokemon =====\n" << endl;

    Pokemon bulbasaur("Bulbasaur", "Planta", 100, 20, 15,30,20);
    Pokemon charmander("Charmander", "Fuego", 100, 20, 15,25,15);
    Pokemon squirtle("Squirtle", "Agua", 110, 22, 18,15,20);
    Pokemon geodude("Geodude", "Roca", 100, 20, 15,10,15, "la roca");

    cout << "\n--- Batalla ---\n" << endl;

    squirtle.atacar(geodude);

    return 0;
}