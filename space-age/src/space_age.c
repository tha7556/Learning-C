#include "space_age.h"

const double years[] = {EARTH_YEAR, MERCURY_YEAR, VENUS_YEAR, MARS_YEAR, JUPITER_YEAR, SATURN_YEAR, URANUS_YEAR, NEPTUNE_YEAR};

double convert_planet_age(int planet, long seconds) {
	if(planet >= EARTH && planet <= NEPTUNE) {
		return seconds / years[planet];
	}
	else
		return -1.0;
}