#include "string_management.h"

int is_in_mas(char sym, char mas[]) {
    int i = 0;
    for (; mas[i] != '\0' && sym != mas[i]; ++i)
        ;
    if (i == (int)strlen(mas)) i = -1;
    return i;
}

int input(char str[]) {
    gets_own(str);
    int flag = 1, cnt_opening = 0, cnt_closing = 0;
    char *appropriate_sym = "x+-*/0123456789P";
    if ((int)strlen(str) < 1 || (int)strlen(str) > LEN - 1) flag = 0;
    for (int i = 0; str[i] != '\0';) {
        if (str[i] == '(') {
            i++;
            cnt_opening++;
            if (str[i] == '\0' || str[i] == ')') flag = 0;
        } else if (str[i] == ')') {
            i++;
            cnt_closing++;
        } else if (is_in_mas(str[i], appropriate_sym) == -1) {
            flag = 0;
            int k = 0;
            char sub[5];
            while (str[i] != '(' && str[i] != '\0') sub[k++] = str[i++];
            sub[k] = '\0';
            if (k == 2 && !strcmp(sub, "ln"))
                flag = 1;
            else if (k == 4 && !strcmp(sub, "sqrt"))
                flag = 1;
            else if (k == 3 && (!strcmp(sub, "sin") || !strcmp(sub, "cos") || !strcmp(sub, "tan") ||
                                !strcmp(sub, "ctg")))
                flag = 1;
        } else
            i++;
    }
    if (cnt_closing != cnt_opening) flag = 0;

    return flag;
}

void add_zero_before_minus(char str[]) {
    char *appropriate = "0123456789x)";
    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] == '-' && is_in_mas(str[i - 1], appropriate) == -1 && i != 0) ||
            (str[i] == '-' && i == 0)) {
            int k = i;
            for (int j = strlen(str) + 1; j >= k; --j) {
                str[j] = str[j - 1];
            }
            str[strlen(str)] = '\0';
            str[k] = '0';
        }
    }
}

void format_string(char str[]) {
    int flag = 1;
    while (flag) {
        if (strstr(str, "sin")) {
            change_substring(str, "sin", "iRR");
            cut_string(str, 'R');
        } else if (strstr(str, "cos")) {
            change_substring(str, "cos", "oRR");
            cut_string(str, 'R');
        } else if (strstr(str, "tan")) {
            change_substring(str, "tan", "aRR");
            cut_string(str, 'R');
        } else if (strstr(str, "ctg")) {
            change_substring(str, "ctg", "tRR");
            cut_string(str, 'R');
        } else if (strstr(str, "sqrt")) {
            change_substring(str, "sqrt", "qRRR");
            cut_string(str, 'R');
        } else if (strstr(str, "ln")) {
            change_substring(str, "ln", "nR");
            cut_string(str, 'R');
        } else
            flag = 0;
    }
}

void change_substring(char str[], char sub[], char replace[]) {
    int ssl = strlen(sub), rpl = strlen(replace);
    char *p = strstr(str, sub);
    int l = rpl < ssl ? rpl : ssl;
    if (p) memcpy(p, replace, l);
}

void cut_string(char str[], char sym) {
    int k = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] != sym) str[k++] = str[i];
    str[k] = '\0';
}

char *gets_own(char *s) {
    int i, k = getchar();
    if (k == EOF) return NULL;
    for (i = 0; k != EOF && k != '\n'; ++i) {
        s[i] = k;
        k = getchar();
        if (k == EOF && !feof(stdin)) return NULL;
    }
    s[i] = '\0';
    return s;
}
