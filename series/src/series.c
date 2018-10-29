#include "series.h"
#include <stdlib.h>
#include <string.h>

series_results_t series(char *input_text, unsigned int substring_length) {
	if(substring_length < 1 || substring_length > MAX_SERIES_LENGTH || strlen(input_text) > MAX_INPUT_TEXT_LENGTH || strlen(input_text) < substring_length) {
		series_results_t result = {0, NULL};
		return result;
	}
	char ** result = (char**)malloc(sizeof(char*) * MAX_SERIES_RESULTS);
	int length = strlen(input_text);
	unsigned int i = 0;
	for(; i <= length-substring_length; i++) {
		result[i] = (char*)malloc(sizeof(char)*substring_length+1);
		for(unsigned int j = 0; j < substring_length; j++) {
			result[i][j] = input_text[i+j];
		}
		result[i][substring_length] = '\0';
	}
	series_results_t r = { i, result };
	return r;
	
}