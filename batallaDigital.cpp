#include "batallaDigital.h"
#include "tablero.h"
#include <string>
#include <iostream>

void jugar(Casillero **tablero) {
    bool termino = false;
    int turno = 1,numeroJugada=0;

    std::string nombreJugador1, nombreJugador2;

    std::cout << "Ingrese el nombre del jugador 1: ";
    std::cin >> nombreJugador1;
    std::cout << "Ingrese el nombre del jugador 2: ";
    std::cin >> nombreJugador2;

    Casillero casillero;

    Jugador jugador1;
    jugador1.nombre = nombreJugador1;
    for(int i = 0;i< 4;i++){
        Ficha ficha;
        ficha.representacion = JUGADOR1;
        ficha.cantidadDeMovimientos = 0;
        int fil = rand() % 20;
        int col = rand() % 20;
        ficha.fila = fil;
        ficha.columna = col;
        jugador1.fichas[i] = ficha;
    }

    Jugador jugador2;
    jugador2.nombre = nombreJugador2;
    for (int i = 0; i < 4; i++)
    {
        Ficha ficha;
        ficha.representacion = JUGADOR2;
        ficha.cantidadDeMovimientos = 0;
        int fil = rand() % 20;
        int col = rand() % 20;
        ficha.fila = fil;
        ficha.columna = col;
        jugador2.fichas[i] = ficha;
    }

    casillero.jugador1 = jugador1;
    casillero.jugador2 = jugador2;

    while (!termino) {

        mostrarTablero(casillero);

        // moverFicha
        imprimeCoordenadasjugadores(tablero, turno);
        if(turno == 1){
                turno = 2;
            } 
            else{
                turno = 1;
            }
        system("pause");
        // tablero[filaDestino][colDestino].ficha = tablero[filaOrigen][colOrigen].ficha;
        // tablero[filaOrigen][colOrigen].ficha = BLANCO;
        numeroJugada++;
    }
}

void imprimeCoordenadasjugadores(Casillero **tablero, int turno){

    if (turno == 1){
        std::cout << "Jugador 1" << std::endl;
    }
    else{
        std::cout << "Jugador 2" << std::endl;
    }
    // for (int i = 0; i < ALTODELTABLERO; i++) {
    //     for (int j = 0; j < ANCHODELTABLERO; j++){
    //         if (tablero[i][j].ficha == turno){
    //             std::cout << i + 1 <<')' << "Ficha: " << tablero[i][j].ficha << " Coordenadas: " << i << " " << j << std::endl;
    //         }
    //     }
    // }

}
// void moverNumeroDeJugador(Casillero **tablero ){
//     int numeroDeJugador;
//     std::cout << "Ingrese el numero de jugador que desea mover: " << std::endl;
//     std::cin >> numeroDeJugador;
//     int filaOrigen = soldados[numeroDeJugador].x;
//     int colOrigen = soldados[numeroDeJugador].y;
//     int filaDestino;
//     int colDestino;
//     std::cout << "Ingrese la fila a la que desea mover el soldado: " << std::endl;
//     std::cin >> filaDestino;
//     std::cout << "Ingrese la columna a la que desea mover el soldado: " << std::endl;
//     std::cin >> colDestino;
//     if (esValidoMover(tablero, filaOrigen, colOrigen, filaDestino, colDestino)){
//         mover(tablero, filaOrigen, colOrigen, filaDestino, colDestino);
//     }
//     else{
//         std::cout << "Movimiento invalido" << std::endl;
//     }
// }



// void moverFicha(Casillero **tablero, int i, intj){

//     int soldado;
//     char direccion;
//     std::cout << "Ingrese el numero del soldado que desea mover: " << std::endl;
//     std::cin >> soldado;
    
//     std::cout << "Ingrese la direccion a la que desea mover el soldado: " << std::endl;
//     std::cin >> direccion;

//     int fil = soldados[soldado].x;
//     int col = soldados[soldado].y;

