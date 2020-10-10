//
// Created by Lavinia on 3/23/2020.
//

#ifndef DISCRETE_SET_H
#define DISCRETE_SET_H



#include "fileIO.h"
#include "global.h"

Set *create_list_set(Set *head, Line *input);
Element *create_list_element(Element *head, Line *input);
void populate(Set *empty, Line *charNumbers);
void process_nodes(Node *current, Line *charNumber);
Node * copy_of_node(Node *A);
Set * copy_of_set(Set * A);
char * set_to_string(Set *A);
Set * string_to_set(char * str);

#endif //DISCRETE_SET_H