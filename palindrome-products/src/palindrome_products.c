#include "palindrome_products.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int isPalindrome(int num) {
	if(num < 10 && num >= 0) 
		return 1;
	char string[5];
	sprintf(string,"%d",num);
	char reverse[5];
	int j = 0;
	for(int i = strlen(string)-1; i >= 0; j++,i--) {
		reverse[j] = string[i];
	}
	reverse[j] = '\0';
	return strcmp(string,reverse) == 0;
}
void append(int *index, factor_t *array, int a, int b) {
	for(int i = 0; i < *index; i++) {
		if((array[i].factor_a == a && array[i].factor_b == b) || (array[i].factor_a == b && array[i].factor_b == a)) {
			return;
		}
	}
	array[*index].factor_a = a;
	array[*index].factor_b = b;
	array[*index].next = 0;
	array[*index-1].next = &array[*index];
	*index = *index + 1;
}
product_t *get_palindrome_product(int start, int end) {
	product_t *product = calloc(sizeof(product_t),1);
	if(start > end) {
		product->error = malloc(sizeof(char)*60);
		sprintf(product->error,"invalid input: min is %d and max is %d", start, end);
		return product;
	}
	product->smallest = INT_MAX;
	product->largest = INT_MIN;
	product->factors_sm = (factor_t*)malloc(sizeof(factor_t)*15);
	product->factors_lg = (factor_t*)malloc(sizeof(factor_t)*15);
	int smIndex = 0, lgIndex = 0;
	for(int i = start; i <= end; i++) {
		for(int j = start; j <= end; j++) {
			int num = i * j;
			if(isPalindrome(num) == 1) {
				if(num == product->largest) {
					append(&lgIndex,product->factors_lg,i,j);
				}
				if(num == product->smallest) {
					append(&smIndex,product->factors_sm,i,j);
				}
				if(num > product->largest) {
					product->largest = num;
					product->factors_lg[0].factor_a = i;
					product->factors_lg[0].factor_b = j;
					product->factors_lg[0].next = 0;
					lgIndex = 1;
				}
				if(num < product->smallest) {
					product->smallest = num;
					product->factors_sm[0].next = 0;
					smIndex = 1;
				}
			}
		}
	}
	if(product->largest == INT_MIN || product->smallest == INT_MAX) {
		product->error = malloc(sizeof(char)*60);
		sprintf(product->error,"no palindrome with factors in the range %d to %d", start, end);
	}
	return product;
}
void free_product(product_t *product) {
	free(product->factors_sm);
	free(product->factors_lg);
	free(product);
}