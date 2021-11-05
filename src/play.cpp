#include "../include/play.h"
#include "../include/chosePlayer.h"
#include "../include/genTable.h"
#include "../include/registerPlayer.h"
#include "../include/showMenus.h"
#include "../include/sieve.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
#include <random>
#include<chrono>
#include<thread> 

std::pair<int, int> dices;


void getDices() {
  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(0 , 9);
  dices.first = uniform_dist(el);
  dices.second = uniform_dist(el);
}

int getScore(std::vector<std::vector<cell>> &table) {
  int i = dices.first, j = dices.second, value = table[i][j].cellValue;

  int score = 0;

  if (table[i][j].isPrime && table[i][j].isPalindrome && table[i][j].inDiagonal) {
    score = value * 4;
  }else if(table[i][j].isPrime && table[i][j].isPalindrome){
		score = value * 2;
  }else if(table[i][j].isPrime || table[i][j].isPalindrome && table[i][j].inDiagonal){
		score = value * 2; 
  }else if(table[i][j].isPrime || table[i][j].isPalindrome){
		score = value;
  }
  return score;
}

std::vector<bool> specials(std::vector<std::vector<cell>> &table ) {
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

void throwDices(std::vector<pInGame> &players,
                std::vector<std::vector<cell>> &table , int &goldenScore) {
  int playerTurn = 0;
  while (1) {
    while (players[playerTurn].turns--) {
      getDices();

      if (!table[dices.first][dices.second].isCatched){
	  table[dices.first][dices.second].playerCatcher = players[playerTurn].username;
	  table[dices.first][dices.second].isCatched = true; 
      }else if(table[dices.first][dices.second].playerCatcher != players[playerTurn].username){
	players[playerTurn].turns++;
	int propertyOf = playerTurn == 0 ? 1 : 0;
	std::cout<<"\n Esta casillla no puede ser tomada!! , es propiedad de: "<<players[propertyOf].username;
	continue;
      }

      if(table[dices.first][dices.second].isFriend) players[playerTurn].turns++;
      if(table[dices.first][dices.second].isPerfect) players[playerTurn].turns+=2;

      int score = getScore(table);

      players[playerTurn].points += score;

      showPlayerResults(players[playerTurn], dices, specials(table),
                        table[dices.first][dices.second].cellValue, score );

      std::this_thread::sleep_for(std::chrono::seconds(1));

      if(players[playerTurn].points >= goldenScore){
	  showPlayerWinner(players[playerTurn] ); 
	  return; 	
      }
    }
    players[playerTurn].turns = 1; 
    playerTurn = playerTurn == 0 ? 1 : 0;
  }
}

void play(std::vector<std::vector<cell>> &table , int &goldenScore) {

  char playOptions;
  std::vector<pInGame> players;
  bool loaded = 0;

  while (1) {
    std::cout << "\033[2J\033[1;1H";
    showPlayMenu(players);

    scanf("%c", &playOptions);

    if (playOptions == '1') {
      std::cout << "\033[2J\033[1;1H";
      players = chosePlayers();
      loaded = 1;
    }
    if (playOptions == '2'  ) {
      std::cout << "\033[2J\033[1;1H";
      if(loaded)
      throwDices(players, table , goldenScore);
      else printf("\n\n NO HA SELECCIONADO JUGADORES \n\n");
      players[0].points = 0;
      players[1].points = 0;
      std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    if (playOptions == '3')
      return;
  }
}
