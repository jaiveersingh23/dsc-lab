#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *link;
} listnode;

typedef listnode *lp;

void deleteend(lp *f) {
    lp temp, prev;
    if (*f == NULL) {
        printf("\nList is empty\n");
    } else if ((*f)->link == NULL) {
        free(*f);
        *f = NULL;
        printf("\nNode deleted from the end...\n");
    } else {
        temp = *f;
        prev = NULL;
        while (temp->link != NULL) {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
        printf("\nNode deleted from the end...\n");
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

    deleteend(&first);
    printlist(first);

    return 0;
}
