#include "clock.h"
#include <stdio.h>


void clock(time_text_t time_text, int hour, int minute) {
	int h = hour;
	int m = minute;
	while(m > 59) {
		h++;
		m -= 60;
	}
	while(m < 0) {
		h--;
		m = 60 + m;
	}
	while(h > 23) {
		h -= 24;
	}
	while(h < 0) {
		h = 24 + h;
	}
	sprintf(time_text,"%02d:%02d",h, m);
}
void clock_add(time_text_t time_text, int minute_offset) {
	int h = minute_offset;
	h = 0;
	int m = 0;
	for(int i = 0; i < 2; i++) {
		int multiplier = 1;
		if(i == 0)
			multiplier = 10;
		h += multiplier * ((int)time_text[i] - 48);
	}
	for(int i = 3; i < 5; i++) {
		int multiplier = 1;
		if(i == 3)
			multiplier = 10;
		m += multiplier * ((int)time_text[i] - 48);
	}
	clock(time_text, h, m + minute_offset);
}