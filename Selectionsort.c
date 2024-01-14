#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int main()
{
    const int size = 5; // Replace with your desired array size
    int array[size];

    // Input array elements
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }

    // Call selection_sort function
    selection_sort(array, size);

    // Display sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
