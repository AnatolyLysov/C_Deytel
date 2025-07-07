#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w"); // Open the file for writing
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "Hello, this is a persistent file access example.\n");
    fprintf(file, "You can store data here.\n");
    fclose(file); // Close the file
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open the file for reading
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Print each line read from the file
    }
    fclose(file); // Close the file
}

int main() {
    const char *filename = "example.txt";

    writeToFile(filename); // Write data to the file
    printf("Data written to %s.\n", filename);

    printf("Reading data from %s:\n", filename);
    readFromFile(filename); // Read data from the file

    return 0;
}