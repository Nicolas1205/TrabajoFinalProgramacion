#include "../include/genTable.h"
#include "../include/sieve.h"
#include <algorithm>
#include <random>
#include <string>
#include <vector>

#define COLS 10
#define ROWS 10

std::vector<bool> exist(1000, 0);

std::vector<bool> sieve = get_sieve();

int countPrimes = 0, countPalindromes = 0, countBoth = 0;

int calculate_perfect_number(int value) {
  int sum = 0;
  for (int i = 1; i < value; i++) {
    if (!(value % i))
      sum += i;
  }
  return sum;
}

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

int get_golden_score() {
  return countPrimes + countPalindromes + countBoth + 2000;
}

bool prime_number(int value) {
  if (sieve[value]) {
    countPrimes++;
    return true;
  }
  return false;
}
bool palindrome_number(int value) {
  std::string valueString = std::to_string(value), s = valueString;

  std::reverse(s.begin(), s.end());

  if (s == valueString) {
    countPalindromes++;
    return true;
  }
  return false;
}

bool friend_number(int value) {
  return value == calculate_perfect_number(calculate_perfect_number(value));
}

bool perfect_number(int value) {

  return calculate_perfect_number(value) == value ? 1 : 0;
}

std::vector<std::vector<Cell>> gen_table(int &goldenScore) {

  std::vector<std::vector<Cell>> table(COLS, std::vector<Cell>(ROWS));

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {

      table[i][j].cellValue = get_random();
      table[i][j].isPrime = prime_number(table[i][j].cellValue) ? 1 : 0;
      table[i][j].isPalindrome =
          palindrome_number(table[i][j].cellValue) ? 1 : 0;
      table[i][j].inDiagonal = i == j ? 1 : 0;
      table[i][j].isFriend = friend_number(table[i][j].cellValue) ? 1 : 0;
      table[i][j].isPerfect = perfect_number(table[i][j].cellValue) ? 1 : 0;

      if (table[i][j].isPrime && table[i][j].isPalindrome)
        countBoth++;
    }
  }

  goldenScore = get_golden_score();

  return table;
}
