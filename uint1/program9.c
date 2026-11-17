#include <stdio.h>
#define ROWS 2
#define COLS 3

int main() {

    int matrixA[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int matrixB[ROWS][COLS] = {
        {7, 8, 9},
        {10, 11, 12}
    };


    int sum[ROWS][COLS];


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }


    printf("Resulting Sum Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }


}

