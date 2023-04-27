#include "tablero.h"
#include <iostream>

// void crearTablero(Casillero **&tablero)
// {
//     tablero = new Casillero *[ANCHODELTABLERO];
//     for (int i = 0; i < ANCHODELTABLERO; i++)
//     {
//         tablero[i] = new Casillero[ALTODELTABLERO];
//         for (int j = 0; j < ALTODELTABLERO; j++)
//         {
//             tablero[i][j].ficha = BLANCO;
//             tablero[i][j].activo = false;
//             tablero[i][j].cantidadDeTurnosActivo = 0;
//         }
//     }
// }
void crearTablero(Casillero **&tablero)
{
    tablero = new Casillero*[ANCHODELTABLERO];
    for (int i = 0; i < ANCHODELTABLERO; i++)
    {
        tablero[i] = new Casillero[ALTODELTABLERO];
        for (int j = 0; j < ALTODELTABLERO; j++)
        {
            tablero[i][j].ficha = BLANCO;
            tablero[i][j].activo = false;
            tablero[i][j].cantidadDeTurnosActivo = 0;
            tablero[i][j].jugadorDeMina = 0;
            tablero[i][j].tieneBomba = false;
            tablero[i][j].soldado.x = i;
            tablero[i][j].soldado.y = j;
            tablero[i][j].soldado.jugador = 0;
        }
    }
}
void cargarTablero(Casillero **tablero)
{
    // Colocar fichas de jugador 1
    for (int i = 0; i < 4; i++)
    {
        tablero[i][0].ficha = JUGADOR1;
    }
    // Colocar fichas de jugador 2
    for (int i = 0; i < 4; i++)
    {
        tablero[i][ALTODELTABLERO - 1].ficha = JUGADOR2;
    }
}
void mostrarTablero(Casillero **tablero, int jugador) {
    std::cout << std::endl;
    char blancoFalso = ' . ';
    std::cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19" << std::endl;
    std::cout << "   --------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < ALTODELTABLERO; i++) {
        if (i < 10) {
            std::cout << " " << i << " ";
        }
        else {
            std::cout << i << " ";
        }
        for (int j = 0; j < ANCHODELTABLERO; j++) {
            switch (tablero[i][j].ficha) {
                case BLANCO:
                    std::cout << "| . ";
                    break;
                case JUGADOR1:
                    if (tablero[i][j].soldado.jugador == 1) {
                        std::cout << "| S1";
                    } else {
                        std::cout << "| 1 ";
                    }
                    break;
                case JUGADOR2:
                    if (tablero[i][j].soldado.jugador == 2) {
                        std::cout << "| S2";
                    } else {
                        std::cout << "| 2 ";
                    }
                    break;
                case MINA:
                    if (tablero[i][j].jugadorDeMina == jugador) {
                        std::cout << "| B" << jugador;
                    } else {
                        std::cout << "| M ";
                    }
                    break;
                case INACTIVA:
                    std::cout << "|   ";
                    break;
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "   --------------------------------------------------------------------------------" << std::endl;
    }
}


// void mostrarTablero(Casillero **tablero, int jugador) {
//     std::cout << std::endl;
//     std::cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19" << std::endl;
//     std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     for (int i = 0; i < ALTODELTABLERO; i++) {
//         if (i < 10) {
//             std::cout << " " << i << " ";
//         }
//         else {
//             std::cout << i << " ";
//         }
//         for (int j = 0; j < ANCHODELTABLERO; j++) {
//             if (tablero[i][j].cantidadDeTurnosActivo > 0) {
//                 std::cout << "| X ";
//             }
//             else if (tablero[i][j].tieneBomba && tablero[i][j].jugadorDeMina == jugador) {
//                 std::cout << "| B" << jugador;
//             }
//             else {
//                 switch (tablero[i][j].ficha) {
//                     case BLANCO:
//                         std::cout << "| . ";
//                         break;
//                     case JUGADOR1:
//                         if (tablero[i][j].soldado.jugador == 1) {
//                             std::cout << "| S1";
//                         } else {
//                             std::cout << "| 1 ";
//                         }
//                         break;
//                     case JUGADOR2:
//                         if (tablero[i][j].soldado.jugador == 2) {
//                             std::cout << "| S2";
//                         } else {
//                             std::cout << "| 2 ";
//                         }
//                         break;
//                     case MINA:
//                         std::cout << "| M ";
//                         break;
//                     case INACTIVA:
//                         std::cout << "|   ";
//                         break;
//                 }
//             }
//         }
//         std::cout << "|" << std::endl;
//         std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     }
// }




// void mostrarTablero(Casillero **tablero){

// }
// void mostrarTablero(Casillero **tablero) {
//     std::cout << std::endl;
//     std::cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19" << std::endl;
//     std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     for (int i = 0; i < ALTODELTABLERO; i++) {
//         if (i < 10) {
//             std::cout << " " << i << " ";
//         }
//         else {
//             std::cout << i << " ";
//         }
//         for (int j = 0; j < ANCHODELTABLERO; j++) {
//             if (tablero[i][j].cantidadDeTurnosActivo > 0) {
//                 std::cout << "| X ";
//             }
//             else if (tablero[i][j].tieneBomba) {
//                 std::cout << "| B" << tablero[i][j].jugadorDeMina;
//             }
//             else {
//                 switch (tablero[i][j].ficha) {
//                     case BLANCO:
//                         std::cout << "| . ";
//                         break;
//                     case JUGADOR1:
//                         if (tablero[i][j].soldado.jugador == 1) {
//                             std::cout << "| S1";
//                         } else {
//                             std::cout << "| 1 ";
//                         }
//                         break;
//                     case JUGADOR2:
//                         if (tablero[i][j].soldado.jugador == 2) {
//                             std::cout << "| S2";
//                         } else {
//                             std::cout << "| 2 ";
//                         }
//                         break;
//                     case MINA:
//                         std::cout << "| M ";
//                         break;
//                     case INACTIVA:
//                         std::cout << "|   ";
//                         break;
//                 }
//             }
//         }
//         std::cout << "|" << std::endl;
//         std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     }
// }

// tablero.cpp

// #include "tablero.h"
// #include <iostream>
// void crearTablero(Casillero **&tablero) {
//     tablero = new Casillero*[ANCHODELTABLERO];
//     for (int i = 0; i < ANCHODELTABLERO; i++) {
//         tablero[i] = new Casillero[ALTODELTABLERO];
//         for (int j = 0; j < ALTODELTABLERO; j++) {
//             // tablero[i][j].ficha = BLANCO;
//             tablero[i][j].activo = false;
//             tablero[i][j].cantidadDeTurnosActivo = 0;
//         }
//     }
// }


// void mostrarTablero(Casillero **tablero)
// {
//     std::cout << std::endl;
//     std::cout << " 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19" << std::endl;
//     std::cout << " --------------------------------------------------------------------------------" << std::endl;
//     for (int i = 0; i < ALTODELTABLERO; i++)
//     {
//         if (i < 10)
//         {
//             std::cout << " " << i << " ";
//         }
//         else
//         {
//             std::cout << i << " ";
//         }
//         for (int j = 0; j < ANCHODELTABLERO; j++)
//         {
//             if (tablero[i][j].cantidadDeTurnosActivo > 0)
//             {
//                 std::cout << "| X ";
//             }
//             else if (tablero[i][j].tieneBomba)
//             {
//                 if (tablero[i][j].jugadorDeMina == 1)
//                 {
//                     std::cout << "| B1";
//                 }
//                 else if (tablero[i][j].jugadorDeMina == 2)
//                 {
//                     std::cout << "| B2";
//                 }
//             }
//             else
//             {
//                 switch (tablero[i][j].ficha)
//                 {
//                 case BLANCO:
//                     std::cout << "| . ";
//                     break;
//                 case JUGADOR1:
//                     if (tablero[i][j].soldado.jugador == 1)
//                     {
//                         std::cout << "| S1";
//                     }
//                     else
//                     {
//                         std::cout << "| 1 ";
//                     }
//                     break;
//                 case JUGADOR2:
//                     if (tablero[i][j].soldado.jugador == 2)
//                     {
//                         std::cout << "| S2";
//                     }
//                     else
//                     {
//                         std::cout << "| 2 ";
//                     }
//                     break;
//                 }
//             }
//         }
//         std::cout << "|" << std::endl;
//         std::cout << " --------------------------------------------------------------------------------" << std::endl;
//     }
// }
// CON ESTE FUNCIONA
// void mostrarTablero(Casillero **tablero) {
//     std::cout << std::endl;
//     std::cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19" << std::endl;
//     std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     for (int i = 0; i < ALTODELTABLERO; i++) {
//         if (i < 10) {
//             std::cout << " " << i << " ";
//         }
//         else {
//             std::cout << i << " ";
//         }
//         for (int j = 0; j < ANCHODELTABLERO; j++) {
//             if (tablero[i][j].cantidadDeTurnosActivo > 0) {
//                 std::cout << "| X ";
//             }
//             else {
//                 switch (tablero[i][j].ficha) {
//                     case BLANCO:
//                         std::cout << "| . ";
//                         break;
//                     case JUGADOR1:
//                         std::cout << "| 1 ";
//                         break;
//                     case JUGADOR2:
//                         std::cout << "| 2 ";
//                         break;
//                     case MINA:
//                         std::cout << "| M ";
//                         break;
//                     case INACTIVA:
//                         std::cout << "| X ";
//                         break;
//                 }
//             }
//         }
//         std::cout << "|" << std::endl;
//         std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     }
// }
// void mostrarTablero(Casillero **tablero) {
//     std::cout << std::endl;
//     std::cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19" << std::endl;
//     std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     for (int i = 0; i < ALTODELTABLERO; i++) {
//         if (i < 10) {
//             std::cout << " " << i << " ";
//         }
//         else {
//             std::cout << i << " ";
//         }
//         for (int j = 0; j < ANCHODELTABLERO; j++) {
//             if (tablero[i][j].cantidadDeTurnosActivo > 0) {
//                 std::cout << "| X ";
//             }
//             else if (tablero[i][j].tieneBomba) {
//                 std::cout << "| B" << tablero[i][j].jugadorDeMina;
//             }
//             else {
//                 switch (tablero[i][j].ficha) {
//                     case BLANCO:
//                         std::cout << "| . ";
//                         break;
//                     case JUGADOR1:
//                         if (tablero[i][j].soldado.jugador == 1) {
//                             std::cout << "| S1";
//                         } else {
//                             std::cout << "| 1 ";
//                         }
//                         break;
//                     case JUGADOR2:
//                         if (tablero[i][j].soldado.jugador == 2) {
//                             std::cout << "| S2";
//                         } else {
//                             std::cout << "| 2 ";
//                         }
//                         break;
//                     case MINA:
//                         std::cout << "| M ";
//                         break;
//                     case INACTIVA:
//                         std::cout << "|   ";
//                         break;
//                 }
//             }
//         }
//         std::cout << "|" << std::endl;
//         std::cout << "   --------------------------------------------------------------------------------" << std::endl;
//     }
// }

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

void eliminarTablero(Casillero **tablero)
{
    for (int i = 0; i < ANCHODELTABLERO; i++)
    {
        delete[] tablero[i];
    }
    delete[] tablero;
}
