/* 
 * File:   main.c
 * Author: paige
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x = 100, y = 25;
    __asm__("addl  %%ebx, %%eax"
            :"=a"(x)
            :"a"(x), "b"(y)
            );
    printf("x+y=%d\n", x);
    

    return (EXIT_SUCCESS);
}
