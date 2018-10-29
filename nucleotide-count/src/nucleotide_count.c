#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>

char *count(const char *dna) {
	char *result = malloc(sizeof(char));
	result[0] = '\0';
	if(!dna)
		return result;	
	int data[4] = {0};
	while(*dna != '\0') {
		switch(*dna++) {
			case 'A':
				data[NUCLEO_A]++;
				break;
			case 'C':
				data[NUCLEO_C]++;
				break;
			case 'G':
				data[NUCLEO_G]++;
				break;
			case 'T':
				data[NUCLEO_T]++;
				break;
			default:
				return result;
		}
	}
	free(result);
	result = malloc(sizeof(char)*25);
	sprintf(result, "A:%d C:%d G:%d T:%d", data[0], data[1], data[2], data[3]);
	return result;
}