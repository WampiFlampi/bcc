#define fori(B) for(int i = 0; i < B; i++)

/*
tree of bracket positions 

    h -> node -> node
    | \          | |
(node->node)     node
        | |
        node

*/

struct node {
    int in;
    int out;
    struct node *l;
    struct node *d; 
};


  
