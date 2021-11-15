#include "../include/gen_table.h"
#include "../include/sieve.h"
#include <algorithm>
#include <random>
#include <string>
#include <vector>

#define COLS 10
#define ROWS 10

std::vector<bool> exist(1001, 0);

std::vector<bool> sieve = get_sieve();

int count_primes = 0, count_palindromes = 0, count_both = 0;

int get_random() {

  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(1, 1000);

  int random = uniform_dist(el);
  if (!exist[random]) {
    exist[random] = 1;
    return random;
  }
  return get_random();
}

int calculate_sum_div(int number) {
  int sum = 0;
  for (int i = 1; i < number; i++) {
    if (!(number % i))
      sum += i;
  }
  return sum;
}

bool palindrome_number(int number) {

  std::string palindrome = std::to_string(number), s = palindrome;

  std::reverse(s.begin(), s.end());

  if (s == palindrome) {
    count_palindromes++;
    return true;
  }
  return false;
}

bool prime_number(int number) { return sieve[number]; }

bool perfect_number(int number) { return calculate_sum_div(number) == number; }

bool friend_number(int number) {
  return number == calculate_sum_div(calculate_sum_div(number));
}

std::vector<std::vector<Cell>> gen_table(int &golden_score) {

  std::vector<std::vector<Cell>> table(COLS, std::vector<Cell>(ROWS));

  bool (*ptr_functions[])(int) = {prime_number, palindrome_number,
                                  friend_number, perfect_number};

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      int random = get_random();
      table[i][j].cell_value = random;
      for (int k = 0; k < 4; k++) {
        table[i][j].specials[k] = (*ptr_functions[k])(random);
      }
      table[i][j].specials[0] && table[i][j].specials[1] ? count_both++ : 0;
      table[i][j].specials[4] = i == j ? 1 : 0;
    }
  }

  golden_score = count_primes + count_palindromes + count_both + 10000;

  return table;
}
