#include "../include/chose_player.h"
#include "../include/register_player.h"
#include <iostream>
#include <string>

bool search_player(std::string username, std::vector<Player> &players_data,
                   std::vector<Player> &players, int p) {

  for (int i = 0; i < players_data.size(); i++) {
    if (players_data[i].username == username) {
      if (!players_data[i].playing) {
        players_data[i].playing = true;
        players[p].name = players_data[i].name;
        players[p].surname = players_data[i].surname;
        players[p].username = players_data[i].username;
        return true;
      } else if (players_data[i].playing) {
        puts("ESTE JUGADOR YA FUE SELECCIONADO");
        return false;
      }
    }
  }
  puts("ESTE JUGADOR NO ESTA REGISTRADO");
  return false;
}

std::vector<Player> chose_players() {

  std::vector<Player> players_data = get_players_data();
  std::vector<Player> players(2);

  for (int i = 0; i < 2; i++) {
    bool selected = false;
    while (!selected) {

      printf("SELECIONAR JUGADORES\n");
      printf("Ingrese username del jugador %d: ", i + 1);
      // FIXME: FIX: if it doesn't work
      std::string username;
      std::cin >> username;
      if (search_player(username, players_data, players, i)) {
        selected = true;
        std::cout << players[i].username << " fue seleccionado!\n";
      }
    }
  }

  return players;
}
