//
// Created by Lavinia on 3/23/2020.
//

#ifndef DISCRETE_SET_H
#define DISCRETE_SET_H

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct ListOfSetHeads {
    char name;
    struct Node * head;
    struct ListOfSetHeads * next;
} ListOfSetHeads;

#endif //DISCRETE_SET_H
