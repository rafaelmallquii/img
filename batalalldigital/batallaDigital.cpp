#include "batallaDigital.h"
#include "tablero.h"
#include <string>
#include <iostream>

void jugar(Casillero **tablero)
{
    bool termino = false;
    int turno = 1, numeroJugada = 0;
    int ficha =  0;

    while (!termino)
    {

        mostrarTablero(tablero, turno);
        if (numeroJugada == 0)
        {
            ficha = JUGADOR1;
        }
        // moverFicha
        imprimeCoordenadasjugadores(tablero, turno);
        seleccionDeSoldado(tablero, ficha);

        if (turno == 1)
        {
            turno = 2;
            ficha = JUGADOR2;
        }
        else
        {
            turno = 1;
            ficha = JUGADOR1;
        }
        system("pause");
        // system("cls");
        numeroJugada++;
    }
}

void imprimeCoordenadasjugadores(Casillero **tablero, int turno)
{

    if (turno == 1)
    {
        std::cout << "Jugador 1" << std::endl;
    }
    else
    {
        std::cout << "Jugador 2" << std::endl;
    }
    for (int i = 0; i < ALTODELTABLERO; i++)
    {
        for (int j = 0; j < ANCHODELTABLERO; j++)
        {
            if (tablero[i][j].ficha == turno)
            {
                std::cout<< "Ficha: " <<  i + 1 << " Coordenadas: " << i << " " << j << std::endl;
            }
        }
    }
}

// void seleccionDeSoldado(Casillero **tablero, int ficha)
// {
//     int soldado;
//     int contadorJugadores = 0;
//     char respuesta;
//     std::cout << "Ingrese el numero del soldado que desea mover: ";
//     std::cin >> soldado;

//     for (int i = 0; i < ALTODELTABLERO; i++){
//         for (int j = 0; j < ANCHODELTABLERO; j++){
//             if (tablero[i][j].ficha == ficha){
//                 contadorJugadores++;
//                 if (contadorJugadores == soldado){
//                     std::cout<<"quiere poner una mina? (s/n):";
//                     std::cin>>respuesta;
//                     if( respuesta == 's'){
//                         colocarMina(tablero,i,j,ficha);
//                     }
                
//                 moverFicha(tablero, i, j);
//                 }
//             }
//         }
//     }
// }
void seleccionDeSoldado(Casillero **tablero, int ficha)
{
    int soldado;
    int contadorJugadores = 0;
    char respuesta;
    std::cout << "Ingrese el numero del soldado que desea mover: ";
    std::cin >> soldado;

    int antiguaFila, antiguaColumna; // Nuevas variables para almacenar las coordenadas antiguas

    for (int i = 0; i < ALTODELTABLERO; i++){
        for (int j = 0; j < ANCHODELTABLERO; j++){
            if (tablero[i][j].ficha == ficha){
                contadorJugadores++;
                if (contadorJugadores == soldado){
                    std::cout<<"quiere poner una mina? (s/n):";
                    std::cin>>respuesta;
                    if( respuesta == 's'){
                        // Almacenar las coordenadas antiguas antes de llamar a moverFicha()
                        antiguaFila = i;
                        antiguaColumna = j;
                        moverFicha(tablero, i, j);
                        colocarMina(tablero,antiguaFila,antiguaColumna,ficha);
                        
                    }
                    else{
                        moverFicha(tablero, i, j);}
                
                }
            }
        }
    }
}

// void activarMinas(Casillero **tablero, int i, int j){
 
//     if (tablero[i][j].ficha == MINA){
//         tablero[i][j].ficha = BLANCO;
//         for (int k = i - 1; k <= i + 1; k++){
//             for (int l = j - 1; l <= j + 1; l++){
//                 if (k >= 0 && k < ALTODELTABLERO && l >= 0 && l < ANCHODELTABLERO){
//                     if (tablero[k][l].ficha == JUGADOR1 || tablero[k][l].ficha == JUGADOR2){
//                         tablero[k][l].ficha = BLANCO;
//                     }
//                 }
//             }
//         }
//     }
// }
// void mostrarMina(Casillero **tablero, int i, int j){
//     if (tablero[i][j].ficha == MINA){
//         tablero[i][j].ficha = BLANCO;
//         for (int k = i - 1; k <= i + 1; k++){
//             for (int l = j - 1; l <= j + 1; l++){
//                 if (k >= 0 && k < ALTODELTABLERO && l >= 0 && l < ANCHODELTABLERO){
//                     if (tablero[k][l].ficha == JUGADOR1 || tablero[k][l].ficha == JUGADOR2){
//                         tablero[k][l].ficha = BLANCO;
//                     }
//                 }
//             }
//         }
//     }
// }


