#include <stdio.h>
#include <stdlib.h>

#define NODECNT 10


int main(){
    struct node{
        /* data */
        int i;
        struct node *pNode;

    };
    struct node *pMem = malloc(sizeof(struct node) * NODECNT);
    printf("%p\n",pMem);
    return 0;
}
