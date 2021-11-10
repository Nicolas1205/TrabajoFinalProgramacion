#include "../include/gen_table.h"
#include "../include/play.h"
#include "../include/register_player.h"
#include "../include/show_menus.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {

  const char *CLEAR = "\033[2J\033[1;1H";

  char menu_option;

  int golden_score = 0;

  std::vector<std::vector<Cell>> table;
  std::vector<Player> players_data = get_players_data();
  std::vector<bool> loaded(2, 0);

  while (1) {
    std::cout << CLEAR;
    show_main_menu(loaded[0], players_data.size(), &golden_score);
    std::cin >> menu_option;
    if (menu_option == '1') {
      table = gen_table(&golden_score);
      loaded[0] = 1;
    }
    if (menu_option == '2') {

      if (players_data.size() == 10)
        continue;

      std::cout << CLEAR;
      std::string name, surname, username;
      puts("*************** Registrar Usario **************");
      printf("\nNombre: ");
      std::cin >> name;
      printf("\nApellido: ");
      std::cin >> surname;
      printf("\nNombre de Usario: ");
      std::cin >> username;
      post_player(name, surname, username, players_data);
      loaded[1] = 1;
    }
    if (menu_option == '3') {
      std::cout << CLEAR;
      show_players();
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    if (menu_option == '4') {
      if (loaded[0] && players_data.size() >= 2) {
        play(table, &golden_score);
      }
    }
    if (menu_option == '5')
      break;
  }

  return 0;
}
