#include "chosePlayer.h"
#include "genTable.h"
#include "registerPlayer.h"
#include "showMenus.hpp"
#include "sieve.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

bool gameOver = false;

std::pair<int , int> dices;

void getDices() {
  dices.first = rand() % 9;
  dices.second  = rand() % 9;
}

int getScore(std::vector<std::vector<cell>> &table){
  int i = dices.first , j = dices.second , cValue = table[i][j].cellValue;
  std::string catcher = table[i][j].playerCatcher;
  bool isPrime = table[i][j].isPrime , isPalindrome = table[i][j].isPalindrome,
       inDiagonal = table[i][j].inDiagonal , isFriend = table[i][j].isFriend ,
       isPerfect = table[i][j].isPerfect;

  if(catcher.size() != 0){
    return 0;
  }

  int score = 0;

  if(isPrime && isPalindrome && inDiagonal ){
    score = cValue * 4;
    return 4;
  }

  return 1;
}

std::vector<bool> specials(std::vector<std::vector<cell>> &table){
  std::vector<bool> isSpecial(5 , 0) ;
  if(table[dices.first][dices.second].isPrime) isSpecial[0] = 1;
  if(table[dices.first][dices.second].isPalindrome) isSpecial[1] = 1;
  if(table[dices.first][dices.second].inDiagonal) isSpecial[2] = 1;
  if(table[dices.first][dices.second].isFriend) isSpecial[3] = 1;
  if(table[dices.first][dices.second].isPerfect) isSpecial[4] = 1;
  return isSpecial;
}


void throwDices(std::vector<pInGame> &players,
                std::vector<std::vector<cell>> &table) {
  int playerTurn = 0;
  while (gameOver) {
    while (players[playerTurn].turns--) {
      getDices();
      if(table[dices.first][dices.second].playerCatcher.size() != 0){
        players[playerTurn].turns++;
      }
      int score = getScore(table);
      players[playerTurn].points+=score;
      showPlayerResults(players[playerTurn].username , dices ,
                        specials(table),
                        table[dices.first][dices.second].cellValue , score);
    }
    playerTurn = playerTurn == 0 ? 1 : 0;
  }
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
    if (playOptions == '2') {
      throwDices(players, table);
    }
    if (playOptions == '3')
      return;
  }
}
