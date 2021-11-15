#include "../include/show_menus.h"
#include "../include/chose_player.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void show_player_winner(Player *winner) {
  std::cout << "******** RESULTADOS DE LA PARTIDA **************\n";
  std::cout << "Jugador: " << winner->username << " ha ganado!!!\n\n"
            << "Nombre Completo: " << winner->name << " " << winner->surname
            << '\n';
  std::cout << "Puntaje Total: " << winner->points << '\n';
}

void show_main_menu(bool table_created, size_t players_sz, int *golden_score) {

  printf("************* PRINCIPAL **************** \n"
         "1- Generar tablero  ");

  if (table_created)
    printf("(TABLERO GENERADO) Puntaje Dorado: %d", *golden_score);

  printf("\n2- Registrar jugadores ");

  if (players_sz)
    printf("(Existen Jugadores Registrados)");
  if (players_sz >= 2)
    printf(" %zu ", players_sz);
  else
    printf(" se necesitan 2 o mas jugadores, ahora mismo %zu", players_sz);
  if (players_sz == 10)
    printf(" (No se pueden registar mas jugadores) ");

  printf("\n3- Listar jugadores \n"
         "4- Jugar \n"
         "5- Salir \n"
         "******************************************* \n"
         "Elija una opcion: ");
}

void show_play_menu(std::vector<Player> &players) {
  printf("\n********* Comienza la aventura ***********\n");

  printf("1- Seleccionar jugadores ");

  if (players.size())
    std::cout << " (Jugador 1: " << players[0].username
              << " Jugador 2: " << players[1].username << ")\n";
  else
    printf(" (No hay jugadores Seleccionados)\n");

  printf("2- Lanzamiento de dados\n"
         "3- Salir\n"
         "******************************************\n"
         "Elija una opcion: ");
}

void show_player_results(Player *player, std::pair<int, int> dices,
                         bool *specials, int found_number, int score) {

  std::cout << "\n\nTurno de jugador: " << player->username << '\n';
  std::cout << "Lanzando dados...\n";
  std::cout << "Dado 1: " << dices.first << " - Dado 2: " << dices.second
            << '\n';
  std::cout << "Numero Encontrado: " << found_number;

  std::vector<std::string> messages = {" (primo) ", " (capicua) ",
                                       " (amigo) 1 turno ",
                                       " (perfecto 2 turnos) ", " (diagonal) "};

  for (int i = 0; i < 5; i++) {
    if (specials[i])
      std::cout << messages[i];
  }

  std::cout << "\nPuntaje : " << score << '\n';
}
