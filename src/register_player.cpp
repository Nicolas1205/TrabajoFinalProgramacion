#include "../include/register_player.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Player> get_players_data() {

  std::ifstream i("../data/players.txt");

  int players_sz;

  i >> players_sz;

  if (!players_sz) {
    std::vector<Player> players_data;
    return players_data;
  }

  std::vector<Player> players_data(players_sz);

  for (int iter = 0; iter < players_sz; iter++) {
    i >> players_data[iter].username >> players_data[iter].name >>
        players_data[iter].surname;
  }

  return players_data;
}

bool comp(Player a, Player b) {
  if (a.surname < b.surname) {
    return 1;
  } else
    return 0;
}

void post_player(std::string name, std::string surname, std::string username,
                 std::vector<Player> &players_data) {

  std::ofstream o("../data/players.txt");

  for (int i = 0; i < players_data.size(); i++) {
    if (players_data[i].username == username) {
      std::cout << "USUARIO YA EXISTENTE\n";
      o << players_data.size() << "\n";
      for (int i = 0; i < players_data.size(); i++) {
        o << players_data[i].username << "\n\t";
        o << players_data[i].name << "\n\t";
        o << players_data[i].surname << "\n";
      }
      return;
    }
  }

  players_data.push_back({name, surname, username});

  sort(players_data.begin(), players_data.end(), comp);

  o << players_data.size() << "\n";

  for (int i = 0; i < players_data.size(); i++) {
    o << players_data[i].username << "\n\t";
    o << players_data[i].name << "\n\t";
    o << players_data[i].surname << "\n";
  }
}

void show_players() {

  std::vector<Player> players_data = get_players_data();

  for (int i = 0; i < players_data.size(); i++) {
    std::cout << "Usuario: " << players_data[i].username << "\n\t";
    std::cout << "Nombre: " << players_data[i].name << "\n\t";
    std::cout << "Apellido: " << players_data[i].surname << "\n";
  }
}
