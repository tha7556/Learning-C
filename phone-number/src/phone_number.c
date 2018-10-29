#include "phone_number.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *removeInvalidChars(const char input[]) {
	int length = strlen(input);
	char *result = malloc(sizeof(char) * length+1);
	int index = 0;
	for(int i = 0; i < length; i++) {
		if(isalpha(input[i]))  {
			free(result);
			return 0;
		}
		else if(isdigit(input[i])) {
			result[index] = input[i];
			index++;
		}
	}
	result[index] = '\0';
	return result;
}
char *phone_number_clean(const char input[]) {
	char *result = removeInvalidChars(input);
	if(result) {
		if(strlen(result) == 11 && result[0] == '1') { //has country code
			char next = result[1];
			for(int i = 0; i < 11; i++) {
				if(i < 10)
					next = result[i+1];
				result[i] = next;
			}
			result[10] = '\0';
		}
		if(strlen(result) == 10)
			return result;
	}
	else
		result = malloc(sizeof(char)*11);
	memset(result,'0',10);
	result[10] = '\0';
	return result;
}
char *phone_number_get_area_code(const char input[]) {
	char *result = phone_number_clean(input);
	result[3] = '\0';
	return result;
}
char *phone_number_format(const char input[]) {
	char *result = malloc(sizeof(char)*13);
	char *cleaned = phone_number_clean(input);
	sprintf(result,"(%c%c%c) %c%c%c-%c%c%c%c", cleaned[0], cleaned[1], cleaned[2], cleaned[3], cleaned[4], cleaned[5], cleaned[6], cleaned[7], cleaned[8], cleaned[9]);
	free(cleaned);
	return result;
}
