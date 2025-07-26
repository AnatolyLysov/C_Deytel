#include <stdio.h>

// Declare the assembly function
extern int add_numbers(int a, int b);

int main() {
    int result = add_numbers(5, 3);
    printf("Result: %d\n", result);
    return 0;
}