//
// Created by Lavinia on 3/28/2020.
//

#include "operations.h"
#include "set.h"

int exists(char *str, char *target) {
    for (int i = 0; i < strlen(str); ++i) {
        if (*(str + i) == target) {
            return 1;
        }
    }
    return 0;
}

int check_operators(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (i % 2) {
            if (!exists("euc", *(str + i))) {
                return 0;
            }
        } else {
            if (exists("euc", *(str + i))) {
                return 0;
            }
        }
    }
    return 1;
}

int check_c_and_e(char *str) {
    int count_c = 0;
    int count_e = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if ((*(str + i) == 'c')) {
            count_c++;
        }
        if ((*(str + i) == 'e')) {
            count_e++;
            if (i != 1) {
                return 0;
            }
        }
    }

    if ((count_e + count_c) > 1) {
        return 0;
    }

    return 1;
}

int is_odd(int num) {
    return num % 2;
}

int validate(const char *str) {
    if (is_odd(strlen(str)) && strlen(str) > 1) {
        if (check_c_and_e(str)) {
            if (check_operators(str)) {
                return 1;
            }
        }
    }
    return 0;
}

void fill_operation_tree(char *str, Tree *current){
    char *buff = (char*)malloc(sizeof(char)*strlen(str));
    strcpy(buff, str);

    if(strlen(buff) == 1){
        current->left = NULL;
        current->right = NULL;
        current->value = buff;
        return;
    }
    char *token;
    char *sep;
    sep = (char*)malloc(sizeof(char));
    *sep = *(buff+1);
    *(sep+1) = '\0';
    current->value = sep;
    token = strtok(buff, sep);
    char *firstHalf;
    firstHalf = token;
    char *secondHalf;
    while (token){
        secondHalf = token;
        token = strtok(NULL, "");
    }
    Tree *left = (Tree*) malloc(sizeof(Tree));
    Tree *right = (Tree*) malloc(sizeof(Tree));

    current->left = left;
    current->right = right;

    fill_operation_tree(firstHalf, current->left);
    fill_operation_tree(secondHalf, current->right);
}

Tree *generate_operation_tree(char *str){

    char *buff = (char*)malloc(sizeof(char)*strlen(str));
    strcpy(buff, str);

    char *token;
    token = strtok(buff, "c");
    char *firstHalf;
    char *secondHalf;
    firstHalf = token;
    int count = 0;
    while (token){
        secondHalf = token;
        count++;
        token = strtok(NULL, "");
    }

    Tree *result;
    result = (Tree*) malloc(sizeof(Tree));
    if(count == 1){
        if(*(buff+1) == 'e'){
            char *token;
            token = strtok(buff, "e");
            char *firstHalf;
            char *secondHalf;
            firstHalf = token;
            int count = 0;
            while (token){
                secondHalf = token;
                count++;
                token = strtok(NULL, "");
            }

            result->value = "e";
            result->left = (Tree*) malloc(sizeof(Tree));
            result->right = (Tree*) malloc(sizeof(Tree));
            fill_operation_tree(strrev(firstHalf), result->left);
            fill_operation_tree(strrev(secondHalf), result->right);
        } else{
            buff = strrev(buff);
            fill_operation_tree(buff, result);
        }
    } else{
        result->value = "c";
        result->left = (Tree*) malloc(sizeof(Tree));
        result->right = (Tree*) malloc(sizeof(Tree));
        fill_operation_tree(strrev(firstHalf), result->left);
        fill_operation_tree(strrev(secondHalf), result->right);
    }

    return result;
}

int contains_in_element(Element *current, char *target){
    while (current){
        if((char *) current->name == target){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int contains_in_set(Set *current, char *target){
    while (current){
        if(current->name == target){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int check_existing_operands(Element *listOfElements, Set *listOfSets, char *str){
    char * buff = (char*) malloc(sizeof(char) * strlen(str));
    strcpy(buff, str);

    for(int i=0; i<strlen(buff); i+=2){
        if(!(contains_in_element(listOfElements, (char *) *(buff + i)) || (contains_in_set(listOfSets,
                                                                                           (char *) *(buff + i))))){
            return 0;
        }
    }
    return 1;
}

Set * find_set(char * value, Set * listOfSets){
    Set *current = listOfSets;

    while(current){
        if(current->name == value){
            return current;
        }
        current = current->next;
    }
}

Set * set_union(Set *A, Set *B){
    Set *result = (Set*) malloc(sizeof(Set));
    result->head = A->head;
    result->name = NULL;
    result->next = NULL;
    Node *head = result->head;
    Node *current = B->head;

    while (result->head && result->head->next){
        result->head = result->head->next;
    }

    while(current){
        if(!exist_value(head, current->value)){
            result->head->next = malloc(sizeof(Node));
            result->head =result->head->next;
            result->head->value = current->value;
            result->head->next = NULL;

        }

        current = current->next;

    }
    result->head = head;

    return result;
}

Set * set_subtraction (Set *A, Set *B){
    Set * result = malloc(sizeof(Set));
    Node *current = A->head;
    result->head = NULL;
    result->name = NULL;
    result->next = NULL;
    Node *head = NULL;

    while(current){
        if(!exist_value(B->head, current->value)){
            if(!head){
                result->head = malloc(sizeof(Node));
                result->head->next = NULL;
                result->head->value = current->value;
                head = result->head;
                current = current->next;
                continue;
            }

            result->head->next = malloc(sizeof(Node));
            result->head = result->head->next;
            result->head->next = NULL;
            result->head->value = current->value;

        }

        current = current->next;
    }
    result->head = head;
    return result;
}

Set * set_intersection(Set *A, Set *B){
    Set * result = malloc(sizeof(Set));
    Node *current = B->head;
    result->head = NULL;
    result->name = NULL;
    result->next = NULL;
    Node *head = NULL;

    while(current){
        if(exist_value(A->head, current->value)){
            if(!head){
                result->head = malloc(sizeof(Node));
                result->head->next = NULL;
                result->head->value = current->value;
                head = result->head;
                current = current->next;
                continue;
            }

            result->head->next = malloc(sizeof(Node));
            result->head = result->head->next;
            result->head->next = NULL;
            result->head->value = current->value;

        }

        current = current->next;
    }
    result->head = head;
    return result;
}

int exist_value(Node *A, int value){
    Node *current = NULL;
    current = A;
    while(current){
        if(current->value == value){
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int belongs_to(Element *a, Set *A){
    if(exist_value(A->head, a->value)){
        return 1;
    }

    return 0;
}