#ifndef STRING_MANAGEMENT_H
#define STRING_MANAGEMENT_H

#define LEN 100

#include <stdio.h>
#include <string.h>

void add_zero_before_minus(char str[]);
void format_string(char str[]);
void change_substring(char str[], char sub[], char replace[]);
void cut_string(char str[], char sym);
char *gets_own(char *s);
int is_in_mas(char sym, char mas[]);
int input(char str[]);

#endif