#include "my_mat.h"
#include "stdbool.h"
#include <stdio.h>
#define mat_size 10

int main() {

    int input_matrix[mat_size][mat_size];
    int i = 0, j = 0;
    bool FLAG = true, is_path = false;
    char choice;


    while (FLAG) {
        printf("Please enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                value_of_matrix(input_matrix);
                continue;
            case 'B':
                isPath(input_matrix, i, j);
                continue;
            case 'C':
                shortest_path(input_matrix, i, j, is_path);
                continue;
            case 'D':
                FLAG = false;
        }
    }

    return 0;

    }