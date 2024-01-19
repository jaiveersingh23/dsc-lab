#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *link;
} listnode;

typedef listnode *lp;

void deletefront(lp *f) {
    lp ptr;
    if (*f == NULL) {
        printf("\nList is empty\n");
    } else {
        ptr = *f;
        *f = (*f)->link;
        free(ptr);
        printf("\nNode deleted from the beginning...\n");
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

    deletefront(&first);
    printlist(first);

    return 0;
}
