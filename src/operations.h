//
// Created by Lavinia on 3/28/2020.
//

#ifndef DISCRETE_OPERATIONS_H
#define DISCRETE_OPERATIONS_H

#include "set.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Tree {
    char *value;
    struct Tree *left;
    struct Tree *right;
} Tree;

int exists(char *str, char *target);
int check_operators(char *str);
int check_c_and_e(char *str);
int is_odd(int num);
int validate(const char *str);
void fill_operation_tree(char *str, Tree *current);
Tree *generate_operation_tree(char *str);
int check_existing_operands(Element *listOfElements, Set *listOfSets, char *str);
int exist_value(Node *A, int value);
Set * set_union(Set *A, Set *B);
Set * set_intersection(Set *A, Set *B);

#endif //DISCRETE_OPERATIONS_H
