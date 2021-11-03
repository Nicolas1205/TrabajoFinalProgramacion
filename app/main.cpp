#include<stdio.h>
#include<assert.h>
#include<iostream>
#include"../include/showMenus.hpp"
#include"../include/play.h"
#include"../include/registerPlayer.h"
#include"../include/genTable.h"


int main(){

  bool  gameOver = false;
  char menuOption;
  while(gameOver){
    showMainMenu();
    scanf("%c" , &menuOption);
    if(menuOption == '1'){
//      genTable();
    }
    if(menuOption == '2'){
//      postPlayer(std::string &name, std::string &surname, std::string &username, std::vector<player> &playersData);
    }
    if(menuOption == '3'){
//      showPlayers();
    }
    if(menuOption == '4'){
//      play(std::vector<std::vector<cell>> &table)
    }
    if(menuOption == '5') break;
  }

  return 0; 
}

