#include <stdio.h>
#include <stdlib.h>
 

struct node {

    int key;

    struct node *left, *right;
};
 


struct node* newNode(int item)
{

    struct node* temp

        = (struct node*)malloc(

            sizeof(struct node));

    temp->key = item;

    temp->left = temp->right = NULL;

    return temp;
}
 


struct node* insert(struct node* node, int key)
{

    

    if (node == NULL)

        return newNode(key);
 

    
    if (key < node->key) {

        node->left = insert(node->left, key);

    }

    else if (key > node->key) {

        node->right = insert(node->right, key);

    }
 

    

    return node;
}
 

void inorder(struct node* root)
{

    if (root != NULL) {

        inorder(root->left);

        printf("%d ", root->key);

        inorder(root->right);

    }
}
 

void preOrder(struct node* root)
{

    if (root != NULL) {

        printf("%d ", root->key);

        preOrder(root->left);

        preOrder(root->right);

    }
}

void postOrder(struct node* root)
{

    if (root != NULL) 

    {

        postOrder(root->left);

        postOrder(root->right);

        cout << " " << root->key;

    }
}
int main()
{

    

    struct node* root = NULL;
 

    

    root = insert(root, 50);
 

    
    insert(root, 30);
 

    

    insert(root, 20);
 

    
    insert(root, 40);
 

    

    insert(root, 70);
 

    

    insert(root, 60);
 

    

    insert(root, 80);
 

    
    printf("\nInorder:");
    inorder(root);
 printf("\PreOrder:");
    preOrder(root);

 printf("\PostOrder:");   
 postOrder(root);
 printf("\n");
    return 0;
}