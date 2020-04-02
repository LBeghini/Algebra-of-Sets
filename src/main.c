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


//    char * teste = "AuB";
//
//    if(check_existing_operands(listOfElements, listOfSets, teste)){
//        printf("exists");
//    }else{
//        printf("dont exists");
//    }
//
//    Tree *tree = generate_operation_tree(teste);
//    printf("CARAO");
//
//    Set * result = subtract(listOfSets, listOfSets->next);
//    printf("AAA");
//
//    if(belongs_to(listOfSets->head, listOfElements->value)){
//        printf("yes");
//    }else{
//        printf("no");
//    }

//    if(is_subset(listOfSets, listOfSets->next)){
//        printf("subset? yes\n");
//    }else{
//        printf("subset? no\n");
//    }
//
//    if(is_proper_subset(listOfSets, listOfSets->next)){
//        printf("proper subset? yes\n");
//    }else{
//        printf("proper subset? no\n");
//    }

//    char *strTeste = "A+B";
//    Tree *teste =generate_operation_tree(strTeste);
//    printf("%s",solve_operation_tree(teste));

    Set * copy = copy_of_set(listOfSets);
    printf("a");

    return 0;


}