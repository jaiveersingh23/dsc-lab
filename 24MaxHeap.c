#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int key; 
} element;

element heap[MAX_HEAP_SIZE]; 
int n = 0; 

void insert_max_heap(element item, int n) {
    int i;
    if (n == MAX_HEAP_SIZE - 1) {
        fprintf(stderr, "the heap is full.\n");
        exit(1);
    }
    i = ++n; 
    while ((i != 1) && (item.key > heap[i / 2].key)) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

element delete_max_heap(int n) {
    int parent, child;
    element item, temp;
    if (n == 0) {
        fprintf(stderr, "The heap is empty\n");
        exit(1);
    }
    
    item = heap[1];
    
    temp = heap[n--];
    parent = 1;
    child = 2;
    while (child <= n) {
        
        if ((child < n) && (heap[child].key < heap[child + 1].key))
            child++;
        if (temp.key >= heap[child].key)
            break;
        
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

int main() {
    
    element item1 = {10}; 
    insert_max_heap(item1, n++);
    element item2 = {20};
    insert_max_heap(item2, n++);
    element item3 = {5};
    insert_max_heap(item3, n++);

    printf("Heap after insertion:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");

    printf("Deleting max element...\n");
    element max_item = delete_max_heap(n--);
    printf("Max element deleted: %d\n", max_item.key);

    printf("Heap after deletion:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");

    return 0;
}