//
// Created by Lavinia on 4/2/2020.
//

#ifndef DISCRETE_VALIDATION_H
#define DISCRETE_VALIDATION_H

#include "global.h"

int check_operators(char *str);
int check_operands(char *str);
int is_odd(int num);
int validate(char *str);int contains_in_elements(char target);
int contains_in_sets(char target) ;
int belongs_subsets_quantities(char *str);
int check_belongs(char *str);
int is_powerset(char *str);
char * string_to_powerset(char* str);

#endif //DISCRETE_VALIDATION_H
