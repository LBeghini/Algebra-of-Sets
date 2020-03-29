#include <stdio.h>
#include "fileIO.h"
#include "set.h"
#include "operations.h"
#define PATH "C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt"



int main()
{

    Line *input =  process_input(PATH);

    Set *listOfSets;
    Element *listOfElements = NULL;
    listOfSets = (Set*) malloc(sizeof(Set));

    listOfSets = create_list_set(listOfSets, input);
    listOfElements = create_list_element(listOfElements, input);

    char * teste = "AuB";

    if(check_existing_operands(listOfElements, listOfSets, teste)){
        printf("exists");
    }else{
        printf("dont exists");
    }

    Tree *tree = generate_operation_tree(teste);
    printf("CARAO");

    Set * result = set_subtraction(listOfSets, listOfSets->next);
    printf("AAA");

    return 0;
}