// Función que coloca una mina en un casillero del tablero
// void colocarMina( Casillero **tablero , int x, int y, int jugador) {
//         tablero[x][y].ficha = MINA;
//         tablero[x][y].activo = true;
//         tablero[x][y].cantidadDeTurnosActivo = 0;
//         tablero[x][y].jugadorDeMina = jugador;
// }
// void colocarMina(Casillero **tablero, int x, int y, int jugador) {
//     tablero[x][y].tieneBomba = true; // se asigna true al miembro tieneBomba del casillero donde se colocó la mina
//     tablero[x][y].ficha = MINA;
//     tablero[x][y].activo = true;
//     tablero[x][y].cantidadDeTurnosActivo = 0;
//     tablero[x][y].jugadorDeMina = jugador;
// }
void colocarMina(Casillero **tablero, int x, int y, int jugador) {
    tablero[x][y].tieneBomba = true;
    tablero[x][y].ficha = MINA;
    tablero[x][y].activo = true;
    tablero[x][y].cantidadDeTurnosActivo = 0;
    tablero[x][y].jugadorDeMina = jugador;
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

void moverFicha(Casillero * *tablero, int i, int j)
    {

        char direccion;
        std::cout << "Ingrese la direccion a la que desea mover el soldado: ";
        std::cin >> direccion;
        int fil = i;
        int col = j;

        switch (direccion)
        {
        case ARRIBA:
            if (tablero[fil - 1][col].ficha == BLANCO && fil - 1 >= 0){
                tablero[fil - 1][col].ficha = tablero[fil][col].ficha;
                
                if(tablero[fil][col].tieneBomba == true){
                    tablero[fil][col].ficha = MINA;
                }
                else{
                    tablero[fil][col].ficha = BLANCO;
                }

                
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case ABAJO:
            if (tablero[fil + 1][col].ficha == BLANCO && fil + 1 < ALTODELTABLERO)
            {
                tablero[fil + 1][col].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
                {
                    /* code */
                }
                
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case DERECHA:
            if (tablero[fil][col + 1].ficha == BLANCO && col + 1 < ANCHODELTABLERO)
            {
                tablero[fil][col + 1].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case IZQUIERDA:
            if (tablero[fil][col - 1].ficha == BLANCO && col - 1 >= 0)
            {
                tablero[fil][col - 1].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case DIAGONALARRIBADERECHA:
            if (tablero[fil - 1][col + 1].ficha == BLANCO && fil - 1 >= 0 && col + 1 < ANCHODELTABLERO)
            {
                tablero[fil - 1][col + 1].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case DIAGONALARRIBAIZQUIERDA:
            if (tablero[fil - 1][col - 1].ficha == BLANCO && fil - 1 >= 0 && col - 1 >= 0)
            {
                tablero[fil - 1][col - 1].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case DIAGONALABAJOIZQUIERDA:
            if (tablero[fil + 1][col - 1].ficha == BLANCO && fil + 1 < ALTODELTABLERO && col - 1 >= 0)
            {
                tablero[fil + 1][col - 1].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        case DIAGONALABAJODERECHA:
            if (tablero[fil + 1][col + 1].ficha == BLANCO && fil + 1 < ALTODELTABLERO && col + 1 < ANCHODELTABLERO)
            {
                tablero[fil + 1][col + 1].ficha = tablero[fil][col].ficha;
                if (tablero[fil][col].tieneBomba == true)
                {
                    tablero[fil][col].ficha = MINA;
                }
                else
                {
                    tablero[fil][col].ficha = BLANCO;
                }
            }
            else
            {
                std::cout << "Movimiento invalido" << std::endl;
            }
            break;
        default:
            std::cout << "Movimiento invalido" << std::endl;
            break;
        }
    }

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
