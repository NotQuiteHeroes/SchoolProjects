/*
 * File:   main.c
 * Author: paige
 *
 * Created on March 17, 2016, 11:00 PM
 */

#include <stdio.h>
#include <stdlib.h>


/*
 *
 */
int power2(int num, int power);
int power1(int base, int exp);

int main(int argc, char** argv) {

    int base, exp;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exp);
    printf("C Results: ");
        printf("\n");
    printf("%d", power1(base, exp));
    printf("\n");
    printf("ASM results: ");
        printf("\n");
    printf("%d", power2(base, exp));
        printf("\n");

    return (EXIT_SUCCESS);
}


int power1(int base, int exp)
{
    int i, result = 1;
    for(i = 0; i < exp; i++)
        result *= base;
    return result;
}

int power2(int num, int power)
{
  int result = 1;
    __asm__
    (
      "mov %[num], %%ebx\n\t"
      "mov %[power], %%ecx\n\t"
      "mov %[result], %%eax\n\t"
          "l1:\n\t"
          "mul %%ebx\n\t"
          "dec %%ecx\n\t"
          "cmp $1, %%ecx\n\t"
          "jne l1\n\t"
          ";"
          : [result] "=r" (result)
          : [num] "m" (num), [power] "m" (power)
          :
    );
}
