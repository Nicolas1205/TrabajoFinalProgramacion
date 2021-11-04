#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>

void showMainMenu() {
  printf("************* PRINCIPAL **************** \n"
         "1- Generar Tablero \n"
         "2- Registrar Jugadores \n"
         "3- Listar Jugadores \n"
         "4- Jugar \n"
         "5- Salir \n"
         "******************************************* \n"
         "Elija una Opcion: \n");
}

void showPlayMenu() {
  printf("********* COMIENZA LA AVENTURA ***********\n"
         "1- Seleccionar jugadores\n"
         "2- Lanzamiento de Dados\n"
         "3- Salir\n"
         "******************************************\n"
         "Elija una Opcion: ");
}

void showPlayerResults(std::string username, std::pair<int, int> dices,
                    std::vector<bool> isSpecial,
                    int foundNumber , int score
){
  std::cout << "Turno de Jugador: " << username << '\n';
  // TODO: Make sleep() here;
  std::cout << "Lanzando Dados...\n";
  std::cout << "Dado 1: " << dices.first << " - Dado 2: " << dices.second<< '\n';
  std::cout << "Numero Encontrado: " << foundNumber;
  if(isSpecial[0]) std::cout<<"(PRIMO) ";
  if(isSpecial[1]) std::cout<<"(CAPICUA) ";
  if(isSpecial[2]) std::cout<<"(DIAGONAL) ";
  if(isSpecial[3]) std::cout<<"(AMIGO) 1 turno ";
  if(isSpecial[4]) std::cout<<"(PERFECTO) 2 turnos\n";
  std::cout<<"Puntaje: "<<score<<'\n';

}
