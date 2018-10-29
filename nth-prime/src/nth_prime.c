#include "nth_prime.h"

unsigned int isPrime(unsigned int n) {
	if(n % 2 == 0) 
		return n == 2;
	if(n % 3 == 0)
		return n == 3;
	for(unsigned int i = 2; i < n; i++) {
		if(n % i == 0)
			return 0;
	}
	return 1;
}
unsigned int nth(unsigned int n) {
	unsigned int count = 0;
	for(unsigned int i = 2; count < n; i++) {
		if(isPrime(i)) {
			count++;
			if(count == n)
				return i;
			
		}
	}
	return 0;
}
