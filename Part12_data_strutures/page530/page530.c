#include <stdio.h>
#include <stdlib.h>
int main() {
    struct node {
        int a;
        struct node *nPtr;
    };
    struct node *mPtr = malloc(sizeof(struct node));
    
    if (mPtr != NULL) {
        printf("mPtr=%p\n", mPtr);
        // Optionally initialize the structure members if needed
        mPtr->a = 0;  // Example initialization
        mPtr->nPtr = NULL;  // Example initialization
    } else {
        printf("malloc return NULL\n");
    }
    // Free the allocated memory
    free(mPtr);
    
    return 0;
}