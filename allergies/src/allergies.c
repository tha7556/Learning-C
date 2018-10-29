#include "allergies.h"
#include <stdlib.h>

allergen_t allAllergens[] = {ALLERGEN_EGGS, ALLERGEN_PEANUTS, ALLERGEN_SHELLFISH, ALLERGEN_STRAWBERRIES, ALLERGEN_TOMATOES, ALLERGEN_CHOCOLATE, ALLERGEN_POLLEN, ALLERGEN_CATS};

void get_allergens(int score, allergen_list_t *list) {
	list->allergens = (allergen_t*)malloc(sizeof(allergen_t) * 7);
	list->count = 0;
	int index = 0;
	for(int i = 0; i <= 7; i++) {
		int x = 0 != (score & (1 << i));
		if(x == 1) {
			list->allergens[index] = allAllergens[i];
			list->count++;
			index++;
		}
	}
}
bool is_allergic_to(allergen_t allergen, int code) {
	return 0 != (code & (1 << allergen));
}
