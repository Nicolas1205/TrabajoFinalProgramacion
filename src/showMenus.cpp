#include "../include/showMenus.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void showMainMenu() {
  printf("************* principal **************** \n"
         "1- generar tablero \n"
         "2- registrar jugadores \n"
         "3- listar jugadores \n"
         "4- jugar \n"
         "5- salir \n"
         "******************************************* \n"
         "elija una opcion: \n");
}

void showPlayMenu() {
  printf("********* comienza la aventura ***********\n"
         "1- seleccionar jugadores\n"
         "2- lanzamiento de dados\n"
         "3- salir\n"
         "******************************************\n"
         "elija una opcion: ");
}

void showPlayerResults(std::string username, std::pair<int, int> dices,
                       std::vector<bool> isSpecial, int foundNumber,
                       int score) {
  std::cout << "turno de jugador: " << username << '\n';
  // todo: make sleep() here;
  std::cout << "lanzando dados...\n";
  std::cout << "dado 1: " << dices.first << " - dado 2: " << dices.second
            << '\n';
  std::cout << "numero encontrado: " << foundNumber;
  if (isSpecial[0])
    std::cout << "(primo) ";
  if (isSpecial[1])
    std::cout << "(capicua) ";
  if (isSpecial[2])
    std::cout << "(diagonal) ";
  if (isSpecial[3])
    std::cout << "(amigo) 1 turno ";
  if (isSpecial[4])
    std::cout << "(perfecto) 2 turnos\n";
  std::cout << "puntaje: " << score << '\n';
}
