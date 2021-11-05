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

std::pair<int, int> dices;

bool gameOver = true;

void getDices() {
  dices.first = rand() % 9;
  dices.second = rand() % 9;
}

int getScore(std::vector<std::vector<cell>> &table) {
  int i = dices.first, j = dices.second, cValue = table[i][j].cellValue;
  std::string playerCatcher = table[i][j].playerCatcher;
  bool isPrime = table[i][j].isPrime, isPalindrome = table[i][j].isPalindrome,
       inDiagonal = table[i][j].inDiagonal, isFriend = table[i][j].isFriend,
       isPerfect = table[i][j].isPerfect;

  if (playerCatcher.size() != 0) {
    return 30;
  }

  int score = 30;

	// FIXME: Not Working?
  if (isPrime && isPalindrome && inDiagonal) {
    score = cValue * 4;
	}
	else if(isPrime && isPalindrome){
		score = cValue * 2;
	}
	else if(isPrime || isPalindrome && inDiagonal){
		score = cValue * 2; 
	}
	else if(isPrime || isPalindrome){
		score = cValue;
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
  while (gameOver) {
    while (players[playerTurn].turns--) {
      getDices();

			// FIXME: TRULY bugs 
      //if (table[dices.first][dices.second].playerCatcher.size() != 0) {
       // players[playerTurn].turns++;
			//	continue;
      //}

			if(table[dices.first][dices.second].isFriend) players[playerTurn].turns++;
			//if(table[dices.first][dices.second].isPerfect) players[playerTurn].turns+=2;

			table[dices.first][dices.second].playerCatcher = players[playerTurn].username; 

      int score = getScore(table);

      players[playerTurn].points += score;

      showPlayerResults(players[playerTurn].username, dices, specials(table),
                        table[dices.first][dices.second].cellValue, score);

			if(players[playerTurn].points >= goldenScore){
				showPlayerWinner(players[playerTurn]); 
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

  while (gameOver) {

    showPlayMenu();

    scanf("%c", &playOptions);

    if (playOptions == '1') {
      players = chosePlayers();
    }
    if (playOptions == '2') {
      throwDices(players, table , goldenScore);
			return; 
    }
    if (playOptions == '3')
      return;
  }
}
