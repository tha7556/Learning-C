#ifndef MEETUP_H
#define MEETUP_H

#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

int meetup_day_of_month(int year, int month, const char *descriptor, const char *day);

#endif