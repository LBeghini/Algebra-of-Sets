//
// Created by Lavinia on 3/23/2020.
//

#include "set.h"

#include "set.h"


void populate(Set *empty, Line *charNumbers) {
    if (charNumbers) {
        empty->head = (Node *) malloc(sizeof(Node));
        process_nodes(empty->head, charNumbers);
    }
}

void process_nodes(Node *current, Line *charNumber) {
    if (charNumber) {
        current->next = NULL;
        if (charNumber->next) {
            Node *head;
            head = (Node *) malloc(sizeof(Node));
            head->next = NULL;
            head->value = NULL;
            current->next = head;
        }

        current->value = (int) strtol(charNumber->value, NULL, 10);
        process_nodes(current->next, charNumber->next);
    }
    return;
}

Line *get_chars_numbers(char *charNumbers) {
    char *current;
    current = (char *) malloc(sizeof(char) * strlen(charNumbers));
    strncpy(current, charNumbers + 3, strlen(charNumbers));
    current[strlen(current) - 1] = '\0';
    Line *result = split(current, ",");
    return result;
}

Set *create_list_set(Set *head, Line *input) {

    if (input->value[0] >= 'A' && input->value[0] <= 'Z') {
        head = (Set *) malloc(sizeof(Set));
        head->name = input->value[0];
        head->next = NULL;
        head->head = NULL;
        populate(head, get_chars_numbers(input->value));

        if (input->next != NULL) {
            head->next = create_list_set(head->next, input->next);
        }
    } else if (input->next != NULL) {
        head = create_list_set(head, input->next);
    }
    return head;
}

Element *create_list_element(Element *head, Line *input){
    if (input->value[0] >= 'a' && input->value[0] <= 'z') {
        head = (Element*)malloc(sizeof(Element));
        head->name = input->value[0];
        //head->value = Element;

        head->next = NULL;
        if(input->next != NULL) {
            head->next = create_list_element(head->next, input->next);
        }
    }else if (input->next != NULL){
        head = create_list_element(head, input->next);
    }
    return head;
}