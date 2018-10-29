#include "hamming.h"
#include <string.h>

int compute(const char *first, const char *second) {
	if(first == NULL || second == NULL)
		return -1;
	int length = strlen(first);
	if((int)strlen(second) != length)
		return -1;
	int count = 0;
	for(int i = 0; i < length; i++) {
		if(first[i] != second[i])
			count++;
	}
	return count;
}