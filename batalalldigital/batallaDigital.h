
#ifndef BATALLADIGITAL_H
#define BATALLADIGITAL_H

#include "tablero.h"

// const char ARRIBA = 'w';
// const char DIAGONALARRIBADERECHA = 'e';
// const char DIAGONALARRIBAIZQUIERDA = 'q';

// const char ABAJO = 's';
// const char DIAGONALBAJOIZQUIERDA = 'a';
// const char DIAGONALABAJODERECHA = 'd';

const char ARRIBA = 'w';
const char DIAGONALARRIBADERECHA = 'e';
const char DIAGONALARRIBAIZQUIERDA = 'q';

const char DERECHA = 'd';
const char IZQUIERDA = 'a';

const char ABAJO = 's';
const char DIAGONALABAJOIZQUIERDA = 'z';
const char DIAGONALABAJODERECHA = 'c';


void jugar(Casillero **tablero);

// bool mover(Casillero **tablero, int filaOrigen, int colOrigen, int filaDestino, int colDestino);
void moverFicha(Casillero **tablero , int i, int j);

void imprimeCoordenadasjugadores(Casillero **tablero, int turno);

void seleccionDeSoldado(Casillero **tablero,int ficha);

// void mostrasMina(Casillero **tablero);

void colocarMina(Casillero **tablero, int x, int y, int ficha );
// bool esValidoMover(Casillero **tablero, int filaOrigen, int colOrigen, int filaDestino, int colDestino);

// void guardarPartida(Casillero **tablero, int turno, std::string nombreArchivo);

// void cargarPartida(Casillero **&tablero, int &turno, std::string nombreArchivo);

// void terminar(Casillero **tablero);

#endif // BATALLADIGITAL_H