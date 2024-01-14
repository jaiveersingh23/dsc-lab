#include <stdio.h>

#define MAX_TERMS 101

typedef struct {
    int col;
    int row;
    int value;
} term;

term a[MAX_TERMS];
term b[MAX_TERMS];

void transpose(term a[], term b[]) {
    int n, i, j, currentb;

    n = a[0].value;

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = n;

    if (n > 0) {
        currentb = 1;

        for (i = 0; i < a[0].col; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of rows in the sparse matrix: ");
    scanf("%d", &a[0].row);

    printf("Enter the number of columns in the sparse matrix: ");
    scanf("%d", &a[0].col);

    printf("Enter the number of non-zero elements in the sparse matrix: ");
    scanf("%d", &a[0].value);

    printf("Enter the elements in the format (row col value):\n");
    for (int i = 1; i <= a[0].value; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    
    transpose(a, b);

    
    printf("Transposed matrix:\n");
    for (int i = 0; i <= b[0].value; i++) {
        printf("(%d, %d, %d)\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;
}
