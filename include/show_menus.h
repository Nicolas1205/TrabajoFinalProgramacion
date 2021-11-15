#include "chose_player.h"
#include <string>
#include <vector>

#ifndef SHOWMENUS
#define SHOWMENUS

void show_player_winner(Player *winner);

void show_main_menu(bool table_created, size_t players_size, int *golden_score);

void show_play_menu(std::vector<Player> &players);

void show_player_results(Player *player, std::pair<int, int> dices,
                         bool *specials, int found_number, int score);

#endif // SHOWMENUS
