#ifndef STACK_H
#define STACK_H

#define LEN 100

typedef struct stack_char {
    char data[LEN];
    int size;
} stack_char;

typedef struct stack_double {
    double data[LEN];
    int size;
} stack_double;

int peek_char(stack_char *my_stack);
void push_char(stack_char *p, char value);
void push_double(stack_double *p, double value);
double pop_double(stack_double *p);
char pop_char(stack_char *p);

#endif