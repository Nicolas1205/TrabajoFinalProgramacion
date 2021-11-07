#include "../include/genTable.h"
#include "../include/play.h"
#include "../include/registerPlayer.h"
#include "../include/showMenus.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {

  char menuOp;
  int goldenScore = 0;
  std::vector<std::vector<Cell>> table;
  std::vector<Player> playersData = get_players_data();
  std::vector<bool> loaded(2);

  while (1) {
    std::cout << "\033[2J\033[1;1H";
    show_main_menu(loaded[0], playersData.size(), playersData.size(),
                   goldenScore);
    std::cin >> menuOp;
    if (menuOp == '1') {
      table = gen_table(goldenScore);
      loaded[0] = 1;
    }
    if (menuOp == '2') {

      std::cout << "\033[2J\033[1;1H";
      std::string name, surname, username;
      puts("*************** Registrar Usario **************\n");
      printf("\nNombre: ");
      std::cin >> name;
      printf("\nApellido: ");
      std::cin >> surname;
      printf("\nNombre de Usario: ");
      std::cin >> username;
      post_player(name, surname, username, playersData);
      loaded[1] = 1;
    }
    if (menuOp == '3') {
      std::cout << "\033[2J\033[1;1H";
      show_players();
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    if (menuOp == '4') {
      if (loaded[0] && playersData.size() >= 2) {
        play(table, goldenScore);
      }
    }
    if (menuOp == '5')
      break;
  }

  return 0;
}
