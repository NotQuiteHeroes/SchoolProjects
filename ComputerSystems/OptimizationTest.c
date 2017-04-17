/* 
 * File:   main.c
 * Author: paige
 *
 * Created on February 21, 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int naive();
int opt();

int naive()
{
    int i, j, k, l, n = 10000, product = 0;
 
    clock_t begin, end;
    double time_spent;
 
    begin = clock();
    
    for(k=0; k<n;k++){
        for(j=0; j<n; j++){
            for(l=0;l<n; l++){
               product = product * 1; 
            }
        }
    }
    for ( i = 0; i < 32000; i++) {
        printf("%d\n", i);
    }
 
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    return 0;
}

int opt()
{
    int i, j, k, l, n = 10000, product = 0;
 
    clock_t begin, end;
    double time_spent;
 
    begin = clock();
    
    for(k=0;k<n;k++){
        for(l=0;l<n;l++){
            for(j=0;j<n;j++){
                product = product*1;
            }
        }
    }
    for ( i = 0; i < 32000; i++) {
        printf("%d\n", i);
    }
 
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    return 0;
}

int main(){
    naive();
    opt();
    return 0;
}
