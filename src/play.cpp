#include "../include/play.h"
#include "../include/chosePlayer.h"
#include "../include/genTable.h"
#include "../include/registerPlayer.h"
#include "../include/showMenus.h"
#include "../include/sieve.h"
#include <chrono>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::pair<int, int> get_dices() {
  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(0, 9);
  return std::make_pair(uniform_dist(el), uniform_dist(el));
}

int get_score(std::vector<std::vector<Cell>> &table, int d1, int d2) {

  int score = 0, value = table[d1][d2].cellValue;

  if (table[d1][d2].isPrime && table[d1][d2].isPalindrome &&
      table[d1][d2].inDiagonal) {
    score = value * 4;
  } else if (table[d1][d2].isPrime && table[d1][d2].isPalindrome) {
    score = value * 3;
  } else if (table[d1][d2].isPrime ||
             table[d1][d2].isPalindrome && table[d1][d2].inDiagonal) {
    score = value * 2;
  } else if (table[d1][d2].isPrime || table[d1][d2].isPalindrome) {
    score = value;
  }
  return score;
}

std::vector<bool> specials(std::vector<std::vector<Cell>> &table, int d1,
                           int d2) {
  std::vector<bool> isSpecial(5, 0);
  if (table[d1][d2].isPrime)
    isSpecial[0] = 1;
  if (table[d1][d2].isPalindrome)
    isSpecial[1] = 1;
  if (table[d1][d2].inDiagonal)
    isSpecial[2] = 1;
  if (table[d1][d2].isFriend)
    isSpecial[3] = 1;
  if (table[d1][d2].isPerfect)
    isSpecial[4] = 1;
  return isSpecial;
}

void throw_dices(std::vector<Player> &players,
                 std::vector<std::vector<Cell>> &table, int &goldenScore) {

  bool player_turn = 0;
  while (1) {
    while (players[player_turn].turns--) {
      auto [d1, d2] = get_dices();

      int score = 0;

      if (!table[d1][d2].isCatched) {
        table[d1][d2].isCatched = true;
        table[d1][d2].playerCatcher = players[player_turn].username;
      } else if (table[d1][d2].isCatched &&
                 table[d1][d2].playerCatcher != players[player_turn].username) {

        show_player_results(players[player_turn], std::make_pair(d1, d2),
                            specials(table, d1, d2), table[d1][d2].cellValue,
                            score);

        bool property_of = player_turn == 1 ? 1 : 0;
        std::cout << "\nYA HA SIDO TOMADA POR" << players[property_of].username
                  << '\n';
        players[player_turn].turns++;
        continue;
      }

      if (table[d1][d2].isFriend)
        players[player_turn].turns += 1;
      if (table[d1][d2].isPerfect)
        players[player_turn].turns += 2;

      score = get_score(table, d1, d2);

      players[player_turn].points += score;

      show_player_results(players[player_turn], std::make_pair(d1, d2),
                          specials(table, d1, d2), table[d1][d2].cellValue,
                          score);

      if (players[player_turn].points >= goldenScore) {
        show_player_winner(players[player_turn]);
        return;
      }
    }

    player_turn = player_turn == 0 ? 1 : 0;
    players[player_turn].turns = 1;
  }
}

void play(std::vector<std::vector<Cell>> &table, int &goldenScore) {

  char playOptions;
  std::vector<Player> players;
  bool loaded = 0;

  while (1) {
    std::cout << "\033[2J\033[1;1H";
    show_play_menu(players);

    scanf("%c", &playOptions);

    if (playOptions == '1') {
      std::cout << "\033[2J\033[1;1H";
      players = chose_players();
      loaded = 1;
    }
    if (playOptions == '2') {
      std::cout << "\033[2J\033[1;1H";
      if (loaded) {
        throw_dices(players, table, goldenScore);
        players[0].points = 0;
        players[1].points = 0;
        std::this_thread::sleep_for(std::chrono::seconds(5));
      }
    }
    if (playOptions == '3')
      return;
  }
}
