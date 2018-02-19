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
    int x = 100, y = 25, result = 0;;
    __asm__("addl  %%ebx, %%eax"
            :"=a"(result)
            :"a"(x), "b"(y)
            );
    printf("%d+%d=%d\n", x, y, result);


    return (EXIT_SUCCESS);
}
