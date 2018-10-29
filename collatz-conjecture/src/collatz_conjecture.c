#include "collatz_conjecture.h"

int steps(int start) {
	if(start == 1)
		return 0;
	if(start <= 0)
		return ERROR_VALUE;
	int x = start;
	if(start % 2 == 0)
		x /= 2;
	else
		x = 3 * x + 1;
	return 1 + steps(x);
}