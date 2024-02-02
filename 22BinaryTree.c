#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree_pointer;

typedef struct node {
    int data;
    tree_pointer left_child, right_child;
} Node;

void inorder(tree_pointer ptr) {
    if (ptr) {
        inorder(ptr->left_child);
        printf("%d ", ptr->data);
        inorder(ptr->right_child);
    }
}

void preorder(tree_pointer ptr) {
    if (ptr) {
        printf("%d ", ptr->data);
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

void postorder(tree_pointer ptr) {
    if (ptr) {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        printf("%d ", ptr->data);
    }
}

int main() {
    // Creating a sample binary tree
    tree_pointer root = (tree_pointer)malloc(sizeof(Node));
    root->data = 1;

    root->left_child = (tree_pointer)malloc(sizeof(Node));
    root->left_child->data = 2;
    root->left_child->left_child = NULL;
    root->left_child->right_child = NULL;

    root->right_child = (tree_pointer)malloc(sizeof(Node));
    root->right_child->data = 3;
    root->right_child->left_child = NULL;
    root->right_child->right_child = NULL;

    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    
    free(root->left_child);
    free(root->right_child);
    free(root);

    return 0;
}