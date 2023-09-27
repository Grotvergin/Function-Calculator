#ifndef LOGIC_H
#define LOGIC_H

#include <math.h>

double apply_unar(double x, char oper);
double apply_double(double x, double y, char oper);
double calculate(char str[], double x);
int priority(char sym);
void to_polish_notation(char str[], char polish_result[]);

#endif