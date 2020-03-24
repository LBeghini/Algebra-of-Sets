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
Line * split(char * strFile);
void print_lines(Line *head);
void remove_spaces_from_lines(Line *head);
void remove_spaces(char * s);

#endif //DISCRETE_FILEIO_H
