#include "../include/genTable.h"
#include"../include/sieve.h"
#include <string>
#include <vector>
#include<algorithm>
#include<random>


#define COLS 10
#define ROWS 10

std::vector<bool> exist(1000, 0);

int countPrimes = 0, countPalindromes = 0, countBoth = 0;

int nPerfect(int value){
  int sum =0 ; 
  for(int i = 1; i < value ; i++){
    if(!(value % i )) sum+=i;
  }
  return sum;

}

int getRandom() {
  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(1 , 1000);
  int random = uniform_dist(el);
  if (!exist[random]) {
    exist[random] = 1;
    return random;
  }
  return getRandom();
}

int getGoldenScore() {
  return countPrimes + countPalindromes + countBoth + 10000; 
}

bool primeNumber(int value) { 
  std::vector<bool> criba = getSieve();
  if(criba[value]) { 
    countPrimes++;
    return true;
  }
  return false;

}
bool palindromeNumber(int value) { 
  std::string   valueString = std::to_string(value) , s = valueString;

  std::reverse(s.begin() , s.end()); 

  if(s == valueString){
    countPalindromes++; 
    return true;
  }
  return false;
}

bool friendNumber(int value) {
  return value == nPerfect(nPerfect(value));
}

bool perfectNumber(int value) {

  return nPerfect(value) == value ? 1 : 0; 
}


std::vector<std::vector<cell>> genTable(int &goldenScore) {

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
