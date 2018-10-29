#include "pangram.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool is_pangram(const char *sentence) {
	if(sentence == NULL)
		return false;
	for(int i = 97; i < 122; i++) {
		int j = 0;
		bool found = false;
		while(sentence[j] != '\0') {
			if(tolower(sentence[j]) == i) {
				found = true;
				break;
			}
			j++;
		}
		if(!found)
			return false;
	}
	return true;
}