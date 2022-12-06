#include <stdio.h>
#include "stdbool.h"
#include "my_mat.h"

#define mat_size 10

int value_of_matrix(int input_matrix[mat_size][mat_size]) {

    printf("please enter %d numbers to the matrix: \n", mat_size*mat_size);
    for (int i = 0; i < mat_size; ++i) {
        for (int j = 0; j < mat_size; ++j) {
            scanf(" %d", &input_matrix[i][j]);
        }
    }
    return 0;
}

int isPath(int input_matrix[mat_size][mat_size], int i, int j) {
    bool Is_Path = true;
    shortest_path(input_matrix, i, j, Is_Path);

    return 0;
}

int shortest_path(int input_matrix[mat_size][mat_size], int i, int j, bool is_path) {

    printf("please enter vertices: \n");
    scanf(" %d%d", &i, &j);

    int solution_matrix[mat_size][mat_size] = {0};

    // copy from input matrix to solution matrix:
    for (int a=0; a<mat_size; a++) {
        for (int b = 0; b < mat_size; b++) {
            solution_matrix[a][b] = input_matrix[a][b];
        }
    }

    for (int k = 0; k < mat_size; k++) {
        for (int l = 0; l < mat_size; l++) {
            for (int m = 0; m < mat_size; m++) {
                if ((l != m) && (k != m) && (k != l)) {
                    if ((solution_matrix[l][m] == 0) && (solution_matrix[l][k] != 0) && (solution_matrix[k][m] != 0)) {
                        solution_matrix[l][m] = solution_matrix[l][k] + solution_matrix[k][m];
                    }
                    else if ((solution_matrix[l][m] != 0) && (solution_matrix[l][k] != 0)
                    && (solution_matrix[k][m] != 0) &&  ((solution_matrix[l][k] + solution_matrix[k][m]) < solution_matrix[l][m])) {
                        solution_matrix[l][m] = solution_matrix[l][k] + solution_matrix[k][m];
                    }
                }
            }
        }
    }
    if (is_path) {
        printf("%s", (solution_matrix[i][j] != 0) ? "True\n" : "False\n");
    }
    else {
        printf("the shortest path between %d and %d is: %d \n", i, j, (solution_matrix[i][j] != 0) ? solution_matrix[i][j] : -1);
    }

   return 0;
}