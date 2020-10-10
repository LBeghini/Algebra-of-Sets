//
// Created by Lavinia on 10/9/2020.
//

#ifndef DISCRETE_GLOBAL_H
#define DISCRETE_GLOBAL_H

#define OPERANDS "+*x<>-[(])"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct Set {
    char name;
    struct Node * head;
    struct Set * next;
} Set;

typedef struct Element {
    int value;
    char name;
    struct Element *next;
} Element;

Set *listOfSets;
Element *listOfElements;

int validate(char *str);int contains_in_elements(char target);
int is_powerset(char *str);
int is_cartesian(char* input);

#endif //DISCRETE_GLOBAL_H
