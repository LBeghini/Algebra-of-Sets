//
// Created by Lavinia on 3/23/2020.
//

#include "set.h"

#ifndef DISCRETE_FILEIO_H
#define DISCRETE_FILEIO_H

typedef struct Line{
    char *value;
    struct  Line *next;
} Line;

char *parse(char *path);
Line * split(char * str, char *separator);
void print_lines(Line *head);
void remove_spaces_from_lines(Line *head);
void remove_spaces(char * s);
Line *process_input(char *path);
Line* get_numbers(char *s);


#endif //DISCRETE_FILEIO_H
