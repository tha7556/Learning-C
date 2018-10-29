#include "word_count.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int word_count(const char *input_text, word_count_word_t *words) {
	memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);
	const int length = strlen(input_text);
	char currentWord[MAX_WORD_LENGTH+1];
	int letterIndex = 0;
	int wordIndex = 0;
	for(int i = 0; i < length+1; i++) {
		if(input_text[i] != ' ' && i != length && input_text[i] != '\n' && input_text[i] != '.' && input_text[i] != ',' && letterIndex <= MAX_WORD_LENGTH) {
			if(input_text[i] == '\'') {
				if(!((i < length && input_text[i+1] == ' ') || (letterIndex == 0))) {
					currentWord[letterIndex] = tolower(input_text[i]);
					letterIndex++;
				}	
			}
			else {
				currentWord[letterIndex] = tolower(input_text[i]);
				letterIndex++;
			}
		}
		else if(letterIndex > 0) { //Current word is a full word
			if(letterIndex > MAX_WORD_LENGTH) {
				return EXCESSIVE_LENGTH_WORD;
			}
			currentWord[letterIndex] = '\0';
			letterIndex = 0;
			int loc = indexOf(currentWord, words);
			if(loc == -1) { //Word is not in words
				if(wordIndex == MAX_WORDS)
					return EXCESSIVE_NUMBER_OF_WORDS;
				strcpy(words[wordIndex].text, currentWord);
				words[wordIndex].count = 1;
				wordIndex++;
			}
			else { //Word already in words
				words[loc].count++;
			}
		}
	}
	return wordIndex;
}
int indexOf(char *word, word_count_word_t *words) {
	for(int i = 0; i < MAX_WORDS; i++) {
		if(words[i].text != NULL && strcmp(word, words[i].text) == 0)
			return i;
	}
	return -1;
}