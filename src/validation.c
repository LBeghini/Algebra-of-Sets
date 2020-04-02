//
// Created by Lavinia on 4/2/2020.
//

#include "validation.h"



int validate(char *str) {
    if (is_odd((int)strlen(str)) && (int)strlen(str) > 1) {
        if(check_operators(str)){
            if(check_operands(str)){
                if(belongs_subsets_quantities(str)){
                    if(check_belongs(str)){
                        return 1;
                    }
                }
            }
        }
    }else if(is_powerset(str)){
        return 1;
    }
    return 0;
}

int check_operators(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (is_odd(i)) {
            if(!strchr(OPERANDS, *(str+i))){
                return 0;
            }
        }
    }
    return 1;
}

int check_operands(char *str){
    for (int i = 0; i < strlen(str); ++i) {
        char current = *(str+i);
        if (!is_odd(i)) {
            if(current>='A' && current<='Z'){
                if(contains_in_sets(current) && i!=0){
                    return 1;
                }
            }else if(current>='a' && current<='z'){
                if(contains_in_elements(current) && i==0) {
                    return 0;
                }
            }
        }

    }

    return 0;
}

int contains_in_elements(char target) {
    Element *current = listOfElements;
    while (current) {
        if ( current->name == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int contains_in_sets(char target) {
    Set *current = listOfSets;
    while (current) {
        if (current->name == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int is_odd(int num) {
    return num % 2;
}

int belongs_subsets_quantities(char *str){
    char *operators = "[]()<>";
    if(!strpbrk(str, operators)){
        return 1;
    }else if(strpbrk(str, operators) && strpbrk(strpbrk(str, operators)+1, operators )){
        return 0;
    }
    return 1;
}

int check_belongs(char *str){
    if(strpbrk(str, "<>")){
        if(*(str+1)!=*strpbrk(str, "<>")){
            return 0;
        }
    }

    return 1;
}

int is_powerset(char *str){
    char outside[3];

    for(int i=0; i<2; i++) {
        outside[i] = *(str + i);

    }
    outside[2] = *(str + (int)strlen(str) - 1);
    char ps[3] = "P()";
    for(int i=0; i<3; i++){
        if(outside[i] != ps[i]){
            return 0;
        }
    }

    char * inside = string_to_powerset(str);
    if(is_odd((int)strlen(inside)) && (int)strlen(inside) >= 1){
        for(int i=0; i<(int)strlen(inside); i++) {
            if(is_odd(i)) {
                if(!strchr("+-*", *(inside+i))){
                    return 0;
                }
            }
        }
    }

    if(!check_operands(inside)){
        return 0;
    }

    return 1;
}

char * string_to_powerset(char* str){
    char *result = (char*) malloc(sizeof(char) * (int)strlen(str));
    result =strcpy(result, str+2);
    strcpy((result+strlen(result)-1), "\0");
    return result;
}






