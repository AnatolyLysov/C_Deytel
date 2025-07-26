#include <stdio.h>

// Declare the external assembly function
extern int add_numbers(int a, int b);

int main() {
    int result = add_numbers(5, 3);  // Call the assembly function
    printf("Result: %d\n", result);   // Print the result
    return 0;
}