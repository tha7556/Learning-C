#include "perfect_numbers.h"

int classify_number(long number) {
	if(number < 1)
		return ERROR;
	long sum = 0;
	for(int i = 1; i <= number/2; i++) {
		if(number % i == 0) {
			sum += i;
		}
		if(sum > number)
			return ABUNDANT_NUMBER;
	}	
	if(sum != number)
		return DEFICIENT_NUMBER;
	return PERFECT_NUMBER;
}