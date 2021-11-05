#include"../include/chosePlayer.h"
#include "../include/registerPlayer.h"
#include <iostream>
#include <string>


bool searchPlayer(std::string username, std::vector<player> &playersData,
                  std::vector<pInGame> &players, int p) {

  for (int i = 0; i < playersData.size(); i++) {
    if (playersData[i].username == username && !playersData[i].playing) {
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
    bool selected = true;
    while (selected) {

      printf("SELECIONAR JUGADORES\n");
      printf("Ingrese username del jugador %d: ", i + 1);
      std::string username;
      std::cin>>username;
      if (searchPlayer(username, playersData, players, i)) {
        selected = false;
        std::cout << players[i].username << " fue seleccionado!\n";
      } else {
        std::cout << username << "No esta registrado\n";
      }

    }
  }

  return players;

}
