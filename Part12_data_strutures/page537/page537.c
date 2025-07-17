#include <stdio.h>
#include <stdlib.h>

#define NDCNT 3

int main(){
   struct node{
   char ch;   
   struct node *p;
   };

   struct node *pN = NULL,*tmp = NULL;
   pN = calloc(NDCNT,sizeof(struct node));
   pN->ch = 'a';
   tmp = pN;
   pN++;
   tmp->p = pN;

   pN->ch = 'b';
   tmp = pN;
   pN++;
   tmp->p = pN;

   pN->ch = 'c';
   pN->p = NULL;
  
   return 0;
}

/* cmake --build . --config Debug -- VERBOSE=1
break 15
run
 */