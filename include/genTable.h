#include <string>
#include <vector>

#define COLS 10
#define ROWS 10

typedef struct Cell {
  std::string playerCatcher;
  int cellValue;
  bool isPrime = false;
  bool isPalindrome = false;
  bool inDiagonal = false;
  bool isFriend = false;
  bool isPerfect = false;
} cell;

std::vector<bool> exist(201, 0);

int goldenScore , countPrimes = 0, countPalindrome = 0, countBoth = 0;

int getRandom() {
  int random = rand() % 200 + 1;
  if (!exist[random]) {
    exist[random] = 1;
    return random;
  }
  return getRandom();
}

int getGoldenScore() {
  return countPrimes * 0.2 + countPalindrome * 0.3 + countBoth * 0.5;
}

bool primeNumber(int value) { return true; }

bool friendNumber(int value) { return true; }

bool perfectNumber(int value) { return true; }

bool palindromeNumber(int value) { return true; }

std::vector<std::vector<cell>> genTable() {

  std::vector<std::vector<cell>> table(COLS, std::vector<cell>(ROWS));

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {

      table[i][j].cellValue = getRandom();
      table[i][j].isPrime = primeNumber(table[i][j].cellValue) ? 1 : 0;
      table[i][j].isPalindrome = palindromeNumber(table[i][j].cellValue) ? 1 : 0;
      table[i][j].inDiagonal = i == j ? 1 : 0;
      table[i][j].isFriend = friendNumber(table[i][j].cellValue) ? 1 : 0;
      table[i][j].isPerfect = perfectNumber(table[i][j].cellValue) ? 1 : 0;

      if (table[i][j].isPrime && table[i][j].isPalindrome)
        countBoth++;
    }
  }

  goldenScore = getGoldenScore();

  return table;
}
