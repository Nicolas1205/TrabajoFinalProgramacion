#include <string>
#include <vector>
#include"chosePlayer.h"

#ifndef SHOWMENUS
#define SHOWMENUS

void showPlayerWinner(pInGame winner);

void showMainMenu(bool tCreated , bool pExist , int size , int &goldenScore);

void showPlayMenu(std::vector<pInGame> &players);

void showPlayerResults(pInGame player, std::pair<int, int> dices,
                       std::vector<bool> isSpecial, int foundNumber, int score);

#endif // SHOWMENUS
