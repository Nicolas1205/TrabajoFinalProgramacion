#include "register_player.h"
#include <string>

#ifndef CHOSEPLAYER

#define CHOSEPLAYER

bool search_player(std::string username, std::vector<Player> &players_data,
                   std::vector<Player> &players, int p);

std::vector<Player> chose_players();

#endif
