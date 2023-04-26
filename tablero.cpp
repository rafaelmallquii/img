#include "tablero.h"
#include <iostream>

void crearTablero(Casillero **&tablero) {
    tablero = new Casillero*[ANCHODELTABLERO];
    for (int i = 0; i < ANCHODELTABLERO; i++) {
        tablero[i] = new Casillero[ALTODELTABLERO];
        for (int j = 0; j < ALTODELTABLERO; j++) {
            tablero[i][j].ficha = BLANCO;
            tablero[i][j].activo = false;
            tablero[i][j].cantidadDeTurnosActivo = 0;
        }
    }
}

void cargarTablero(Casillero **tablero) {
    // Colocar fichas de jugador 1
    for (int i = 0; i < 4; i++) {
        tablero[i][0].ficha = JUGADOR1;
    }
    // Colocar fichas de jugador 2
    for (int i = 0; i < 4; i++) {
        tablero[i][ALTODELTABLERO - 1].ficha = JUGADOR2;
    }
}

void mostrarTablero(Casillero **tablero) {
    // std::cout<<"   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19"<< std::endl;
    // std::cout<<"   ----------------------------------------------------------"<< std::endl;
    for (int i = 0; i < ANCHODELTABLERO; i++) {
        for (int j = 0; j < ALTODELTABLERO; j++) {
            if (tablero[i][j].activo) {
                std::cout << " X ";
            } else {
                switch (tablero[i][j].ficha) {
                    case BLANCO:
                        std::cout << " . ";
                        break;
                    case JUGADOR1:
                        std::cout << " 1 ";
                        break;
                    case JUGADOR2:
                        std::cout << " 2 ";
                        break;
                    case MINA:
                        std::cout << " M ";
                        break;
                    case INACTIVA:
                        std::cout << " X ";
                        break;
                }
            }
        }
        std::cout << std::endl;
    }
    // std::cout<<"   ----------------------------------------------------------";
}


    // for(int i = 0; i < FIL; i++){
    //     for(int j = 0; j < COL; j++){
    //         if(j > 0) {
    //             std::cout<<"  "<< matriz[i][j];
    //         }
    //         else {
    //             if (i < 10){
    //                 std::cout<<i<<" |"<<matriz[i][j];
    //             }
    //             else {
    //                 std::cout<<i<<"|"<<matriz[i][j];
    //             }
    //         }
    //     } 
    //     std::cout<<"|"<< endl;
    // }


void eliminarTablero(Casillero **tablero) {
    for (int i = 0; i < ANCHODELTABLERO; i++) {
        delete [] tablero[i];
    }
    delete [] tablero;
}

