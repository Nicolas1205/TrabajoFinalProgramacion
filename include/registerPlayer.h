#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>

typedef struct Player {
    std::string  name ;
    std::string  surname ;
    std::string  username;
    bool playing = false;
    //  int32_t currentPoints = 0;
   // uint32_t looses = 0;
    //uint32_t wins = 0;

} player ;


std::vector<player> getPlayersData(){

  std::ifstream i("../data/players.txt");

  int players_sz;

  i>>players_sz;

  if(!players_sz){
      std::vector<player> playersData;
      return playersData;
  }

  std::vector<player> playersData(players_sz);

  for(int iter = 0 ; iter <  players_sz ; iter++){
      i>>playersData[iter].username>>playersData[iter].name>>playersData[iter].surname; //>>playersData[i].looses>>playersData[i].wins;
  }

  return playersData;

}

bool compare(player a , player b){
    if(a.surname < b.surname){
        return 1 ;
    }
    else return 0;

}

void postPlayer(std::string &name , std::string &surname ,
                std::string &username , std::vector<player> &playersData){



  std::ofstream o("../data/players.txt");

  for(int i=0  ; i < playersData.size() ; i++){
      if(playersData[i].username == username) {
          std::cout<<"USUARIO YA EXISTENTE\n";
          o << playersData.size() << "\n";
          for(int i = 0 ;  i < playersData.size() ; i++){
            o << playersData[i].username << "\n\t";
            o << playersData[i].name << "\n\t";
            o << playersData[i].surname << "\n";
          }
          return;
      }
  }

  playersData.push_back({name , surname , username});

  sort(playersData.begin() , playersData.end() , compare);

  o << playersData.size() << "\n" ;

  for(int i = 0 ;  i < playersData.size() ; i++){

      o << playersData[i].username << "\n\t";
      o << playersData[i].name << "\n\t";
      o << playersData[i].surname << "\n";
  }

}


void showPlayers(){

  std::vector<player> playersData = getPlayersData();

  for(int i = 0 ;  i < playersData.size() ; i++){
      std::cout <<"Usuario: "<< playersData[i].username << "\n\t";
      std::cout <<"Nombre: "<< playersData[i].name << "\n\t";
      std::cout <<"Apellido: "<< playersData[i].surname << "\n";
  }

}


