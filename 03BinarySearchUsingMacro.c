#include <stdio.h>

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

int binary_search(int list[], int lo, int hi, int key)
{
    int mid;
    if (lo > hi)
    {
        printf("Key not found\n");
        return -1; // or any other appropriate value indicating not found
    }
    mid = (lo + hi) / 2;
    switch (COMPARE(list[mid], key))
    {
    case 0:
        printf("Key found at index %d\n", mid);
        return mid;
    case 1: // (list[mid] > key)
        return binary_search(list, lo, mid - 1, key);
    case -1: // (list[mid] < key)
        return binary_search(list, mid + 1, hi, key);
    }
}

int main()
{
    const int size = 5; // Replace with your desired array size
    int array[size];

    // Input sorted array elements
    printf("Enter %d sorted elements: ", size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    // Call binary_search function
    int result = binary_search(array, 0, size - 1, key);

    if (result == -1)
    {
        printf("Key not found\n");
    }

    return 0;
}
