#include <stdio.h>

#define MAX_TERMS 101

typedef struct {
    int col;
    int row;
    int value;
} term;

void transpose(term a[], term b[]) {
    int row_term[MAX_TERMS], starting_pos[MAX_TERMS];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;

    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if (num_terms > 0) {
        for (i = 0; i < num_terms; i++)
            row_term[i] = 0;

        for (i = 1; i <= num_terms; i++)
            row_term[a[i].col]++;

        starting_pos[0] = 1;
        for (i = 1; i < num_cols; i++)
            starting_pos[i] = starting_pos[i - 1] + row_term[i - 1];

        for (i = 1; i <= num_terms; i++) {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main() {
    term a[MAX_TERMS], b[MAX_TERMS];

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