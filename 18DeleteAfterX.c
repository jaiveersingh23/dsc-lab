#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *link;
} listnode;

typedef listnode *lp;

void deleteAfter(lp *f, int position) {
    lp temp, after;
    int count = 1;

    if (*f == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = *f;

        // Traverse to the specified position
        while (temp != NULL && count < position) {
            temp = temp->link;
            count++;
        }

        // Check if the specified position is valid
        if (temp == NULL || temp->link == NULL) {
            printf("\nInvalid position or no node after the specified position\n");
        } else {
            after = temp->link;
            temp->link = after->link;
            free(after);
            printf("\nNode deleted after position %d\n", position);
        }
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
    lp third = (lp)malloc(sizeof(listnode));

    third->link = NULL;
    third->data = 30;
    second->data = 20;
    second->link = third;
    first->data = 10;
    first->link = second;

    deleteAfter(&first, 1); // Delete after position 1
    printlist(first);

    return 0;
}
