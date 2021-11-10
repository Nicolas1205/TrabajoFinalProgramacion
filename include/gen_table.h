#include <string>
#include <vector>

#ifndef GENTABLE
#define GENTABLE

typedef struct Cell {
  std::string player_catcher;
  int cell_value;
  bool is_catched = false;
  bool is_prime = false;
  bool is_palindrome = false;
  bool in_diagonal = false;
  bool is_friend = false;
  bool is_perfect = false;
} Cell;

int get_random();

std::vector<std::vector<Cell>> gen_table(int *golden_score);

#endif
