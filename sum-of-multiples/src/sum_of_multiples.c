#include "sum_of_multiples.h"
#include <stdio.h>

unsigned int sum_of_multiples(const unsigned int multiples[], int length, const unsigned int num) {
	if(multiples == NULL) 
		return 0;
	for(int i = 0; i < length; i++) {
		if(multiples[i] == 0)
			return 0;
	}
	unsigned int result = 0;
	for(unsigned int i = 1; i < num; i++) {
		for(int j = 0; j < length; j++) {
			if(i % multiples[j] == 0) {
				result += i;
				break;
			}
		}
	}
	return result;
}