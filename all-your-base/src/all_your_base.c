#include "all_your_base.h"
#include <stdio.h>

long power(int base, int exponent) {
	if(base == 0 || base == 1)
		return base;
	if(base == 2)
		return 1ul << exponent;
	long result = 1;
	for(int i = 0; i < exponent; i++) 
		result *= base;
	return result;
}
void flip(int8_t digits[], int length) {
	int temp;
	int start = 0; 
	int end = length-1;
	while(start < end) {
		temp = digits[start];
		digits[start] = digits[end];
		digits[end] = temp;
		start++;
		end--;
	}
}
int rebase(int8_t digits[], int input_base, int output_base, int input_length) {
	if(input_base < 2 || output_base < 2 || digits[0] == 0) {
		digits[0] = 0;
		return 0;
	}
	int num = 0;
	for(int i = input_length-1; i >= 0; i--) {
		long pow = power(input_base,input_length-1-i);
		num += digits[i] * pow;
		if(digits[i] < 0 || digits[i] >= input_base) {
			digits[0] = 0;
			return 0;
		}
	}
	int i = 0;
	while(num != 0) {
		digits[i] = num % output_base;
		num /= output_base;
		i++;
	}
	flip(digits,i);
	return i;
}
