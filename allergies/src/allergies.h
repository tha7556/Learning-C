#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS = 1,
   ALLERGEN_SHELLFISH = 2,
   ALLERGEN_STRAWBERRIES = 3,
   ALLERGEN_TOMATOES = 4,
   ALLERGEN_CHOCOLATE = 5,
   ALLERGEN_POLLEN = 6,
   ALLERGEN_CATS = 7,
} allergen_t;

typedef struct {
   int count;
   allergen_t *allergens;
} allergen_list_t;

void get_allergens(int score, allergen_list_t *list);
bool is_allergic_to(allergen_t allergen, int code);

#endif
