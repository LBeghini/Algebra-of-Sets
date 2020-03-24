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

#endif //DISCRETE_FILEIO_H
