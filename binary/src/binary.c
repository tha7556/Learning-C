#include "binary.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int convert(const char *input) {
	int length = strlen(input);
	int result = 0;
	for(int i = length-1; i >= 0; i--) {
		if(!isdigit(input[i]))
			return INVALID;
		int digit = (int)input[i]-48;
		if(digit > 1 || digit < 0)
			return INVALID;
		if(length-i-1 > 0)
			result += digit * (2 << (length-i-2));
		else
			result += digit;
	}
	return result;
}