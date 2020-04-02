//
// Created by Lavinia on 3/28/2020.
//

#include "operations.h"
#include "set.h"

void fill_operation_tree(char *str, Tree *current) {

    char *buff = (char *) malloc(sizeof(char) * (int)(strlen(str) +1) );
    strcpy(buff, str);

    if (strlen(buff) == 1) {
        current->left = NULL;
        current->right = NULL;
        current->value = buff;
        return;
    }

    char * firstHalf = buff;
    char * secondHalf;

    char *operand = (char*) malloc(sizeof(char));
    strcpy(operand, strpbrk(buff, OPERANDS));
    *(operand+1) = '\0';
    current->value = operand;
    current->left = (Tree *) malloc(sizeof(Tree));
    current->right = (Tree *) malloc(sizeof(Tree));
    secondHalf = strchr(buff, *operand);
    *secondHalf = '\0';
    secondHalf = secondHalf+1;
    fill_operation_tree(firstHalf, current->left);
    fill_operation_tree(secondHalf, current->right);

}

Tree *generate_operation_tree(char *str) {

    char *buff = (char *) malloc(sizeof(char) * (int) (strlen(str)+1));
    strcpy(buff, str);
    buff = strrev(buff);

    Tree *current;
    Tree *result = (Tree*) malloc(sizeof(Tree));
    result->left = NULL;
    result->right = NULL;

    char * firstHalf = buff;
    char * secondHalf;

    if(strpbrk(buff, "[]()")){
        char *operand = (char*) malloc(sizeof(char));
        strcpy(operand, strpbrk(buff, "[]()"));
        *(operand+1) = '\0';
        result->value = operand;
        result->left = (Tree *) malloc(sizeof(Tree));
        result->right = (Tree *) malloc(sizeof(Tree));
        secondHalf = strchr(buff, *operand);
        *secondHalf = '\0';
        secondHalf = secondHalf+1;
        fill_operation_tree(strrev(firstHalf), result->left);
        fill_operation_tree(strrev(secondHalf), result->right);
    }else if (strpbrk(buff, "<>")){
        char *operand = (char*) malloc(sizeof(char));
        strcpy(operand, strpbrk(buff, "<>"));
        *(operand+1) = '\0';
        result->value = operand;
        result->left = (Tree *) malloc(sizeof(Tree));
        result->right = (Tree *) malloc(sizeof(Tree));
        secondHalf = strchr(buff, *operand);
        *secondHalf = '\0';
        secondHalf = secondHalf+1;
        fill_operation_tree(strrev(firstHalf), result->left);
        fill_operation_tree(strrev(secondHalf), result->right);
    }else if (strpbrk(buff, "x")){
        secondHalf = strchr(buff, 'x');
        firstHalf = buff;
        current = result;
        while(strchr(firstHalf, 'x')){
            *secondHalf = '\0';
            secondHalf = secondHalf+ 1;
            current->value = "x";
            current->left = (Tree *) malloc(sizeof(Tree));
            current->right = (Tree *) malloc(sizeof(Tree));
            fill_operation_tree(firstHalf, current->right);
            current = current->left;
            firstHalf = secondHalf;
            secondHalf = strchr(secondHalf, 'x');
        }
        fill_operation_tree(firstHalf, current);
    }else{
        fill_operation_tree(buff, result);
    }

    return result;
}

Set *unite(Set *A, Set *B) {
    Set *result = (Set *) malloc(sizeof(Set));
    result->head = A->head;
    result->next = NULL;
    result->next = NULL;
    Node *head = result->head;
    Node *current = B->head;

    while (result->head && result->head->next) {
        result->head = result->head->next;
    }

    while (current) {
        if (!belongs_to(current->value, head)) {
            result->head->next = malloc(sizeof(Node));
            result->head = result->head->next;
            result->head->value = current->value;
            result->head->next = NULL;
        }

        current = current->next;

    }
    result->head = head;

    return result;
}

