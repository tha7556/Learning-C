#include "pascals_triangle.h"

size_t **create_triangle(int rows) {
	if(rows < 0)
		return 0;
	size_t **result;
	if(rows > 0) {
		result = malloc(sizeof(size_t*)*rows);
		for(int i = 0; i < rows; i++) {
			result[i] = malloc(sizeof(size_t)*rows);
			for(int j = 0; j < rows; j++) {
				if(i == 0) { //first row
					if(j == 0)
						result[i][j] = 1;
					else
						result[i][j] = 0;
				}
				else { //normal rows
					if(j == 0)
						result[i][j] = 1;
					else 
						result[i][j] = result[i-1][j-1] + result[i-1][j];
				}
			}
		}
	}
	else if(rows == 0){
		result = calloc(sizeof(size_t*),rows+1);
		result[0] = calloc(sizeof(size_t), 1);
		result[0][0] = 0;
	}
	else
		return NULL;
	return result;
}
void free_triangle(size_t **triangle, int rows) {
	for(int i = 0; i < rows; i++)
		free(triangle[i]);
	free(triangle);
}