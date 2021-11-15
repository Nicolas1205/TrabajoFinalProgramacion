#include "../include/play.h"
#include "../include/chose_player.h"
#include "../include/gen_table.h"
#include "../include/register_player.h"
#include "../include/show_menus.h"
#include "../include/sieve.h"
#include <chrono>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::random_device r;
std::default_random_engine el(r());
std::uniform_int_distribution<int> uniform_dist(0, 9);

const char *CLEAR = "\033[2J\033[1;1H";

std::pair<int, int> get_dices() {
  return std::make_pair(uniform_dist(el), uniform_dist(el));
}

int get_score(std::vector<std::vector<Cell>> &table, int d1, int d2) {

  int score = 0, value = table[d1][d2].cell_value;

  if (table[d1][d2].specials[0] && table[d1][d2].specials[1] &&
      table[d1][d2].specials[4]) {
    score = value * 4;
  } else if (table[d1][d2].specials[0] && table[d1][d2].specials[1]) {
    score = value * 3;
  } else if (table[d1][d2].specials[0] ||
             table[d1][d2].specials[1] && table[d1][d2].specials[4]) {
    score = value * 2;
  } else if (table[d1][d2].specials[0] || table[d1][d2].specials[1]) {
    score = value;
  }

  return score;
}

void throw_dices(std::vector<Player> &players,
                 std::vector<std::vector<Cell>> &table, int *golden_score) {

  bool player_turn = 0;
  while (1) {
    while (players[player_turn].turns--) {
      auto [d1, d2] = get_dices();

      int score = 0;

      if (!table[d1][d2].is_catched) {
        table[d1][d2].is_catched = true;
        table[d1][d2].player_catcher = players[player_turn].username;
      } else if (table[d1][d2].is_catched &&
                 table[d1][d2].player_catcher !=
                     players[player_turn].username) {

        show_player_results(&players[player_turn], std::make_pair(d1, d2),
                            table[d1][d2].specials, table[d1][d2].cell_value,
                            score);

        bool property_of = player_turn == 1 ? 0 : 1;
        std::cout << "\nYA HA SIDO TOMADA POR " << players[property_of].username
                  << '\n';
        players[player_turn].turns++;
        continue;
      }

      players[player_turn].turns += table[d1][d2].specials[2] ? 1 : 0;
      players[player_turn].turns += table[d1][d2].specials[3] ? 2 : 0;

      score = get_score(table, d1, d2);
      players[player_turn].points += score;

      if (!score)
        players[player_turn].nothing_catched++;

      show_player_results(&players[player_turn], std::make_pair(d1, d2),
                          table[d1][d2].specials, table[d1][d2].cell_value,
                          score);

      // std::this_thread::sleep_for(std::chrono::seconds(1));

      if (players[player_turn].nothing_catched >= 3) {
        std::cout << players[player_turn].username
                  << " no ha atrapado numeros especiales"
                     " -10 puntos\n";
        players[player_turn].points -= 10;
        players[player_turn].nothing_catched = 0;
      }

      if (players[player_turn].points >= *golden_score) {
        show_player_winner(&players[player_turn]);
        return;
      }
    }

    player_turn = player_turn == 0 ? 1 : 0;
    players[player_turn].turns = 1;
  }
}

void play(std::vector<std::vector<Cell>> &table, int *golden_score) {

  char play_options;
  std::vector<Player> players;
  bool loaded = 0;

  while (1) {
    std::cout << CLEAR;
    show_play_menu(players);

    scanf("%c", &play_options);

    if (play_options == '1') {
      std::cout << CLEAR;
      players = chose_players();
      loaded = 1;
    }
    if (play_options == '2') {
      std::cout << CLEAR;
      if (loaded) {
        throw_dices(players, table, golden_score);
        players[0].points = 0;
        players[1].points = 0;
        std::this_thread::sleep_for(std::chrono::seconds(5));
      }
    }
    if (play_options == '3')
      return;
  }
}
