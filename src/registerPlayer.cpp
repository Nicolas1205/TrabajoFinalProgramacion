#include "../include/registerPlayer.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Player> get_players_data() {

  std::ifstream i("../data/players.txt");

  int players_sz;

  i >> players_sz;

  if (!players_sz) {
    std::vector<Player> playersData;
    return playersData;
  }

  std::vector<Player> players_data(players_sz);

  for (int iter = 0; iter < players_sz; iter++) {
    i >> players_data[iter].username >> players_data[iter].name >>
        players_data[iter]
            .surname; //>>playersData[i].looses>>playersData[i].wins;
  }

  return players_data;
}

bool compare(Player a, Player b) {
  if (a.surname < b.surname) {
    return 1;
  } else
    return 0;
}

void post_player(std::string &name, std::string &surname, std::string &username,
                 std::vector<Player> &playersData) {

  std::ofstream o("../data/players.txt");

  for (int i = 0; i < playersData.size(); i++) {
    if (playersData[i].username == username) {
      std::cout << "USUARIO YA EXISTENTE\n";
      o << playersData.size() << "\n";
      for (int i = 0; i < playersData.size(); i++) {
        o << playersData[i].username << "\n\t";
        o << playersData[i].name << "\n\t";
        o << playersData[i].surname << "\n";
      }
      return;
    }
  }

  playersData.push_back({name, surname, username});

  sort(playersData.begin(), playersData.end(), compare);

  o << playersData.size() << "\n";

  for (int i = 0; i < playersData.size(); i++) {

    o << playersData[i].username << "\n\t";
    o << playersData[i].name << "\n\t";
    o << playersData[i].surname << "\n";
  }
}

void show_players() {

  std::vector<Player> playersData = get_players_data();

  for (int i = 0; i < playersData.size(); i++) {
    std::cout << "Usuario: " << playersData[i].username << "\n\t";
    std::cout << "Nombre: " << playersData[i].name << "\n\t";
    std::cout << "Apellido: " << playersData[i].surname << "\n";
  }
}
