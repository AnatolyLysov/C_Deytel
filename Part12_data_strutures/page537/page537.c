#include <stdio.h>
#include <stdlib.h>

#define NODECNT 100

int main(){
    struct node_lbl{
        /* data */
        int i;
        struct node_lbl *pNode;

    };
    void *pChain = calloc(NODECNT,sizeof(struct node_lbl));
    
    if (pChain == NULL)
    {
       printf("memory allocation error");
       exit(1);
    }
   
    struct node_lbl *pNode = pChain;
    
    for(int i = 0; i <= 99; i++){
        pNode->i = i;
        pNode ++;
    } 

    return 0;
}
