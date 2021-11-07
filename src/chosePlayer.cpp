#include "../include/chosePlayer.h"
#include "../include/registerPlayer.h"
#include <iostream>
#include <string>

bool search_player(std::string username, std::vector<Player> &playersData,
                   std::vector<Player> &players, int p) {

  for (int i = 0; i < playersData.size(); i++) {
    if (playersData[i].username == username) {
      if (!playersData[i].playing) {
        playersData[i].playing = true;
        players[p].name = playersData[i].name;
        players[p].surname = playersData[i].surname;
        players[p].username = playersData[i].username;
        return true;
      } else if (playersData[i].playing) {
        puts("ESTE JUGADOR YA FUE SELECCIONADO");
        return false;
      }
    }
  }
  puts("ESTE JUGADOR NO ESTA REGISTRADO");
  return false;
}

std::vector<Player> chose_players() {

  std::vector<Player> playersData = get_players_data();
  std::vector<Player> players(2);

  for (int i = 0; i < 2; i++) {
    bool selected = false;
    while (!selected) {

      printf("SELECIONAR JUGADORES\n");
      printf("Ingrese username del jugador %d: ", i + 1);
      std::string username;
      std::cin >> username;
      if (search_player(username, playersData, players, i)) {
        selected = true;
        std::cout << players[i].username << " fue seleccionado!\n";
      }
    }
  }

  return players;
}
