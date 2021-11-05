#include"../include/showMenus.hpp"
#include"../include/play.h"
#include"../include/registerPlayer.h"
#include"../include/genTable.h"


int main(){

  bool  gameOver = false;
  char menuOp;
  int goldenScore; 
  std::vector<std::vector<cell>> table;
  std::vector<std::vector<player>> playersData = getPlayersData();
  while(gameOver){
    showMainMenu();
    scanf("%c" , &menuOp);
    if(menuOp == '1'){
      table = genTable(goldenScore);
    }
    if(menuOp == '2'){
      postPlayer(std::string &name, std::string &surname, std::string &username, std::vector<player> &playersData);
    }
    if(menuOp == '3'){
      showPlayers();
    }
    if(menuOp == '4'){
//      play(std::vector<std::vector<cell>> &table)
    }
    if(menuOp == '5') break;
  }

  return 0; 
}

