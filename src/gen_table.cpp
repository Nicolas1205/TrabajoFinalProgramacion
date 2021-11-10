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

std::vector<std::vector<Cell>> gen_table(int *goldenScore) {

  std::vector<std::vector<Cell>> table(COLS, std::vector<Cell>(ROWS));

  auto calculate_perfect_number = [](int value) {
    int sum = 0;
    for (int i = 1; i < value; i++) {
      if (!(value % i))
        sum += i;
    }
    return sum;
  };

  auto prime_number = [](int value) {
    if (sieve[value]) {
      count_primes++;
      return true;
    }
    return false;
  };

  auto palindrome_number = [](int value) {
    std::string palindrome = std::to_string(value), s = palindrome;

    std::reverse(s.begin(), s.end());

    if (s == palindrome) {
      count_palindromes++;
      return true;
    }
    return false;
  };

  auto perfect_number = [](int value,
                           std::function<int(int)> calculate_perfect_number) {
    return calculate_perfect_number(value) == value ? 1 : 0;
  };

  auto friend_number = [](int value,
                          std::function<int(int)> calculate_perfect_number) {
    return value == calculate_perfect_number(calculate_perfect_number(value));
  };

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {

      table[i][j].cell_value = get_random();
      table[i][j].is_prime = prime_number(table[i][j].cell_value) ? 1 : 0;
      table[i][j].is_palindrome =
          palindrome_number(table[i][j].cell_value) ? 1 : 0;
      table[i][j].in_diagonal = i == j ? 1 : 0;
      table[i][j].is_friend =
          friend_number(table[i][j].cell_value, calculate_perfect_number) ? 1
                                                                          : 0;
      table[i][j].is_perfect =
          perfect_number(table[i][j].cell_value, calculate_perfect_number) ? 1
                                                                           : 0;

      if (table[i][j].is_prime && table[i][j].is_palindrome)
        count_both++;
    }
  }

  *goldenScore = count_primes + count_palindromes + count_both + 10000;

  return table;
}
