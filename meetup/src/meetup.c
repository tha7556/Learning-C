#include "meetup.h"
#include <string.h>

int readDay(const char *day) {
	if(strcmp(day, "Sunday") == 0)
		return SUNDAY;
	else if(strcmp(day, "Monday") == 0)
		return MONDAY;
	else if(strcmp(day, "Tuesday") == 0)
		return TUESDAY;
	else if(strcmp(day, "Wednesday") == 0)
		return WEDNESDAY;
	else if(strcmp(day, "Thursday") == 0)
		return THURSDAY;
	else if(strcmp(day, "Friday") == 0)
		return FRIDAY;
	else if(strcmp(day, "Saturday") == 0)
		return SATURDAY;
	return -1;
}
int getDay(int year, int month, int day) {
	int y = year;
	int m = month-2;
	if(m < 1) {
		m = month + 10;
		y--;
	}
	int century = y / 100;
	y = y % 100;
	int result = day + (int)(2.6 * m - 0.2) - 2 * century + y + (int)(y/4.0) + (int)(century/4.0);
	return result % 7;
}
int daysInMonth(int year, int month) {
	if(month == 2) { //February
		if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) //Leap year
			return 29;
		return 28;
	}
	if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}
int getWeek(int year, int month, const char *descriptor) {
	if(strcmp(descriptor, "first") == 0)
		return 1;
	else if(strcmp(descriptor, "second") == 0)
		return 8;
	else if(strcmp(descriptor, "third") == 0)
		return 15;
	else if(strcmp(descriptor, "fourth") == 0)
		return 22;
	else if(strcmp(descriptor, "fifth") == 0)
		return 29;
	else if(strcmp(descriptor, "teenth") == 0)
		return 13;
	else if(strcmp(descriptor, "last") == 0)
		return daysInMonth(year, month) - 6;
	return -1;
}

int meetup_day_of_month(int year, int month, const char *descriptor, const char *day) {
	int weekOffset = getWeek(year, month, descriptor);
	int offsetDay = getDay(year, month, weekOffset); 
	int targetWeekday = readDay(day);
	int result = weekOffset + (targetWeekday - offsetDay + 7) % 7;
	if(result > daysInMonth(year, month))
		return 0;
	return result;
}