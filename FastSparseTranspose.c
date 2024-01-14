#include <stdio.h>
#include <stdio.h>

#define MAX_TERMS 101

typedef struct {
    int col;
    int row;
    int value;
} term;
void transpose(term a[], term b[]) {
    int row_tern[MAX_TERMS], starting_pos[MAX_TERMS];
    int i, j, nun_cols = a[0].col, nun_terns = a[0].value;

    b[0].row = nun_cols;
    b[0].col = a[0].row;
    b[0].value = nun_terns;

    if (nun_terns > 0) {
        for (i = 0; i < nun_terns; i++)
            row_tern[i] = 0;

        for (i = 1; i <= nun_terns; i++)
            row_tern[a[i].col]++;

        starting_pos[0] = 1;
for (i = 1; i < nun_cols; i++)
            starting_pos[i] = starting_pos[i - 1] + row_tern[i - 1];

        for (i = 1; i <= nun_terns; i++) {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
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
