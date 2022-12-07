#include <stdio.h>
#include "my_mat.h"


void value_of_matrix(int input_matrix[MAT_SIZE][MAT_SIZE]) {

// With this 'for' loops we can go to every component in the matrix and give it a value from user
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            scanf(" %d", &input_matrix[i][j]);
        }
    }
}

void isPath(int input_matrix[MAT_SIZE][MAT_SIZE], int i, int j) {
    bool Is_Path = true;
    // There is a condition in shortest_path func that depend in the boolean variant is_path:
    // if true, the func will print only what rellevant to isPath func 
    shortest_path(input_matrix, i, j, Is_Path);

}

void shortest_path(int input_matrix[MAT_SIZE][MAT_SIZE], int i, int j, bool is_path) {

    scanf(" %d%d", &i, &j);

    int solution_matrix[MAT_SIZE][MAT_SIZE] = {0};

    // Copy from input matrix to solution matrix:
    for (int a=0; a<MAT_SIZE; a++) {
        for (int b = 0; b < MAT_SIZE; b++) {
            solution_matrix[a][b] = input_matrix[a][b];
        }
    }
    
    // Using Floyd–Warshall algorithm.
    // In addition, we add conditions to prevent calculate non-exist edges
    for (int k = 0; k < MAT_SIZE; k++) {
        for (int l = 0; l < MAT_SIZE; l++) {
            for (int m = 0; m < MAT_SIZE; m++) {
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
    // Condition that depend in the boolean variant is_path (parameter that got from the caller):
    // If true, the func will print only what rellevant to isPath func.
    // If false, the func will print only what rellevant to shortest_path func.
    if (is_path) {
        printf("%s", (solution_matrix[i][j] != 0) ? "True\n" : "False\n");
    }
    else {
        printf("%d\n",(solution_matrix[i][j] != 0) ? solution_matrix[i][j] : -1);
    }

}