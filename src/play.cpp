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

std::pair<int, int> dices;

void get_dices() {
  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(0, 9);
  dices.first = uniform_dist(el);
  dices.second = uniform_dist(el);
}

int get_score(std::vector<std::vector<Cell>> &table) {
  int i = dices.first, j = dices.second, value = table[i][j].cellValue;

  int score = 0;

  if (table[i][j].isPrime && table[i][j].isPalindrome &&
      table[i][j].inDiagonal) {
    score = value * 4;
  } else if (table[i][j].isPrime && table[i][j].isPalindrome) {
    score = value * 3;
  } else if (table[i][j].isPrime ||
             table[i][j].isPalindrome && table[i][j].inDiagonal) {
    score = value * 2;
  } else if (table[i][j].isPrime || table[i][j].isPalindrome) {
    score = value;
  }
  return score;
}

std::vector<bool> specials(std::vector<std::vector<Cell>> &table) {
  std::vector<bool> isSpecial(5, 0);
  if (table[dices.first][dices.second].isPrime)
    isSpecial[0] = 1;
  if (table[dices.first][dices.second].isPalindrome)
    isSpecial[1] = 1;
  if (table[dices.first][dices.second].inDiagonal)
    isSpecial[2] = 1;
  if (table[dices.first][dices.second].isFriend)
    isSpecial[3] = 1;
  if (table[dices.first][dices.second].isPerfect)
    isSpecial[4] = 1;
  return isSpecial;
}

void throw_dices(std::vector<Player> &players,
                 std::vector<std::vector<Cell>> &table, int &goldenScore) {
  int playerTurn = 0;
  while (1) {
    while (players[playerTurn].turns--) {

      get_dices();

      if (!table[dices.first][dices.second].isCatched) {
        table[dices.first][dices.second].playerCatcher =
            players[playerTurn].username;
        table[dices.first][dices.second].isCatched = true;
      } else if (table[dices.first][dices.second].playerCatcher !=
                 players[playerTurn].username) {
        players[playerTurn].turns++;
        int propertyOf = playerTurn == 1 ? 1 : 0;
        std::cout << "\n Esta casillla no puede ser tomada!! , es propiedad de "
                  << players[propertyOf].username;
        continue;
      }

      if (table[dices.first][dices.second].isFriend)
        players[playerTurn].turns++;
      if (table[dices.first][dices.second].isPerfect)
        players[playerTurn].turns += 2;

      int score = get_score(table);

      players[playerTurn].points += score;

      show_player_results(players[playerTurn], dices, specials(table),
                          table[dices.first][dices.second].cellValue, score);

      std::this_thread::sleep_for(std::chrono::seconds(1));

      if (players[playerTurn].points >= goldenScore) {
        show_player_winner(players[playerTurn]);
        return;
      }
    }
    players[playerTurn].turns = 1;
    playerTurn = playerTurn == 0 ? 1 : 0;
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
        std::this_thread::sleep_for(std::chrono::seconds(10));
      } else
        printf("\n\n NO HA SELECCIONADO JUGADORES \n\n");
    }
    if (playOptions == '3')
      return;
  }
}
