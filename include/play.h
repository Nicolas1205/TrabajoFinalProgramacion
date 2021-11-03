#include "registerPlayer.h"
#include "chosePlayer.h"
#include "genTable.h"
#include "sieve.h"
#include "showMenus.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

bool gameOver = false;


void throwDices(std::vector<pInGame> &players , std::vector<std::vector<cell>> &table ){


}

void play(std::vector<std::vector<cell>> &table) {

  char playOptions;
  std::vector<pInGame> players;
  while (gameOver) {

    showPlayMenu();

    scanf("%c", &playOptions);

    if (playOptions == '1') {
      players = chosePlayers();
    }
    if (playOptions  == '2') {
      throwDices(players , table);
    }
    if (playOptions == '3')
      return;
  }

}
