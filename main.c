#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct ListOfSetHeads {
    char name;
    struct Node * head;
    struct ListOfSetHeads * next;
} ListOfSetHeads;

int main()
{
    char ch;
    FILE *fp;
    int comma = 0;

    fp = fopen("C:\\Users\\Lavinia\\Documents\\GitHub\\set-algebra\\set.txt", "r");

    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){



//        switch (ch){
//            case 65 ... 90:
//                if(ch == )
//                break;
//            case 97 ... 122:
//                //Lowercase
//                break;
//            default:
//                //error
//        }
    }

    fclose(fp);
    return 0;
}