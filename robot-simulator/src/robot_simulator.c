#include "robot_simulator.h"
#include <string.h>
#include <ctype.h>

robot_grid_status_t robot_init(void) {
	return robot_init_with_position(DEFAULT_BEARING, DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE);
}
robot_grid_status_t robot_init_with_position(int bearing, int x, int y) {
	if(bearing < 0 || bearing > 3)
		bearing = 0;
	robot_coordinates_t loc;
	loc.x_position=x;
	loc.y_position=y;
	robot_grid_status_t robot;
	robot.bearing = bearing;
	robot.grid = loc;
	return robot;
}
void robot_turn_right(robot_grid_status_t * robot) {
	if(robot->bearing == 3)
		robot->bearing = HEADING_NORTH;
	else
		robot->bearing++;
	
}
void robot_turn_left(robot_grid_status_t * robot) {
	if(robot->bearing == 0)
		robot->bearing = HEADING_WEST;
	else 
		robot->bearing--;
	
}
void robot_advance(robot_grid_status_t * robot) {
	switch(robot->bearing) {
		case(HEADING_NORTH):
			robot->grid.y_position++;
			break;
		case(HEADING_SOUTH):
			robot->grid.y_position--;
			break;
		case(HEADING_EAST):
			robot->grid.x_position++;
			break;
		case(HEADING_WEST):
			robot->grid.x_position--;
			break;
	}
}
void robot_simulator(robot_grid_status_t * robot, const char *commands) {
	while(*commands != '\0') {
		char c = toupper(*commands++);
		switch(c) {
			case('R'):
				robot_turn_right(robot);
				break;
			case('L'):
				robot_turn_left(robot);
				break;
			case('A'):
				robot_advance(robot);
				break;
		}
	}
}