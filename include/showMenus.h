#include <string>
#include <vector>

#ifndef SHOWMENUS
#define SHOWMENUS

void showMainMenu();

void showPlayMenu();

void showPlayerResults(std::string username, std::pair<int, int> dices,
                       std::vector<bool> isSpecial, int foundNumber, int score);

#endif // SHOWMENUS_H_
