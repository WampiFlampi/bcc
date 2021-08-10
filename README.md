# bcc

Everything is fully functional 

The bracket mapping system and memory management should allow you to run on
embedded systems

https://github.com/rdebath/Brainfuck/tree/master/testing for benchmarking 

Error handling is also in the works, as of now, 
mismatched brackets and lack of file input will result
in a crash

## Commands for building and use:
    
    $ make
    $ ./bcc program.bf
    
Example:
    
    $ ./bcc bt/mandelbrot.bf

## Contributing: 

If you're interested in contributing or learning about
the project read the comments in this order

    
   * bf.h -> stack.c -> struct.c -> bf.c
   

If you're serious about benchmarking checkout 

    $ make profile
    
