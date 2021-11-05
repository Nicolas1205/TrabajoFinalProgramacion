#ifndef PLAY
#define PLAY
#include"genTable.h"
#include"chosePlayer.h"

void getDices();

int getScore(std::vector<std::vector<cell>> &table);

std::vector<bool> specials(std::vector<std::vector<cell>> &table);

void throwDices(std::vector<pInGame> &players, std::vector<std::vector<cell>> &table , int &goldenScore);

void play(std::vector<std::vector<cell>> &table , int &goldenScore);

#endif
