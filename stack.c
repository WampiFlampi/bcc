#include <stdio.h>
#include "bf.h"


//Simple array of pointers to node
static struct node *stack[500];

static struct node **sp = stack; 

//using pointers makes these operations less costly
void push(struct node *n) { 
    if (sp - stack == 500) {
        printf("stack full\n");
    }else {
        *sp++ = n;
    }
}

struct node *pop() { 
   if (sp - stack == 0) { 
      printf("empty\n");
      return 0;
   }
   return *--sp;
}


