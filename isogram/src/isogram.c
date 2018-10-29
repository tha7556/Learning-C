#include "isogram.h"
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
	int length = strlen(phrase);
	for(int i = 0; i < length; i++) {
		for(int j = i+1; j < length; j++) {
			if(isalpha(phrase[i]) && toupper(phrase[i]) == toupper(phrase[j]))
				return false;
		}
	}
	return true;
}
