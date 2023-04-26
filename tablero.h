// tablero.h
#include <string>
#include <iostream>

#ifndef TABLERO_H
#define TABLERO_H

const int ANCHODELTABLERO = 20;
const int ALTODELTABLERO = 20;

enum FichaR {
    BLANCO,
    JUGADOR1,
    JUGADOR2,
    MINA,
    ACTIVO,
    INACTIVA
};

struct Ficha
{
    FichaR representacion;
    int cantidadDeMovimientos;
    int fila;
    int columna;
};

struct Jugador
{
    std::string nombre;
    Ficha fichas[4];
};

struct Casillero {
    Jugador jugador1;
    Jugador jugador2;
    bool activo;
    int cantidadDeTurnosActivo;
};



void crearTablero(Casillero **&tablero);
void cargarTablero(Casillero **tablero);
void mostrarTablero(Casillero tablero);
void eliminarTablero(Casillero **tablero);

#endif // TABLERO_H
