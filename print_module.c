#include "print_module.h"

#include "polish_logic.h"

void graph_to_matrix(char notation[], int matrix[][WIDTH]) {
    double x = 0;
    for (int j = 0; j < WIDTH; ++j) {
        double y = calculate(notation, x);
        x += C_W;
        double cnt = -1;
        for (int i = 0; i < HEIGHT; ++i, cnt += C_H) {
            if (cnt <= y && y <= cnt + C_H)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}

void print_matrix(int matrix[][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (matrix[i][j] == 1)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}