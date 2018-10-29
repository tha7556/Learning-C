#include "triangle.h"

int isTriangle(triangle_t *triangle) {
	if(triangle->a <= 0 || triangle->b <= 0 || triangle->c <= 0) 
		return 0;
	if(triangle->a + triangle->b <= triangle->c || triangle->a + triangle->b <= triangle->c || triangle->b + triangle->c <= triangle->a)
		return 0;
	return 1;
}
int is_equilateral(triangle_t triangle) {
	return triangle.a != 0 && triangle.a == triangle.b && triangle.a == triangle.c && isTriangle(&triangle);
}
int is_isosceles(triangle_t triangle) {
	return (triangle.a == triangle.b || triangle.a == triangle.c || triangle.b == triangle.c) && isTriangle(&triangle);
}
int is_scalene(triangle_t triangle) {
	return triangle.a != triangle.b && triangle.a != triangle.c && triangle.b != triangle.c && isTriangle(&triangle);
}
