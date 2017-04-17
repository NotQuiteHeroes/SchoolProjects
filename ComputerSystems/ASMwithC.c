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
int power(int base, int exp);

int main(int argc, char** argv) {
    
    int base, exp;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exp);
    printf("Results: ");
    power(base, exp);
        
    return (EXIT_SUCCESS);
}


void power(int base, int exp)
{
    int i, result = 1;
    for(i = 0; i < exp; i++)
        result *= base;
    printf("%d", result);
}

int power2(int num, int power)
{
    __asm
    {
        mov eax, num;
        move ecx, power;
        shl eax, cl;
    }
            
}

