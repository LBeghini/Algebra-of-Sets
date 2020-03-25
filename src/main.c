#include <stdio.h>
#include "fileIO.h"
#include "set.h"
#define PATH "C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt"



int main()
{

    Line *input =  process_input(PATH);

    Set *listOfSetHeads;
    Element *listOfElements;
    listOfSetHeads = (Set*) malloc(sizeof(Set));

    listOfSetHeads = create_list_set(listOfSetHeads, input);
    listOfElements = create_list_element(listOfElements, input);

    printf("nothing");

    return 0;
}
