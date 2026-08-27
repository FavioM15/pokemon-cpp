#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"
#include "Ataque.h"
#include "Tipos.h"
#include "BaseDatosPokemon.h"
#include "Batalla.h"

using namespace std;

int main() {
    cout << "===== TORRE DE BATALLA POKEMON =====\n" << endl;
    
    vector<Pokemon> pokemons = BaseDatosPokemon::obtenerPokemonIniciales();
    
    cout << "Pokémon disponibles:" << endl;
    for (size_t i = 0; i < pokemons.size(); i++) {
        cout << (i + 1) << ". " << pokemons[i].getNombreMostrar() 
             << " (" << pokemons[i].getTipo() << ")" << endl;
    }
    
    int seleccion;
    cout << "\nSelecciona tu Pokémon (1-" << pokemons.size() << "): ";
    cin >> seleccion;
    
    if (cin.fail() || seleccion < 1 || seleccion > (int)pokemons.size()) {
        cout << "Selección inválida. Usando Bulbasaur por defecto." << endl;
        seleccion = 1;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    
    Pokemon jugador = pokemons[seleccion - 1];
    
    srand(time(0));
    int oponenteIdx;
    do {
        oponenteIdx = rand() % pokemons.size();
    } while (oponenteIdx == seleccion - 1);
    
    Pokemon oponente = pokemons[oponenteIdx];
    
    string apodo;
    cout << "¿Quieres ponerle un apodo a " << jugador.getEspecie() << "? (deja vacío para no): ";
    cin.ignore();
    getline(cin, apodo);
    if (!apodo.empty()) {
        jugador.setApodo(apodo);
    }
    
    cout << "\n" << jugador.getNombreMostrar() << " entra en batalla!" << endl;
    cout << "¡Enfrenta a " << oponente.getNombreMostrar() << "!" << endl;
    
    Batalla batalla(jugador, oponente);
    batalla.iniciar();
    
    return 0;
}