#include "difference_of_squares.h"

long power(int base, int exponent) {
	if(base == 0 || base == 1)
		return base;
	if(base == 2) {
		return 1ul << base;
	}
	long result = 1;
	for(int i = 0; i < exponent; i++) 
		result *= base;
	return result;
}
long square_of_sum(int num) {
	long squaredSum = 0;
	for(int i = 1; i <= num; i++)
		squaredSum += i;
	return power(squaredSum, 2);
	
}
long sum_of_squares(int num) {
	long sumSquares = 0;
	for(int i = 1; i <= num; i++) 
		sumSquares += power(i,2);
	return sumSquares;
}
long difference_of_squares(int num) {
	return square_of_sum(num) - sum_of_squares(num);
}
