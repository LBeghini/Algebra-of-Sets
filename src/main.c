#include "set.h"
#include "global.h"
#include <stdio.h>
#include "fileIO.h"
#include "operations.h"
#include <conio.h>

#include "validation.h"

void clear_console(){
#if defined _WIN32
    system("cls");
#elif defined (LINUX) || defined(gnu_linux) || defined(linux)
    system("clear");
#elif defined (APPLE)
    system("clear");
#endif
}

void print_set(Set* sets){
    printf("       %c = {", sets->name);
    Node* current = sets->head;
    while (current){
        printf("%d", current->value);
        if(current->next){
            printf(", ");
        } else{
            printf("}\n");
        }
        current = current->next;
    }
}

void print_sets(Set* set){
    while (set){
        print_set(set);
        set = set->next;
    }
}
void print_elements(Element* element){
    while (element){
        printf("       %c = %d\n", element->name, element->value);
        element = element->next;
    }
}

void solve(char* input){
    remove_spaces(input);
    if(validate(input)){
        char* solution = solve_operation_tree(prepare_operation_tree(input));
        printf("------------------------------------------------\n");
        printf("SOLUTION: %s\n", solution);
        printf("------------------------------------------------\n");

        if(is_cartesian(input)){
            printf("Would you like to reverse it?");
            printf("(y/n)");
            char r;
            r = getch();
            if(r == 'y'){
                Set* result = undo_cartesian_product(solution);
                while (result){
                    printf("\n%s", set_to_string(result));
                    result = result->next;
                }
            }
        }
    } else if(is_powerset(input)){
        char* solution = powerset_to_string(powerset(string_to_set(solve_operation_tree(
                prepare_operation_tree(string_to_powerset(input))))));
        printf("------------------------------------------------\n");
        printf("SOLUTION: %s\n", solution);
        printf("------------------------------------------------\n");
        printf("Would you like to reverse it?");
        printf("(y/n)");
        char r;
        r = getch();
        if(r == 'y'){
            Set* result = undo_powerset(solution);
            printf("\n%s", set_to_string(result));
        }
    } else{
        printf("------------------------------------------------\n");
        printf("ERROR: OPERATION NOT VALID\n");
        printf("------------------------------------------------\n");
    }

}


int main()
{

    Line *input =  process_input();

    listOfSets = (Set*) malloc(sizeof(Set));
    listOfElements = (Element*) malloc(sizeof(Element));

    listOfSets = create_list_set(listOfSets, input);
    listOfElements = create_list_element(listOfElements, input);

#ifndef DEBUG
    clear_console();
    printf("           _            _                        __    _____      _       \n"
           "     /\\   | |          | |                      / _|  / ____|    | |      \n"
           "    /  \\  | | __ _  ___| |__  _ __ __ _    ___ | |_  | (___   ___| |_ ___ \n"
           "   / /\\ \\ | |/ _` |/ _ \\ '_ \\| '__/ _` |  / _ \\|  _|  \\___ \\ / _ \\ __/ __|\n"
           "  / ____ \\| | (_| |  __/ |_) | | | (_| | | (_) | |    ____) |  __/ |_\\__ \\\n"
           " /_/    \\_\\_|\\__, |\\___|_.__/|_|  \\__,_|  \\___/|_|   |_____/ \\___|\\__|___/\n"
           "              __/ |                                                       \n"
           "             |___/                                                        ");


    printf("\nPRESS ANY KEY TO START");
    getch();

    char e = ' ';

while (e != 'e'){
        clear_console();
        printf("------------------------------------------------\n");
        printf(" SETS:                                          \n");
        print_sets(listOfSets);
        printf("\n");
        printf(" ELEMENTS:\n");
        print_elements(listOfElements);
        printf("\n");
        printf("------------------------------------------------\n");
        printf(" OPERATIONS:\n");
        printf("       Union:......................... +\n"
               "       Subtraction:................... -\n"
               "       Intersection:.................. *\n"
               "       Belongs:....................... <\n"
               "       Does not belong:............... >\n"
               "       Subset:........................ (\n"
               "       Not Subset:.................... )\n"
               "       Proper subset:................. [\n"
               "       Not proper subset:............. ]\n"
               "       Cartesian Product.............. x\n"
               "       Powerset:...................... P()\n\n");
        printf("------------------------------------------------\n");
        printf("OPERATION STRING: ");
        char* ops = (char*)calloc(10, sizeof(char));
        gets(ops);
        solve(ops);
        printf("\nPRESS ANY KEY TO CONTINUE OR e TO EXIT");
        e = getch();
    }
#endif


    return 0;


}