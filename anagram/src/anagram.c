#include "anagram.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int stringComp(const char *a, const char *b) {
	while(*a != '\0') {
		if(tolower(*a++) != tolower(*b++))
			return 1;
	}
	return 0;
}
int compare(const char *word, const char *candidate) {
	if(stringComp(word, candidate) == 0 || strlen(word) != strlen(candidate))
		return 0;
	int length = strlen(candidate);
	char *copy = malloc(length* sizeof(char));
	strcpy(copy, candidate);
	while(*word != '\0') {
		char c = *word++;
		int found = 0;
		for(int i = 0; i < length; i++) {
			if(tolower(c) == tolower(copy[i])) {
				copy[i] = '_';
				found = 1;
				break;
			}
		}
		if(found != 1)
			return 0;
	}
	free(copy);
	return 1;

}
void anagrams_for(const char *word, struct candidates *candidates) { //pointer to canidates object, not array
	for(unsigned int i = 0; i < candidates->count; i++) {
		int result = compare(word, candidates->candidate[i].candidate);
		if(result == 1) {
			candidates->candidate[i].is_anagram = IS_ANAGRAM;
		}
		else {
			candidates->candidate[i].is_anagram = NOT_ANAGRAM;
		}
	}
}
