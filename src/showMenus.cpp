#include "../include/showMenus.h"
#include"../include/chosePlayer.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void showPlayerWinner(pInGame player){
	std::cout<<"******** RESULTADOS DE LA PARTIDA **************\n";
	std::cout<<"Jugador "<<player.username<<" Ha ganado!!!\n\n"
		<<"Nombre Completo: "<<player.name<<" "<<player.surname<<'\n';
}

void showMainMenu() {
  printf("************* PRINCIPAL **************** \n"
         "1- Generar tablero \n"
         "2- Registrar jugadores \n"
         "3- Listar jugadores \n"
         "4- Jugar \n"
         "5- Salir \n"
         "******************************************* \n"
         "Elija una opcion: ");
}

void showPlayMenu() {
  printf("\n********* Comienza la aventura ***********\n"
         "1- Seleccionar jugadores\n"
         "2- Lanzamiento de dados\n"
         "3- Salir\n"
         "******************************************\n"
         "Elija una opcion: ");
}

void showPlayerResults(std::string username, std::pair<int, int> dices,
                       std::vector<bool> isSpecial, int foundNumber,
                       int score) {
  std::cout << "Turno de jugador: " << username << '\n';
  // todo: make sleep() here;
  std::cout << "Lanzando dados...\n";
  std::cout << "Dado 1: " << dices.first << " - Dado 2: " << dices.second
            << '\n';
  std::cout << "Numero Encontrado: " << foundNumber;
	// FIXME: Make an structure for isSpecial
  if (isSpecial[0])
    std::cout << " (primo) ";
  if (isSpecial[1])
    std::cout << " (capicua) ";
  if (isSpecial[2])
    std::cout << " (diagonal) ";
  if (isSpecial[3])
    std::cout << " (amigo) 1 turno ";
  if (isSpecial[4])
    std::cout << " (perfecto) 2 turnos";
  std::cout << "\npuntaje: " << score << '\n';
}
