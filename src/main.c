#include "set.h"
#include "global.h"
#include <stdio.h>
#include "fileIO.h"
#include "operations.h"
#include "validation.h"
#define PATH "C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt"


int main()
{

    Line *input =  process_input(PATH);

    listOfSets = (Set*) malloc(sizeof(Set));
    listOfElements =(Element*) malloc(sizeof(Element));

    listOfSets = create_list_set(listOfSets, input);
    listOfElements = create_list_element(listOfElements, input);

    char * strTeste= "B(C";
    Tree * teste = generate_operation_tree(strTeste);
    char * s = solve_operation_tree(teste);
    printf("%s", s);

    return 0;


}