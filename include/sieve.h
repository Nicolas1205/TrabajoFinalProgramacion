#include<vector>
#include<stdio.h>
#include<math.h>



std::vector<bool> getSieve() {

    std::vector<bool> sieve(1000, 1);
    for(int i = 2 ; i < sieve.size() ; i++ ){
        for(int j = i ; j < sqrt(sieve.size()); j+=j){
            sieve[j] = 0;
        }
    }

    return sieve;

}
