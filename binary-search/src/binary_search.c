#include "binary_search.h"

int *binary_search(int value, int arr[], int length) {
	if(arr == 0 || length == 0)
		return 0;
	int leftIndex = 0;
	int rightIndex = length - 1;
	int middleIndex;
	while(leftIndex < rightIndex) {
		middleIndex = (leftIndex + rightIndex) / 2;
		if(arr[middleIndex] < value) {
			leftIndex = middleIndex + 1;
		}
		else
			rightIndex = middleIndex;
	}
	if(arr[leftIndex] == value) {
		return &arr[leftIndex];
	}
	return 0;
}