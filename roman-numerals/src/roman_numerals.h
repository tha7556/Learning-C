#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

typedef struct {
	int key;
	const char *value;
}dictionary;

char *to_roman_numeral(int number);

#endif