#include "BaseDatosPokemon.h"
#include "Ataque.h"
#include <vector>

using namespace std;

vector<Pokemon> BaseDatosPokemon::obtenerPokemonIniciales() {
    vector<Pokemon> pokemons;
    
    // ========== CREAR ATAQUES ==========
    Ataque placaje("Placaje", "Normal", 40);
    Ataque hojaAfilada("Hoja Afilada", "Planta", 55);
    Ataque llamarada("Llamarada", "Fuego", 60);
    Ataque pistolaAgua("Pistola Agua", "Agua", 50);
    Ataque burbuja("Burbuja", "Agua", 30);
    Ataque golpeRoca("Golpe Roca", "Roca", 45);
    Ataque impactoElectrico("Impacto Eléctrico", "Electrico", 50);
    Ataque terremoto("Terremoto", "Tierra", 70);
    Ataque corteAereo("Corte Aéreo", "Volador", 55);
    Ataque puñoCometa("Puño Cometa", "Lucha", 45);
    Ataque atadura("Atadura", "Bicho", 30);
    Ataque colaDragon("Cola Dragón", "Dragon", 60);
    Ataque sombras("Sombras", "Fantasma", 50);
    
    // ========== BULBASAUR ==========
    Pokemon bulbasaur("Bulbasaur", "Planta", 100, 20, 15, 30, 20);
    bulbasaur.agregarAtaque(placaje);
    bulbasaur.agregarAtaque(hojaAfilada);
    pokemons.push_back(bulbasaur);
    
    // ========== CHARMANDER ==========
    Pokemon charmander("Charmander", "Fuego", 100, 20, 15, 25, 15);
    charmander.agregarAtaque(placaje);
    charmander.agregarAtaque(llamarada);
    pokemons.push_back(charmander);
    
    // ========== SQUIRTLE ==========
    Pokemon squirtle("Squirtle", "Agua", 110, 22, 18, 15, 20);
    squirtle.agregarAtaque(placaje);
    squirtle.agregarAtaque(pistolaAgua);
    squirtle.agregarAtaque(burbuja);
    pokemons.push_back(squirtle);
    
    // ========== GEODUDE ==========
    Pokemon geodude("Geodude", "Roca", 100, 20, 15, 10, 15);
    geodude.agregarAtaque(placaje);
    geodude.agregarAtaque(golpeRoca);
    pokemons.push_back(geodude);
    
    // ========== PIKACHU ==========
    Pokemon pikachu("Pikachu", "Electrico", 90, 25, 12, 20, 15);
    pikachu.agregarAtaque(placaje);
    pikachu.agregarAtaque(impactoElectrico);
    pokemons.push_back(pikachu);
    
    // ========== PIDGEY ==========
    Pokemon pidgey("Pidgey", "Volador", 85, 18, 14, 20, 12);
    pidgey.agregarAtaque(placaje);
    pidgey.agregarAtaque(corteAereo);
    pokemons.push_back(pidgey);
    
    return pokemons;
}

Pokemon BaseDatosPokemon::obtenerPorEspecie(string especie) {
    vector<Pokemon> todos = obtenerPokemonIniciales();
    for (Pokemon& p : todos) {
        if (p.getEspecie() == especie) {
            return p;
        }
    }
    return Pokemon("Pikachu", "Electrico", 90, 25, 12, 20, 15);
}