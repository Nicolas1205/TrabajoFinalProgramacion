#include <string>
#include <vector>
#include"chosePlayer.h"

#ifndef SHOWMENUS
#define SHOWMENUS

void showPlayerWinner(pInGame player);

void showMainMenu();

void showPlayMenu();

void showPlayerResults(std::string username, std::pair<int, int> dices,
                       std::vector<bool> isSpecial, int foundNumber, int score);

#endif // SHOWMENUS
