#include <stdio.h>
#include <stdlib.h>

#define NDCNT 10

int main(){
    struct node{
         struct node *p;
    };
   
   struct node *pNode;
   pNode = calloc(NDCNT,sizeof(struct node));
   
   for(int i=1; i <= NDCNT; i++)
      pNode->p = pNode++;
      printf("%p\n",pNode);
   return 0;
}

/* cmake --build . --config Debug -- VERBOSE=1
gdb ./page537
break 15
run
 */