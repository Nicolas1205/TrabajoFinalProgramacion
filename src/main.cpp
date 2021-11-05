#include"../include/showMenus.h"
#include"../include/play.h"
#include"../include/registerPlayer.h"
#include"../include/genTable.h"
#include<iostream> 
#include<chrono>
#include<thread>

int main(){

  char menuOp;
  int goldenScore; 
  std::vector<std::vector<cell>> table;
  std::vector<player> playersData = getPlayersData();
  std::vector<bool> loaded(2);

  while(1){
    std::cout << "\033[2J\033[1;1H";
    showMainMenu(loaded[0] , playersData.size() , playersData.size() , goldenScore);
    std::cin>>menuOp;
    if(menuOp == '1'){
      table = genTable(goldenScore);
      loaded[0] = 1; 
    }
    if(menuOp == '2'){
			
			std::string name , surname , username;
			puts( "*************** Registrar Usario **************\n");
			printf("\nNombre: ");
			std::cin>>name;
			printf("\nApellido: ");
			std::cin>>surname;
			printf("\nNombre de Usario: ");
			std::cin>>username; 
      postPlayer(name, surname, username, playersData);
			loaded[1] =1;
    }
    if(menuOp == '3'){
      std::cout << "\033[2J\033[1;1H";
      showPlayers();
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    if(menuOp == '4'){
      if(loaded[0] && playersData.size() >= 2) {
	play(table, goldenScore);
      }	
    }
    if(menuOp == '5') break;
  }

  return 0; 
}

