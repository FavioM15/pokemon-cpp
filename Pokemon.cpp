#include "Pokemon.h"
#include "Tipos.h"
#include <iostream>

using namespace std;

// Constructor
Pokemon::Pokemon(string especie, string tipo, int vida, int ataque, int defensa, 
                 int ataque_esp, int defensa_esp, string apodo) {
    this->especie = especie;
    this->tipo = tipo;
    this->vida = vida;
    this->vidaMaxima = vida;
    this->ataque = ataque;
    this->defensa = defensa;
    this->ataque_esp = ataque_esp;
    this->defensa_esp = defensa_esp;
    this->apodo = apodo;
    this->nivel = 5;
    this->debilitado = false;
}

// Getters
string Pokemon::getEspecie() const { return especie; }
string Pokemon::getApodo() const { return apodo; }
string Pokemon::getTipo() const { return tipo; }
int Pokemon::getVida() const { return vida; }
int Pokemon::getVidaMaxima() const { return vidaMaxima; }
int Pokemon::getAtaque() const { return ataque; }
int Pokemon::getDefensa() const { return defensa; }
bool Pokemon::estaDebilitado() const { return debilitado; }

string Pokemon::getNombreMostrar() const {
    if (!apodo.empty()) {
        return apodo + " (" + especie + ")";
    }
    return especie;
}

void Pokemon::setApodo(string nuevoApodo) {
    this->apodo = nuevoApodo;
}

void Pokemon::recibirDano(int dano) {
    if (dano < 0) dano = 0;
    
    vida -= dano;
    if (vida < 0) vida = 0;
    
    if (vida == 0) {
        debilitado = true;
    }
}

void Pokemon::curar(int cantidad) {
    vida += cantidad;
    if (vida > vidaMaxima) vida = vidaMaxima;
    debilitado = false;
}

void Pokemon::agregarAtaque(Ataque ataque) {
    if (ataques.size() < 4) {
        ataques.push_back(ataque);
    } else {
        cout << "¡" << getNombreMostrar() << " ya tiene 4 ataques!" << endl;
    }
}

void Pokemon::mostrarAtaques() const {
    cout << "Ataques de " << getNombreMostrar() << ":" << endl;
    for (size_t i = 0; i < ataques.size(); i++) {
        cout << "  " << (i + 1) << ". " << ataques[i].getNombre() 
             << " (Tipo: " << ataques[i].getTipo() 
             << ", Potencia: " << ataques[i].getPotencia() << ")" << endl;
    }
}

const vector<Ataque>& Pokemon::getAtaques() const {
    return ataques;
}

void Pokemon::mostrar() const {
    cout << "\n============================" << endl;
    cout << getNombreMostrar() << " (Nvl. " << nivel << ")" << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Vida: " << vida << "/" << vidaMaxima << endl;
    cout << "Ataque: " << ataque << "\tDefensa: " << defensa << endl;
    cout << "Ataque Esp: " << ataque_esp << "\tDefensa Esp: " << defensa_esp << endl;
    if (debilitado) {
        cout << "¡DEBILITADO!" << endl;
    }
    cout << "============================\n" << endl;
}

void Pokemon::atacar(Pokemon &objetivo, int indiceAtaque) {
    // Validaciones
    if (debilitado) {
        cout << getNombreMostrar() << " no puede atacar porque está debilitado." << endl;
        return;
    }
    
    if (objetivo.estaDebilitado()) {
        cout << objetivo.getNombreMostrar() << " ya está debilitado." << endl;
        return;
    }
    
    if (indiceAtaque < 0 || indiceAtaque >= (int)ataques.size()) {
        cout << "Ataque inválido." << endl;
        return;
    }
    
    // Obtener el ataque seleccionado
    Ataque ataqueUsado = ataques[indiceAtaque];
    
    // Calcular efectividad
    double efectividad = Tipos::calcularEfectividad(ataqueUsado.getTipo(), objetivo.getTipo());
    
    // Mostrar mensaje de efectividad
    if (efectividad == 2.0) {
        cout << "¡Es super efectivo!" << endl;
    } else if (efectividad == 0.5) {
        cout << "¡No es muy efectivo..." << endl;
    } else if (efectividad == 0.0) {
        cout << "¡No afecta a " << objetivo.getNombreMostrar() << "!" << endl;
        return;
    }
    
    // Calcular daño usando el método del ataque
    int dano = ataqueUsado.calcularDano(ataque, objetivo.getDefensa(), efectividad);
    
    // Aplicar daño
    objetivo.recibirDano(dano);
    
    // Mostrar resultado
    cout << getNombreMostrar() << " usa " << ataqueUsado.getNombre() << "!" << endl;
    cout << "Causa " << dano << " puntos de daño a " << objetivo.getNombreMostrar() << "." << endl;
    
    if (objetivo.estaDebilitado()) {
        cout << "¡" << objetivo.getNombreMostrar() << " se ha debilitado!" << endl;
    }
}