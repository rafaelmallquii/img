#include "tablero.h"
#include "batallaDigital.h"
#include <iostream>

int main() {
    Casillero **tablero;
    int turno = 1;
    crearTablero(tablero);
    cargarTablero(tablero);
    jugar(tablero);
    eliminarTablero(tablero);
    return 0;
}