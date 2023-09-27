#include "stack_functions.h"

int peek_char(stack_char *my_stack) {
    int operator= 0;
    if (my_stack->size <= 0)
        operator= 0;
    else
        operator= my_stack->data[my_stack->size - 1];
    return operator;
}

void push_char(stack_char *p, char value) {
    p->data[p->size] = value;
    p->size++;
}

void push_double(stack_double *p, double value) {
    p->data[p->size] = value;
    p->size++;
}

double pop_double(stack_double *p) {
    double operator= 0;
    if (p->size == 0)
        operator= 0;
    else {
        p->size--;
        operator= p->data[p->size];
    }
    return operator;
}

char pop_char(stack_char *p) {
    char operator= 0;
    if (p->size == 0)
        operator= 0;
    else {
        p->size--;
        operator= p->data[p->size];
    }
    return operator;
}