#include "registerPlayer.h"
#include <iostream>
#include <string>

typedef struct PInGame {

  std::string name;
  std::string surname;
  std::string username;
  int turns = 1;
  int points = 0;

} pInGame;


bool searchPlayer(std::string username, std::vector<player> &playersData,
                  std::vector<pInGame> &players, int p = 0) {

  for (int i = 0; i < playersData.size(); i++) {
    if (playersData[i].username == username || !playersData[i].playing) {
      playersData[i].playing = true;
      players[p].name = playersData[i].name;
      players[p].surname = playersData[i].surname;
      players[p].username = playersData[i].username;
      return true;
    }
  }

  return false;
}

std::vector<pInGame> chosePlayers() {

  std::vector<player> playersData = getPlayersData();
  std::vector<pInGame> players(2);

  for (int i = 0; i < 2; i++) {
    bool selected = false;
    while (selected) {
      printf("SELECIONAR JUGADORES\n");
      printf("Ingre el apodo del jugador %d: ", i + 1);
      std::string username;
      std::cin >> username;
      if (searchPlayer(username, playersData, players, i)) {
        selected = true;
        std::cout << players[i].username << "fue seleccionado!\n";
      } else {
        std::cout << username << "No esta registrado\n";
      }
    }
  }

  return players;

}
