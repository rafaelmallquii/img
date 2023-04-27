// tablero.h

#ifndef TABLERO_H
#define TABLERO_H

const int ANCHODELTABLERO = 20;
const int ALTODELTABLERO = 20;

enum Ficha {
    BLANCO,
    JUGADOR1,
    JUGADOR2,
    MINA,
    INACTIVA
};

struct Soldado {
    int x;
    int y;
    int jugador;
};

struct Casillero {
    Ficha ficha;
    bool activo;
    int cantidadDeTurnosActivo;
    int jugadorDeMina;
    bool tieneBomba;
    Soldado soldado; // Agregamos el soldado a cada casillero
};

void crearTablero(Casillero **&tablero);
void cargarTablero(Casillero **tablero);
void mostrarTablero(Casillero **tablero, int jugador);
void eliminarTablero(Casillero **tablero);

#endif // TABLERO_H
