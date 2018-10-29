#include "beer_song.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* pluralBottles(int number) {
	char *result = malloc(15*sizeof(char));
	if(number == 0) {
		sprintf(result, "no more bottles");
	}
	else if(number == 1) {
		sprintf(result, "1 bottle");
	}
	else {
		sprintf(result, "%d bottles", number);
	}
	return result;
}
void verse(char result[], int verseNumber) {
	char *bottles = pluralBottles(verseNumber);
	sprintf(result, "%s of beer on the wall, %s of beer.\n", bottles, bottles);
	if(verseNumber == 0) {
		result[0] = toupper(result[0]);
		strcat(result, "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
	}
	else if(verseNumber == 1) {
		strcat(result, "Take it down and pass it around, no more bottles of beer on the wall.\n");
	}
	else {
		char *otherBottles = pluralBottles(verseNumber-1);
		sprintf(result, "%sTake one down and pass it around, %s of beer on the wall.\n",result, otherBottles);
		free(otherBottles);
	}
	free(bottles);
}

void sing(char result[], int startVerse, int endVerse) {
	result[0] = '\0';
	for(int i = startVerse; i >= endVerse; i--) {
		char *temp = malloc(130*sizeof(char));
		verse(temp,i);
		strcat(result,temp);
		if(i != endVerse)
			strcat(result,"\n");
		free(temp);
	}
}
