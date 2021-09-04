#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"

int main(int argc, char *argv[]) {
     
    FILE *fp = fopen(argv[1], "r");

    extern struct node *h;  

    char *form(FILE *);
    char lstch = ']';
    
    size_t tape = 1000;
    //using calloc to zero the tape
    signed char *arr = calloc(tape, sizeof(signed char));
    signed char *ptr = arr;
   
    //only difference is memset() for zeroing 
    void extape () {
        tape += 1000;
        long int diff = (ptr - arr);
        signed char *tmp = arr;
        tmp = realloc(arr , tape * sizeof(signed char));
        
        if (tmp != NULL) {
            arr = tmp;
            ptr = arr + diff;
            memset(ptr, 0, sizeof(arr)); 
        }
        else {
            printf("memory error");
        }
    }


    char *start = form(fp);
    char *pos = start;

    while(*pos != '\0') {
        switch(*pos) {
            case '<':
                --ptr;
                break;
            case '>':
                ++ptr;
                if ((ptr - arr) == (tape - 1)) {
                    extape();
                }
                break;
            case '+':
                ++*ptr;
                break;
            case '-':
                --*ptr;
                break;
            case ',':
                *ptr = getchar();
                break;
            case '.':
                putchar(*ptr);
                break;
            case '[':
                if (*ptr) {
                    h = h->d;
                } else { 
                    pos = start + h->out;
                    h = h->l;
                }
                break;
            case ']':
                if (*ptr) {
                    pos = start + h->in;
                    h = h->d;
                } else { 
                    h = h->l;
                }
                break;

            
       }        
        
        ++pos;
    }  
    putchar('\n');
}

