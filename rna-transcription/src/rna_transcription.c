#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna) {
	if(dna == NULL)
		return NULL;
	char *result = (char*)malloc(sizeof(char) * strlen(dna)+1);
	int i = 0;
	while(*dna != '\0') {
		char val = *dna++;
		if(val == 'G')
			result[i] = NUCLEO_G;
		else if(val == 'C')
			result[i] = NUCLEO_C;
		else if(val == 'T')
			result[i] = NUCLEO_T;
		else if(val == 'A')
			result[i] = NUCLEO_A;
		else {
			free(result);
			return NULL;
		}
		i++;
	}
	result[i] = '\0';
	return result;
}