#include "../include/showMenus.h"
#include"../include/chosePlayer.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void showPlayerWinner(pInGame winner){
	std::cout<<"******** RESULTADOS DE LA PARTIDA **************\n";
	std::cout<<"Jugador: "<<winner.username<<" ha ganado!!!\n\n"
		<<"Nombre Completo: "<<winner.name<<" "<<winner.surname<<'\n';
	std::cout<<"Puntaje Total: "<<winner.points<<'\n';
}

void showMainMenu(bool tCreated , bool pExist , int size , int &goldenScore) {
  printf("************* PRINCIPAL **************** \n"
         "1- Generar tablero  ");

  if(tCreated) printf("(TABLERO GENERADO) Puntaje Dorado: %d" , goldenScore);

  printf("\n2- Registrar jugadores ");

  if(pExist) printf("(Existen Jugadores Registrados)");
  if(size >= 2) printf(" %d " , size);
  else printf(" se necesitan 2 o mas jugadores, ahora mismo %d" , size);

  printf("\n3- Listar jugadores \n"
         "4- Jugar \n"
         "5- Salir \n"
         "******************************************* \n"
         "Elija una opcion: ");
}

void showPlayMenu(std::vector<pInGame> &players) {
  printf("\n********* Comienza la aventura ***********\n");


  printf( "1- Seleccionar jugadores ");

  if(players.size()) std::cout<<" (Jugador 1: "<<players[0].username<<" Jugador 2: "<<players[1].username<<")\n";
  else printf(" (No hay jugadores Seleccionados)\n");

  printf("2- Lanzamiento de dados\n"
         "3- Salir\n"
         "******************************************\n"
         "Elija una opcion: ");
}

void showPlayerResults(pInGame player , std::pair<int, int> dices,
                       std::vector<bool> isSpecial, int foundNumber,
                       int score) {
  std::cout << "\n\nTurno de jugador: " << player.username << '\n';
  std::cout << "Lanzando dados...\n";
  std::cout << "Dado 1: " << dices.first << " - Dado 2: " << dices.second
            << '\n';
  std::cout << "Numero Encontrado: " << foundNumber;
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
  std::cout << "\nPuntaje : " << score << '\n';
}
