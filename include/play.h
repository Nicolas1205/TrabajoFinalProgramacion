#include "chose_player.h"
#include "gen_table.h"

#ifndef PLAY
#define PLAY
std::pair<int, int> get_dices();

int get_score(std::vector<std::vector<Cell>> &table, int d1, int d2);

std::vector<bool> specials(std::vector<std::vector<Cell>> &table, int d1,
                           int d2);

void throw_dices(std::vector<Player> &players,
                 std::vector<std::vector<Cell>> &table, int *golden_score);

void play(std::vector<std::vector<Cell>> &table, int *golden_score);

#endif
