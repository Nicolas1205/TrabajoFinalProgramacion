#ifndef PLAY
#define PLAY
#include "chosePlayer.h"
#include "genTable.h"
#include <functional>

void get_dices();

int get_score(std::vector<std::vector<Cell>> &table);

std::vector<bool> specials(std::vector<std::vector<Cell>> &table);

void throw_dices(std::vector<Player> &players,
                 std::vector<std::vector<Cell>> &table, int &goldenScore);

void play(std::vector<std::vector<Cell>> &table, int &goldenScore);

#endif
