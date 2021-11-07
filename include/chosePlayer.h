#include "registerPlayer.h"
#include <string>

#ifndef CHOSEPLAYER
#define CHOSEPLAYER

bool search_player(std::string username, std::vector<Player> &playersData,
                   std::vector<Player> &players, int p);

std::vector<Player> chose_players();

#endif
