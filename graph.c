#include "polish_logic.h"
#include "print_module.h"
#include "stack_functions.h"
#include "string_management.h"

int main() {
    char str[LEN];
    if (input(str)) {
        char polish_notation[LEN];
        int matrix[HEIGHT][WIDTH];
        format_string(str);
        add_zero_before_minus(str);
        to_polish_notation(str, polish_notation);
        graph_to_matrix(polish_notation, matrix);
        print_matrix(matrix);
    } else
        printf("\nERROR!");
    return 0;
}
