#include <string>
#include <vector>

#ifndef GENTABLE
#define GENTABLE

typedef struct Cell {
  std::string playerCatcher;
  int cellValue;
  bool isCatched = false;
  bool isPrime = false;
  bool isPalindrome = false;
  bool inDiagonal = false;
  bool isFriend = false;
  bool isPerfect = false;
} Cell;

int calculate_perfect_number(int value);

int get_random();

int get_golden_score();

bool prime_number(int value);

bool friend_number(int value);

bool perfect_number(int value);

bool palindrome_number(int value);

std::vector<std::vector<Cell>> gen_table(int &goldenScore);

#endif
