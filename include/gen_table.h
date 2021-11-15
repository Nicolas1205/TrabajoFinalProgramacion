#include <string>
#include <vector>

#ifndef GENTABLE
#define GENTABLE

typedef struct Cell {
  std::string player_catcher;
  int cell_value;
  bool is_catched = false;
  //  bool *specials = malloc(sizeof(bool) * 5);
  bool specials[5];
  // order
  // bool is_prime = false;
  // bool is_palindrome = false;
  // bool is_friend = false;
  // bool is_perfect = false;
  // bool in_diagonal = false;
} Cell;

int get_random();

int calculate_div_sum(int number);

bool friend_number(int number);

bool prime_number(int number);

bool palindrome_number(int number);

bool perfect_number(int number);

std::vector<std::vector<Cell>> gen_table(int &golden_score);

#endif
