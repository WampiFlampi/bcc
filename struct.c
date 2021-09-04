#include <stdio.h>
#include <stdlib.h>

#include "bf.h"

void push(struct node *);
struct node *pop(void);


/*
Logically, an open bracket = ++treedepth
while a closed bracket = --treedepth

[] = Neutral Depth
[[ = ++depth
]] = --depth

Using this knowledge one can determine 
when to link downward to a child a node, and when to 
link the final child node of a depth back to its parent, 
which I store on the stack after a [[
*/

static char lstch;
struct node *initNode() {
    struct node *n = malloc(sizeof(struct node));
    n->in = 0;
    n->out = 0; 
    n->l = NULL;
    n->d = n;
    return n;
}

//tree head and pointer to current node
struct node head, *h = &head, *cr = &head;

//allocates a new node, maps previous node, and returns the new one
static struct node *map(struct node *in, int dir) {
    struct node *n = initNode();

    if (dir == 1) { 
        in->l = n;
    }
    else if (dir == -1) {
        n = pop();
        in->l = n; 
    }else {
        push(in);
        in->d = n;
    }
    return n; 
}

//Form reads from file *f, disregards extraneous chars and,
//returns an array to the remaining program instructions
//Form also creates the bracket map using map() and lstch

char *form(FILE *f) {
    h->d = h; 
    char c;
    size_t buffer = 1000;
    //instruction array
    char *prg = malloc(buffer * sizeof(char));
    char *pos = prg;
    
    //expand the array if needed 
    void exbuffer () {
        buffer += 2500;
        long int diff = (pos - prg);
        char *tmp = prg;

        tmp = realloc(prg , buffer * sizeof(char));

        if (tmp != NULL) {
            prg = tmp;
            pos = prg + diff;
        }
        else {
            printf("memory error");
        }
    }
    //was a bit lazy handling the base case here, did it better in bf.c
    while ((c = getc(f)) != '[') {
        switch(c) {
            case '+': case '-': case '.': case ',': case '>': case '<':
                *pos++ = c;
                break;
            case EOF:
                *pos = '\0';
                return prg;
            default:
                break;
        } 
        if ((pos - prg) == (buffer - 1)) {
             exbuffer();
        }
    }

    *pos = c;
    lstch = '[';
    h->in = (pos - prg);       
    
    while ((c = getc(f)) != EOF) {
        switch(c) {
            case '+': case '-': case '.': case ',': case '>': case '<':
                *++pos = c;
                break;

            case '[':
                *++pos = c;

                if (lstch == '[') {
                    cr = map(cr, 0);
                }else {
                    cr = map(cr, 1);
                }

                cr->in = (pos - prg);
                lstch = '[';
                break;

            case ']':
                *++pos = c; 

                if (lstch == ']') {
                    cr = map(cr, -1);
                }
                cr->out = (pos - prg); 

                lstch = ']';
                break;
            default:
                break;
        }
          if ((pos - prg) == (buffer - 1)) {
             exbuffer();
          }

    }

    *++pos = '\0';
    return prg;
}
