#include "atbash_cipher.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char flipChar(char letter) {
	char result = tolower(letter);
	if(result >= 'a' && result <= 'z') {
		if(result > 'm') {
			result -= (2*(result - 'm')-1);
		}
		else {
			result += (2*('n'-result)-1);
		}
	}
	return result;
}
char *atbash_encode(char *input) {
	int length = strlen(input);
	char *result = (char*)malloc(sizeof(char) *  (length + (length/5+1)));
	int index = 0;
	int count = 0;
	for(int i = 0; i < length; i++) {
		if(count == 5 && isalnum(input[i])) {
			result[index] = ' ';
			count = 0;
			index++;
			i--;
		}
		else {
			if(isalnum(input[i])) {
				result[index] = flipChar(input[i]);
				index++;
				count++;
			}
		}
	}
	result[index] = '\0';
	return result;
}
char *atbash_decode(char *input) {
	int length = strlen(input);
	char *result = (char*)malloc(sizeof(char) * (length+1 - (length/5)));
	int index = 0;
	for(int i = 0; i < length; i++) {
		if(input[i] != ' ') {
			result[index] = flipChar(input[i]);
			index++;
		}
	}
	result[index] = '\0';

	return result;
}
