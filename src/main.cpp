#include"../include/showMenus.h"
#include"../include/play.h"
#include"../include/registerPlayer.h"
#include"../include/genTable.h"
#include<iostream> 


int main(){

  bool  gameOver = true;
  char menuOp;
  int goldenScore; 
  std::vector<std::vector<cell>> table;
  std::vector<player> playersData = getPlayersData();
	std::vector<bool> loaded(2);
  while(gameOver){
    showMainMenu();
		std::cin>>menuOp;
    if(menuOp == '1'){
      table = genTable(goldenScore);
			loaded[0] = 1; 
    }
    if(menuOp == '2'){
			std::string name , surname , username;
			puts("*************** Registrar Usario **************\n");
			puts("Nombre:");
			std::cin>>name;
			puts("Apellido:");
			std::cin>>surname;
			puts("Nombre de Usario:");
			std::cin>>username; 
      postPlayer(name, surname, username, playersData);
			loaded[1] =1;
    }
    if(menuOp == '3'){
      showPlayers();
    }
    if(menuOp == '4'){
			if(loaded[0] && loaded[1]) 
     		play(table, goldenScore );
    }
    if(menuOp == '5') break;
  }

  return 0; 
}

