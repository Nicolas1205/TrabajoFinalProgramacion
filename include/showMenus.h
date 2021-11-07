#include "chosePlayer.h"
#include <string>
#include <vector>

#ifndef SHOWMENUS
#define SHOWMENUS

void show_player_winner(Player winner);

void show_main_menu(bool tCreated, bool pExist, int size, int &goldenScore);

void show_play_menu(std::vector<Player> &players);

void show_player_results(Player player, std::pair<int, int> dices,
                         std::vector<bool> isSpecial, int foundNumber,
                         int score);

#endif // SHOWMENUS
