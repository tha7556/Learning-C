#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H


typedef struct factor_type {
	int factor_a;
	int factor_b;
	struct factor_type *next;
}factor_t;

typedef struct product_type {
	long smallest;
	long largest;
	factor_t *factors_sm;
	factor_t *factors_lg;
	char *error;
}product_t;

product_t *get_palindrome_product(int start, int end);
void free_product(product_t *product);

#endif