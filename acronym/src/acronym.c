#include "acronym.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {
	if(phrase == NULL || strlen(phrase) == 0)
		return NULL;
	const int length = strlen(phrase);
	char *result = (char*)malloc(length*sizeof(char));
	int index = 0;
	for(int i = 0; i < length; i++) {
		if(i == 0 || phrase[i-1] == ' ' || phrase[i-1] == '-' || phrase[i-1] == '_') {
			result[index] = toupper(phrase[i]);
			index++;
		}
	}
	result[index] = '\0';
	return result;
}