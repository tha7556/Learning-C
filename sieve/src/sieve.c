#include "sieve.h"
#include <stdio.h>
#include <string.h>

unsigned int sieve(const unsigned int limit, primes_array_t primes) {
	if(limit < 2)
		return 0;
	int numbers[limit+1];
	for(unsigned int i = 0; i <= limit; i++) {
		if(i < 2)
			numbers[i] = 1;
		else
			numbers[i] = 0;
	}
	for(unsigned int i = 2; i <= limit; i++) {
		for(unsigned int p = 2*i; p <= limit; p+=i) {
			numbers[p] = 1;
		}
	}
	int index = 0;
	for(unsigned int i = 0; i <= limit; i++) {
		if(numbers[i] == 0) {
			primes[index] = i;
			index++;
		}
	}
	return index;
}