#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#define EARTH 0
#define MERCURY 1
#define VENUS 2
#define MARS 3
#define JUPITER 4
#define SATURN 5
#define URANUS 6
#define NEPTUNE 7

#define EARTH_YEAR 31557600 
#define MERCURY_YEAR 0.2408467 * EARTH_YEAR
#define VENUS_YEAR 0.61519726 * EARTH_YEAR
#define MARS_YEAR 1.8808158 * EARTH_YEAR
#define JUPITER_YEAR 11.862615 * EARTH_YEAR
#define SATURN_YEAR 29.447498 * EARTH_YEAR
#define URANUS_YEAR 84.016846 * EARTH_YEAR
#define NEPTUNE_YEAR 164.79132 * EARTH_YEAR

double convert_planet_age(int planet, long seconds);

#endif