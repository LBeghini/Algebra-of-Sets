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


Tree *prepare_operation_tree(char *str);
void fill_operation_tree(char *str, Tree *current);
char * solve_operation_tree(Tree *tree);
int find_element_in_tree(Tree *tree);
Set *find_set_in_tree(Tree *tree);

int belongs_to(int value, Node *A);
int is_proper_subset(Set *A, Set *B);
int is_subset(Set *A, Set*B);

Set * unite(Set *A, Set *B);
Set * subtract (Set *A, Set *B);
Set * intersect(Set *A, Set *B);
Set* powerset(Set* head);
void fill_powerset(Set* list, int element);
Set * undo_powerset(char* A);
Line *solve_cartesian_operation_tree(Tree *tree);
Line * set_to_line(Set *A);
Line * do_cartesian_product(Line *A, Line *B);
Line * do_couple(char* x, char *y);
Set * undo_cartesian_product(char* cartesian);

char * cartesian_to_string(Line *A);
char * powerset_to_string(Set *A);


#endif //DISCRETE_OPERATIONS_H
