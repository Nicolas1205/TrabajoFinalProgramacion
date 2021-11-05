//#include"../include/registerPlayer.h"
//#include"../include/chosePlayer.h"
#include"../include/genTable.h"
#include<iostream>


int main(){

    //std::vector<player> playersData = getPlayersData();

    //std::string name , surname , username; std::cin>>name>>surname>>username;

    //postPlayer(name , surname , username , playersData);

    //showPlayers();

    //std::vector<pInGame> players;

    //players = chosePlayers();
    
    int goldenScore; 
    std::vector<std::vector<cell>> table = genTable(goldenScore); 

    printf(" %d\n", goldenScore);
    printf("FRIENDS\n"); 

    for(int i =0 ;  i < 10 ; i++){
      for(int j =0 ;  j < 10 ; j++){
	std::cout<<table[i][j].isFriend<<' ';
      }
      std::cout<<'\n';
    }
    
    printf("%d", friendNumber(220));

    return 0;
}
