#include "grains.h"

long square(int x) {
	if(x == 1 || x == 0)
		return x;
	if(x > 64)
		return 0;
	return 1l << (x - 1);
}
long total() {
	long result = 0;
	for(int i = 1; i <= 64; i++)
		result += square(i);
	return result;
}