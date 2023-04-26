// tablero.h

#ifndef TABLERO_H
#define TABLERO_H

const int ANCHODELTABLERO = 10;
const int ALTODELTABLERO = 10;

enum Ficha {
    BLANCO,
    JUGADOR1,
    JUGADOR2,
    MINA,
    INACTIVA
};

struct Casillero {
    Ficha ficha;
    bool activo;
	
    int cantidadDeTurnosActivo;
};

void crearTablero(Casillero **&tablero);
void cargarTablero(Casillero **tablero);
void mostrarTablero(Casillero **tablero);
void eliminarTablero(Casillero **tablero);

#endif // TABLERO_H
