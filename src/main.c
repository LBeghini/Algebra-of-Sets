#include <stdio.h>
#include "fileIO.h"
#include "set.h"
#define PATH "C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt"



int main()
{

    char * file = parse(PATH);
    Line *head = split(file);
    print_lines(head);


    return 0;
}
