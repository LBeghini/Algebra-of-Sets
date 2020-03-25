#include <stdio.h>
#include "fileIO.h"
#include "set.h"
#define PATH "C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt"



int main()
{

    Line *input =  process_input(PATH);

    print_lines(input);
    return 0;
}
