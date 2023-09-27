#include "polish_logic.h"

#include "stack_functions.h"
#include "string_management.h"

double apply_unar(double x, char oper) {
    double res = 0;
    switch (oper) {
        case 'i': {
            res = sin(x);
            break;
        }
        case 'o': {
            res = cos(x);
            break;
        }
        case 'a': {
            res = tan(x);
            break;
        }
        case 't': {
            res = 1 / tan(x);
            break;
        }
        case 'n': {
            res = log(x);
            break;
        }
        case 'q': {
            res = sqrt(x);
            break;
        }
    }
    return res;
}

double apply_double(double x, double y, char oper) {
    double res = 0;
    switch (oper) {
        case '+': {
            res = x + y;
            break;
        }
        case '-': {
            res = y - x;
            break;
        }
        case '*': {
            res = x * y;
            break;
        }
        case '/': {
            res = y / x;
            break;
        }
    }
    return res;
}

double calculate(char str[], double x) {
    stack_double new_stack;
    char *operands = "0123456789xP";
    char *unar = "ioatqn";
    new_stack.size = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_mas(str[i], operands) != -1) {
            if (str[i] == 'x')
                push_double(&new_stack, x);
            else if (str[i] == 'P')
                push_double(&new_stack, M_PI);
            else
                push_double(&new_stack, (double)(str[i] - '0'));
        } else if (is_in_mas(str[i], unar) != -1) {
            double value = pop_double(&new_stack);
            value = apply_unar(value, str[i]);
            push_double(&new_stack, value);
        } else {
            double first = pop_double(&new_stack);
            double second = pop_double(&new_stack);
            double value = apply_double(first, second, str[i]);
            push_double(&new_stack, value);
        }
    }
    return new_stack.data[0];
}

int priority(char sym) {
    int prior = 0;
    if (sym == ')' || sym == '(')
        prior = 1;
    else if (sym == '+' || sym == '-')
        prior = 2;
    else if (sym == '*' || sym == '/')
        prior = 3;
    else if (sym == 'i' || sym == 'o' || sym == 'a' || sym == 't' || sym == 'n' || sym == 'q')
        prior = 4;
    return prior;
}

void to_polish_notation(char str[], char polish_result[]) {
    char *unar = "ioatqn";
    char *operands = "0123456789xP";
    stack_char my_stack;
    my_stack.size = 0;
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_mas(str[i], operands) != -1) {
            polish_result[len++] = str[i];
        } else if (is_in_mas(str[i], unar) != -1) {
            push_char(&my_stack, str[i]);
        } else {
            if (my_stack.size == 0) {
                push_char(&my_stack, str[i]);
            } else if (priority(str[i]) <= priority(peek_char(&my_stack)) && str[i] != '(' && str[i] != ')') {
                while (priority(str[i]) <= priority(peek_char(&my_stack))) {
                    polish_result[len++] = pop_char(&my_stack);
                }
                push_char(&my_stack, str[i]);
            } else if (str[i] == '(') {
                push_char(&my_stack, str[i]);
            } else if (str[i] == ')') {
                while (peek_char(&my_stack) != '(') polish_result[len++] = pop_char(&my_stack);
                pop_char(&my_stack);
            } else
                push_char(&my_stack, str[i]);
        }
    }
    while (my_stack.size != 0) polish_result[len++] = pop_char(&my_stack);
    polish_result[len] = '\0';
}