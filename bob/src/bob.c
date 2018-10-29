#include "bob.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isAllUpper(char *input) {
	bool hasLetter = false;
	while(*input != '\0') {
		char c = *input++;
		if(c != toupper(c))
			return false;
		if(c >= 65 && c <= 90)
			hasLetter = true;
	}
	return hasLetter;
}
bool isQuestion(char *input) {
	int index = strlen(input)-1;
	while(input[index] == ' ' || input[index] == '\n' || input[index] == '\t' || input[index] == '\r') {
		index--;
	}
	return input[index] == '?';
}
bool isEmpty(char *input) {

	while(*input != '\0') {
		char c = *input++;
		if(c != ' ' && c != '\t' && c != '\n' && c != '\r')
			return false;
	}
	return true;
}
char *hey_bob(char *input) {
	if(isEmpty(input))
		return "Fine. Be that way!";
	else if(isAllUpper(input)) {
		if(isQuestion(input))
			return "Calm down, I know what I'm doing!";
		else
			return "Whoa, chill out!";
	}
	else if(isQuestion(input)) {
		return "Sure.";
	}
	
	else
		return "Whatever.";
}