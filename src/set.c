//
// Created by Lavinia on 3/23/2020.
//

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
            head = (Node *) calloc(1, sizeof(Node));
            current->next = head;
        }

        current->value = (int) strtol(charNumber->value, NULL, 10);
        process_nodes(current->next, charNumber->next);
    }
}

Set *create_list_set(Set *head, Line *input) {

    if (input->value[0] >= 'A' && input->value[0] <= 'Z') {
        head = (Set *) malloc(sizeof(Set));
        head->name = input->value[0];
        head->next = NULL;
        head->head = NULL;
        populate(head, get_numbers(input->value));

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
        Line * aux = get_numbers(input->value);
        head->value = (int) strtol(aux->value, NULL, 10);
        head->next = NULL;
        if(input->next != NULL) {
            head->next = create_list_element(head->next, input->next);
        }
    }else if (input->next != NULL){
        head = create_list_element(head, input->next);
    }
    return head;
}

Set * copy_of_set(Set * A){
    Set * current = A;
    Set * copy = (Set*) calloc(1, sizeof(Set));
    Set * head = copy;
    while(current){
        copy->name = current->name;
        copy->head = copy_of_node(current->head);

        if(!current->next){
            break;
        }
        copy->next = (Set*) calloc(1, sizeof(Set));
        copy = copy->next;
        current = current->next;
    }

    return head;
}

Node * copy_of_node(Node *A){
    Node * current = A;
    Node *copy = (Node*) calloc(1, sizeof(Node));
    Node * head = copy;
    while(current){
        copy->value = current->value;

        if(!current->next){
            break;
        }
        copy->next = (Node*) calloc(1, sizeof(Node));
        copy = copy->next;
        current = current->next;
    }

    return head;
}