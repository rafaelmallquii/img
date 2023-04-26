
#ifndef BATALLADIGITAL_H
#define BATALLADIGITAL_H

#include "tablero.h"

// const char ARRIBA = 'w';
// const char DIAGONALARRIBADERECHA = 'e';

// const char DERECHA = 'd';
// const char IZQUIERDA= 'a';


// const char DIAGONALARRIBAIZQUIERDA = 'q';
// const char ABAJO = 's';
// const char DIAGONALBAJOIZQUIERDA = 'Z';
// const char DIAGONALABAJODERECHA = 'C';



void jugar(Casillero **tablero);

// bool mover(Casillero **tablero, int filaOrigen, int colOrigen, int filaDestino, int colDestino);
void moverFicha(Casillero **tablero);

void imprimeCoordenadasjugadores(Casillero **tablero, int turno);

// bool esValidoMover(Casillero **tablero, int filaOrigen, int colOrigen, int filaDestino, int colDestino);

// void guardarPartida(Casillero **tablero, int turno, std::string nombreArchivo);

// void cargarPartida(Casillero **&tablero, int &turno, std::string nombreArchivo);

// void terminar(Casillero **tablero);

#endif // BATALLADIGITAL_H