#include <stdio.h>
#include "fileIO.h"
#include "set.h"
#include "operations.h"
#define PATH "C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt"



int main()
{

    Line *input =  process_input(PATH);

    Set *listOfSetHeads;
    Element *listOfElements = NULL;
    listOfSetHeads = (Set*) malloc(sizeof(Set));

    listOfSetHeads = create_list_set(listOfSetHeads, input);
    listOfElements = create_list_element(listOfElements, input);

    char * teste = "AuB";

    if(check_existing_operands(listOfElements, listOfSetHeads, teste)){
        printf("exists");
    }else{
        printf("dont exists");
    }

    Tree *tree = generate_operation_tree(teste);
    printf("CARAO");


    return 0;
}