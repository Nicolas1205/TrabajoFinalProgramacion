#include "registerPlayer.h"
#include <string>

#ifndef CHOSEPLAYER
#define CHOSEPLAYER

typedef struct PInGame {

  std::string name;
  std::string surname;
  std::string username;
  int turns = 1;
  int points = 0;

} pInGame;


bool searchPlayer(std::string username, std::vector<player> &playersData,
                  std::vector<pInGame> &players, int p);

std::vector<pInGame> chosePlayers();

#endif