//     switch (direccion) {
//     case ARRIBA:
//       if (tablero[fil - 1][col] == '.' && fil - 1 >= 0) {
//         tablero[fil - 1][col] = '1';
//         tablero[fil][col] = '.';
//         soldados[soldado].x = fil - 1;
//         soldados[soldado].y = col;
//       }
//       else {
//         std::cout << "Movimiento invalido" << endl;
//       }
//       break;
//     case ABAJO:
//       if (tablero[fil + 1][col] == '.' && fil + 1 < FIL) {
//         tablero[fil + 1][col] = '1';
//         tablero[fil][col] = '.';
//         soldados[soldado].x = fil + 1;
//         soldados[soldado].y = col;
//       }
//       else {
//         std::cout << "Movimiento invalido" << endl;
//       }
//       break;
//     case DERECHA:
//       if (tablero[fil][col + 1] == '.'&& col + 1 < COL) {
//         tablero[fil][col + 1] = '1';
//         tablero[fil][col] = '.';
//         soldados[soldado].x = fil;
//         soldados[soldado].y = col + 1;
//       }
//       else {
//         std::cout << "Movimiento invalido" << endl;
//       }
//       break;
//     case IZQUIERDA:
//       if (tablero[fil][col - 1] == '.'&& col - 1 >= 0) {
//         tablero[fil][col - 1] = '1';
//         tablero[fil][col] = '.';
//         soldados[soldado].x = fil;
//         soldados[soldado].y = col - 1;
//       }
//       else {
//         std::cout << "Movimiento invalido" << endl;
//       }
//       break;
//     case DIAGONALARRIBADERECHA:
//       if (tablero[fil - 1][col + 1] == '.'&& fil - 1 >= 0 && col + 1 < COL) {
//         tablero[fil - 1][col + 1] = '1';
//         tablero[fil][col] = '.';
//         soldados[soldado].x = fil - 1;
//         soldados[soldado].y = col + 1;
//         }
//         else {
//             std::cout << "Movimiento invalido" << endl;
//             }
//         break;
//     case DIAGONALARRIBAIZQUIERDA:
//         if (tablero[fil - 1][col - 1] == '.'&& fil - 1 >= 0 && col - 1 >= 0) {
//             tablero[fil - 1][col - 1] = '1';
//             tablero[fil][col] = '.';
//             soldados[soldado].x = fil - 1;
//             soldados[soldado].y = col - 1;
//             }
//             else {
//                 std::cout << "Movimiento invalido" << endl;
//                 }
//             break;
//     case DIAGONALABAJODERECHA:
//         if (tablero[fil + 1][col + 1] == '.'&& fil + 1 < FIL && col + 1 < COL) {
//             tablero[fil + 1][col + 1] = '1';
//             tablero[fil][col] = '.';
//             soldados[soldado].x = fil + 1;
//             soldados[soldado].y = col + 1;
//             }
//             else {
//                 std::cout << "Movimiento invalido" << endl;
//                 }
//             break;
//     case DIAGONALABAJOIZQUIERDA:
//         if (tablero[fil + 1][col - 1] == '.'&& fil + 1 < FIL && col - 1 >= 0) {
//             tablero[fil + 1][col - 1] = '1';
//             tablero[fil][col] = '.';
//             soldados[soldado].x = fil + 1;
//             soldados[soldado].y = col - 1;
//             }
//             else {
//                 std::cout << "Movimiento invalido" << endl;
//                 }
//             break;
//     default:
//         std::cout << "Movimiento invalido" << endl;
//         break;
//     }
// }

// }


        // if (mover(tablero, filaOrigen, colOrigen, filaDestino, colDestino)) {
//             if (turno == 1) {
//                 turno = 2;
//             } 
//             else {
//                 turno = 1;
//             }
//         }
//     }
// }

// bool mover(Casillero **tablero, int filaOrigen, int colOrigen, int filaDestino, int colDestino){
//     if (esValidoMover(tablero, filaOrigen, colOrigen, filaDestino, colDestino)) {
//         tablero[filaDestino][colDestino].ficha = tablero[filaOrigen][colOrigen].ficha;
//         tablero[filaOrigen][colOrigen].ficha = BLANCO;
//         return true;
//     } else {
//         return false;
//     }
// }

// bool esValidoMover(Casillero **tablero, int filaOrigen, int colOrigen, int filaDestino, int colDestino) {
//     if (tablero[filaOrigen][colOrigen].ficha == BLANCO) {
//         return false;
//     }
//     if (tablero[filaDestino][colDestino].ficha != BLANCO) {
//         return false;
//     }
//     if (filaOrigen == filaDestino && colOrigen == colDestino) {
//         return false;
//     }
//     if (filaOrigen < 0 || filaOrigen >= ANCHODELTABLERO || colOrigen < 0 || colOrigen >= ALTODELTABLERO) {
//         return false;
//     }
//     if (filaDestino < 0 || filaDestino >= ANCHODELTABLERO || colDestino < 0 || colDestino >= ALTODELTABLERO) {
//         return false;
//     }
//     if (filaOrigen == filaDestino) {
//         if (colOrigen == colDestino + 1 || colOrigen == colDestino - 1) {
//             return true;
//         } else {
//             return false;
//         }
//     }
//     if (colOrigen == colDestino) {
//         if (filaOrigen == filaDestino + 1 || filaOrigen == filaDestino - 1) {
//             return true;
//         } else {
//             return false;
//         }
//     }
//     return false;
// }

// Path: batallaDigital.cpp




