#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *link;
} listnode;

typedef listnode* lp;

int main() {
    // Creating a two-node list lp first and second;
    lp first = (lp)malloc(sizeof(listnode));
    lp second = (lp)malloc(sizeof(listnode));

    second->link = NULL;
    second->data = 20;
    first->data = 10;

    first->link = second;

    printf("%d %d", first->data, second->data);

    free(first);
    free(second);

    return 0;
}
