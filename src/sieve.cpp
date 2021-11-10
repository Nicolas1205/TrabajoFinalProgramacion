#include "../include/sieve.h"
#include <math.h>
#include <stdio.h>
#include <vector>

std::vector<bool> get_sieve() {

  std::vector<bool> sieve(10000, 1);

  sieve[0] = 0;
  sieve[1] = 0;

  for (int i = 2; i <= sqrt(sieve.size()); i++) {
    for (int j = i << 1; j < sieve.size(); j += i) {
      sieve[j] = 0;
    }
  }

  return sieve;
}
