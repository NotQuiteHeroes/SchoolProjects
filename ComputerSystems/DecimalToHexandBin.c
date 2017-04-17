/* 
 * File:   main.c
 * Author: Paige Eckstein
 *
 * Created on January 17, 2016
 */

#include <stdio.h>
#include <stdlib.h>


int toBin(int x);
int toHex(int x);

/*
 * 
 */
int main(int argc, char** argv) {
    int x;
    
    printf("Enter a base 10 number to convert: ");
    scanf("%d", &x);
    
    toBin(x);
    printf("\n");
    toHex(x);
    
    return (EXIT_SUCCESS);
}

int toBin(int x){
    int i = 0, q, r, j, binNum[100];
    q = x;
    
    while(q!=0){
        binNum[i++] = q % 2;
        q /= 2;
    }
    printf("%d to binary: ", x);
    for(j = i - 1; j>=0; j--)
        printf("%d", binNum[j]);
    
    return 0;      
    
}

int toHex(int x){
    int i = 0, q, r, j, tmp;
    char hexNum[100];
    q = x;
    
    while(q!=0){
        tmp = q % 16;
        if(tmp < 10)
            tmp += 48;
        else
            tmp += 55;
        hexNum[i++] = tmp;
        q /= 16;
    }
    printf("%d to hex: ", x);
    for(j = i - 1; j>=0; j--)
        printf("%c", hexNum[j]);
    
    return 0;   
}

