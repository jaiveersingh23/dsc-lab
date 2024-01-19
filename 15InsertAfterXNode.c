#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *link;
} listnode;

typedef listnode *lp;

void insertend(lp *first,lp x) {
    lp temp;
    temp = (lp)malloc(sizeof(listnode));
    temp->data = 50;

    if (*first) {
        temp->link=x->link;
        x->link=temp;
        }
     else {
        temp->link = NULL;
        *first = temp;
    }
}

void printlist(lp f) {
    printf("The list contains: ");
    for (; f; f = f->link) {
        printf("%d ", f->data);
    }
    printf("\n");
}

int main() {
    lp first = (lp)malloc(sizeof(listnode));
    lp second = (lp)malloc(sizeof(listnode));

    second->link = NULL;
    second->data = 20;
    first->data = 10;
    first->link = second;

    insertend(&first,first);
    printlist(first);

    free(first);
    free(second);

    return 0;
}
