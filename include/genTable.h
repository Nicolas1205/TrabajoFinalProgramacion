#ifndef GENTABLE
#define GENTABLE
#include <string>
#include <vector>

typedef struct Cell {
  std::string playerCatcher = "";
  int cellValue;
  bool isPrime = false;
  bool isPalindrome = false;
  bool inDiagonal = false;
  bool isFriend = false;
  bool isPerfect = false;
} cell;

int nPerfect(int value);

int getRandom();

int getGoldenScore();

bool primeNumber(int value);

bool friendNumber(int value);

bool perfectNumber(int value);

bool palindromeNumber(int value);

std::vector<std::vector<cell>> genTable(int &golderScore);

#endif
