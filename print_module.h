#ifndef PRINT_MODULE_H
#define PRINT_MODULE_H

#define HEIGHT 25
#define WIDTH 80
#define C_W M_PI_4 / 5
#define C_H 0.083333333333

#include <math.h>
#include <stdio.h>

void print_matrix(int matrix[][WIDTH]);
void graph_to_matrix(char notation[], int matrix[][WIDTH]);

#endif