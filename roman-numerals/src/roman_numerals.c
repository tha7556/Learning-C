#include "roman_numerals.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

dictionary digits[] = {
	{1, "I"},
	{4, "IV"},
	{5, "V"},
	{9, "IX"},
	{10, "X"},
	{40, "XL"},
	{50, "L"},
	{90, "XC"},
	{100, "C"},
	{400, "CD"},
	{500, "D"},
	{900, "CM"},
	{1000, "M"}
};
	
char *to_roman_numeral(int number) {
	char *result = (char*)malloc(sizeof(char) * 10);
	result[0] = '\0';
	for(int i = sizeof(digits)/sizeof(digits[0]) - 1; i >= 0; i--) {
		if(digits[i].key <= number) {
			strcat(result, digits[i].value);
			char *temp = to_roman_numeral(number-digits[i].key);
			strcat(result, temp);
			free(temp);
			return result;
		}
	}
	
	return result;
}