Set *subtract(Set *A, Set *B) {
    Set *result = malloc(sizeof(Set));
    Node *current = A->head;
    result->head = NULL;
    result->next = NULL;
    Node *head = NULL;

    while (current) {
        if (!belongs_to(current->value, B->head)) {
            if (!head) {
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

Set *intersect(Set *A, Set *B) {
    Set *result = malloc(sizeof(Set));
    Node *current = B->head;
    result->head = NULL;
    result->next = NULL;
    Node *head = NULL;

    while (current) {
        if (belongs_to(current->value, A->head)) {
            if (!head) {
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

int belongs_to(int value, Node *A) {
    if(!A){
        return 0;
    }

    Node *current = NULL;
    current = A;
    while (current) {
        if (current->value == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int is_proper_subset(Set *A, Set *B) {
    //A is not equal to B
    Node *current = A->head;
    Node *aux = B->head;

    while (current) {
        if (!belongs_to(current->value, B->head)) {
            return 0;
        }
        current = current->next;
        aux = aux->next;
    }

    if (!current && !aux) {
        return 0;
    }

    return 1;
}

int is_subset(Set *A, Set *B) {
    //A is a subset of B. set A is included in set B. A can be equal to B
    Node *current = A->head;

    while (current) {
        if (!belongs_to(current->value, B->head)) {
            return 0;
        }
        current = current->next;
    }

    return 1;
}

Line *do_couple(char *x, char *y) {
    Line *couple =  (Line*) malloc(sizeof(Line));
    couple->next = NULL;
    couple->value = (char*) malloc(sizeof(char)*(strlen(x)+strlen(y)+4));
    sprintf(couple->value, "<%s,%s>", x, y);
    couple->next = NULL;
    return couple;
}

Line *set_to_line(Set *A) {
    Node *currentNode = A->head;
    Line *head = (Line *) malloc(sizeof(Line));
    head->next = NULL;
    head->next = NULL;
    Line *currentLine = head;
    while (currentNode) {
        currentLine->value = (char*) malloc(sizeof(char));
        sprintf(currentLine->value, "%d", currentNode->value);
        if (!currentNode->next) {
            break;
        }
        currentNode = currentNode->next;
        currentLine->next = (Line *) malloc(sizeof(Line));
        currentLine = currentLine->next;
        currentLine->next = NULL;
    }

    return head;
}

char * solve_operation_tree(Tree *tree){
    if(strcmp(tree->value, "+") == 0){
        return set_to_string(unite(find_set_in_tree(tree->right), find_set_in_tree(tree->left)));
    }

    if(strcmp(tree->value, "*") == 0){
        return set_to_string(intersect(find_set_in_tree(tree->right), find_set_in_tree(tree->left)));
    }

    if(strcmp(tree->value, "-") == 0){
        return set_to_string(subtract(find_set_in_tree(tree->right), find_set_in_tree(tree->left)));
    }

    if(strcmp(tree->value, "<") == 0){
        if(belongs_to(find_element_in_tree(tree->right), find_set_in_tree(tree->left)->head)){
            return "true";
        }

        return "false";
    }

    if(strcmp(tree->value, ">") == 0){
        if(!belongs_to(find_element_in_tree(tree->right), find_set_in_tree(tree->left)->head)){
            return "true";
        }
        return "false";
    }

    if(strcmp(tree->value, "[") == 0){
        if(is_proper_subset(find_set_in_tree(tree->right), find_set_in_tree(tree->left))){
            return "true";
        }
        return "false";
    }

    if(strcmp(tree->value, "]") == 0){
        if(!is_proper_subset(find_set_in_tree(tree->right), find_set_in_tree(tree->left))){
            return "true";
        }

        return "false";
    }

    if(strcmp(tree->value, "(") == 0){
        if(is_subset(find_set_in_tree(tree->right), find_set_in_tree(tree->left))){
            return "true";
        }

        return "false";
    }

    if(strcmp(tree->value, ")") == 0){
        if(!is_subset(find_set_in_tree(tree->right), find_set_in_tree(tree->left))){
            return "true";
        }

        return "false";
    }

    if(strcmp(tree->value, "x") == 0) {
        return cartesian_to_string(solve_cartesian_operation_tree(tree));
    }

    if(find_set_in_tree(tree)){
        return set_to_string(find_set_in_tree(tree));
    }

    return NULL;
}

Line *solve_cartesian_operation_tree(Tree *tree){
    if(strcmp(tree->left->value, "x") != 0){
        return do_cartesian_product(set_to_line(find_set_in_tree(tree->left)), set_to_line(find_set_in_tree(tree->right)));
    }
    return do_cartesian_product(solve_cartesian_operation_tree(tree->left), set_to_line(find_set_in_tree(tree->right)));
}

Line *do_cartesian_product(Line *A, Line *B) {
    Line *currentA = A;
    Line *currentB = B;
    Line *result = (Line *) malloc(sizeof(Line));
    result->next = NULL;
    Line *head = result;

    while (currentA) {
        currentB = B;
        while (currentB) {
            result->value = do_couple(currentA->value, currentB->value)->value;
            if (!currentB->next) {
                break;
            }
            result->next = (Line *) malloc(sizeof(Line));
            result = result->next;
            currentB = currentB->next;
        }
        if(!currentA->next){
            result->next = NULL;
            break;
        }
        result->next = (Line *) malloc(sizeof(Line));
        result = result->next;
        result->next = NULL;
        currentA = currentA->next;
    }

    return head;
}

int find_element_in_tree(Tree *tree){
    Element *current = listOfElements;

    while (current) {
        if (strchr(tree->value, current->name)){
            return current->value;
        }
        current = current->next;
    }
}

Set *find_set_in_tree(Tree *tree) {
    Set *current = copy_of_set(listOfSets);

    if(strcmp(tree->value, "+") == 0){
        return unite(find_set_in_tree(tree->left), find_set_in_tree(tree->right));
    }

    if(strcmp(tree->value, "*") == 0){
        return intersect(find_set_in_tree(tree->left), find_set_in_tree(tree->right));
    }

    if(strcmp(tree->value, "-") == 0){
        return subtract(find_set_in_tree(tree->left), find_set_in_tree(tree->right));
    }

    while (current) {
        if (strchr(tree->value, current->name)){
            current->next = NULL;
            return current;
        }
        current = current->next;
    }
}

char * set_to_string(Set *A){
    if(!A->head){
        return "{ }";
    }
    Node *current = A->head;
    char * result = (char*) malloc(sizeof(char));
    strcpy(result, "{");
    char * str = (char*) malloc(sizeof(char));
    while(current){
        sprintf(str, "%d, ", current->value);
        strcat(result, str);
        current = current->next;
    }
    strcpy((result+strlen(result)-2), "}\0");
    return result;
}

char * cartesian_to_string(Line *A){
    Line *current = A;
    char * result = (char*) malloc(sizeof(char) + 2) ;
    strcpy(result, "{");
    while(current){
        result = realloc(result, sizeof(char) * ((int)strlen(result) + (int)strlen(current->value) + 3 ));
        strcat(result, current->value);
        strcat(result, ", ");
        current = current->next;
    }
    strcpy((result+(int)strlen(result)-2), "}\0");
    return result;
}

Set * undo_cartesian_product(char* cartesian){
    int countSets = 0;
    int i, j;
    Set *head = NULL;
    head = (Set*) malloc(sizeof(Set));

    Set *currentSet = head;
    head->next = NULL;
    while(!(*cartesian > '0' && *cartesian < '9')){
        countSets++;
        cartesian = cartesian + 1;
    }
    Line *numbers = get_numbers(cartesian);
    Line *currentNumbers = numbers;
    currentNumbers = numbers;
    Node * currentNode;
    j=0;
    while (j<countSets){
        currentSet->head = (Node*) malloc(sizeof(Node));
        currentNode = currentSet->head;
        currentSet->head->value = (int) NULL;
        while (numbers){
            if(!currentNode->value){
                currentNode->value = (int) strtol(numbers->value, NULL, 10 );
                currentNode->next = NULL;
            }else if(!belongs_to((int) strtol(numbers->value, NULL, 10 ), currentSet->head)){
                currentNode->next = (Node*) malloc(sizeof(Node));
                currentNode = currentNode->next;
                currentNode->next = NULL;
                currentNode->value = (int) strtol(numbers->value, NULL, 10 );
            }

            i=0;
            while(i<countSets){
                if(!numbers) {
                    break;
                }
                numbers = numbers->next;
                i++;
            }
        }
        j++;

        if(j == countSets){
            break;
        }
        currentNode = (Node*) malloc(sizeof(Node));
        currentNode->next = NULL;
        currentSet->next = (Set*) malloc(sizeof(Set));
        currentSet = currentSet->next;
        currentSet->next = NULL;
        currentNumbers = currentNumbers->next;
        numbers = currentNumbers;
    }

    return head;

}

Set* powerset(Set* head){
    Node* current = head->head;
    Set* powerset = (Set*)calloc(1, sizeof(Set));

    while (current){
        fill_powerset(powerset, current->value);
        current = current->next;
    }

    return powerset;
}

void fill_powerset(Set* list, int element){
    Set* current = list;
    Set* head = NULL;
    Set* control = (Set*) calloc(1, sizeof(Set));

    while (current){
        Set* tail = (Set*) calloc(1, sizeof(Set));

        if(!head){
            head = tail;
        }

        tail->head = (Node*)calloc(1,sizeof(Node));
        tail->head->value = element;
        tail->head->next = current->head;
        control->next = tail;
        control = control->next;

        if(!current->next){
            current->next = head;
            break;
        }

        current = current->next;
    }
}

char * powerset_to_string(Set *A){
    Set * current = A;
    char * result = (char*) calloc(2, sizeof(char));
    strcpy(result, "{");
    while(current){
        result = realloc(result, sizeof(char) * ((int)strlen(result) + (int)strlen(set_to_string(current)) + 3 ));
        strcat(result, set_to_string(current));
        strcat(result, ", ");
        current = current->next;
    }
    strcpy((result+(int)strlen(result)-2), "}\0");

    return result;
};

Set * undo_powerset(char* A){
    Set * result = (Set*) calloc(1, sizeof(Set));
    Node *elements=  (Node*) calloc(1, sizeof(Node));
    Line * numbers = get_numbers(strrev(A));
    result->head = elements;

    while(!belongs_to((int) strtol(numbers->value, NULL, 10),result->head)){
        elements->value = (int) strtol(numbers->value, NULL, 10);

        if(belongs_to((int) strtol(numbers->next->value, NULL, 10),result->head)){
            break;
        }
        elements->next = (Node*) calloc(1, sizeof(Node));
        elements = elements->next;
        numbers = numbers->next;

    }

    return  result;

}

Set * string_to_set(char * str){
    Set * result = (Set*) calloc(1, sizeof(Set));
    Line * elements = get_numbers(str);
    result->head = (Node*) calloc(1, sizeof(Node));
    Node *current = result->head;

    while(elements){
        current->value = (int)strtol(elements->value, NULL, 10);
        if(!elements->next){
            break;
        }
        current->next = (Node*) calloc(1, sizeof(Node));
        current = current->next;
        elements = elements->next;
    }

    return result;

}

