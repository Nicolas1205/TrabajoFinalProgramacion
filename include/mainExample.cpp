#include"registerPlayer.h"
#include<iostream>


int main(){

    std::vector<player> playersData = getPlayersData();

    std::string name , surname , username; std::cin>>name>>surname>>username;

    postPlayer(name , surname , username , playersData);

    showPlayers();

    return 0;
}
