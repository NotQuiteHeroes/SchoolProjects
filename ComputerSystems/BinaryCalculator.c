/*
 * File:   main.c
 * Author: paige eckstein
 *
 * Created on January 23
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int sumFunc(int bin1, int bin2, bool display);
void difference(int bin1,int bin2);
int product(int bin1, int bin2);
/*
 *
 */
int main(int argc, char** argv) {
        int bin1, bin2;

        printf("Enter the first binary number: ");
        scanf("%d", &bin1);
        printf("Enter the second binary number: ");
        scanf("%d", &bin2);

        printf("Sum: ");
        sumFunc(bin1, bin2, true);
        printf("\n");
        printf("Difference: ");
        difference(bin1, bin2);
        printf("\n");
        printf("Product: ");
        product(bin1, bin2);

        return (EXIT_SUCCESS);
}

int sumFunc(int bin1, int bin2, bool display){
        int i = 0, r = 0, product = 0, sum[20];

        while(bin1 != 0 || bin2 != 0) {
                sum[i++] = (bin1 % 10 + bin2 % 10 + r) % 2;
                r = (bin1 % 10 + bin2 % 10 + r)/2;
                bin1 = bin1/10;
                bin2 = bin2/10;
        }
        if(r!=0)
                sum[i++] = r;
        i--;


        while(i >=0) {
                if(display)
                {
                        printf("%d", sum[i]);
                }
                product = product * 10 + sum[i];
                i--;
        }

        return product;
}

void difference(int bin1, int bin2){
        int temp = 0, sub = 0;

        temp = sumFunc(~bin2 + 1, bin1, false);
        //printf("%d bin2", bin2);

        printf("%d", temp);
}

int product(int bin1, int bin2){
        int product = 0, x = 0, factor = 1;
        int multiply = 0;

        while(bin2 != 0) {
                x = bin2 % 10;
                if(x == 1) {
                        bin1 = bin1*factor;
                        multiply = sumFunc(bin1, multiply, false);
                }
                else
                        bin1 = bin1 * factor;
                bin2 = bin2/10;
                factor = 10;
        }
        printf("%d", multiply);
        return 0;
}
