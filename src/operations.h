//
// Created by Lavinia on 3/28/2020.
//

#ifndef DISCRETE_OPERATIONS_H
#define DISCRETE_OPERATIONS_H
#define OPERANDS "+*x<>-[(])"

#include "set.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"

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
int belongs_to(int value, Node *A);
Set * unite(Set *A, Set *B);
Set * intersect(Set *A, Set *B);
Set * subtract (Set *A, Set *B);
int is_subset(Set *A, Set*B);
int is_proper_subset(Set *A, Set *B);
Line * set_to_line(Set *A);
Line * do_couple(char* x, char *y);
Line  * do_cartesian_product(Line *A, Line *B);
int is_operator(char * str);
Set *find_set_in_tree(Tree *tree);
char * solve_operation_tree(Tree *tree);
int find_element_in_tree(Tree *tree);
Line *solve_cartesian_operation_tree(Tree *tree);
char * set_to_string(Set *A);
char * cartesian_to_string(Line *A);
Set * undo_cartesian_product(char* cartesian);

#endif //DISCRETE_OPERATIONS_H
