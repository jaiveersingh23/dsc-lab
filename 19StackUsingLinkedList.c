#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Stack {
    Node* top;
} Stack;
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}
void push(Stack* stack, int data) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("%d pushed to the stack\n", data);
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;

    free(temp);

    return data;
}

void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    displayStack(&stack);

    printf("Popped element: %d\n", pop(&stack));

    displayStack(&stack);

    freeStack(&stack);

    return 0;
}
