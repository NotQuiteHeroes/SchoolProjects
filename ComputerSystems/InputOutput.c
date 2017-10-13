/* 
 * File:   main.c
 * Author: Paige Eckstein
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    long binNum, remain, decNum = 0, i=1;
    
    FILE *fp;
    fp = fopen("binaryfile.txt", "rb+");
    fscanf(fp, "%ld", binNum);
    
    while(binNum ! = 0){
        remain = binNum%10;
        decNum = decNum + remain*i;
        i=i*2;
        binNum = binNum/10;
    }
    
    fprintf(fp, decNum);
    
    fclose(fp);
    return (EXIT_SUCCESS);
}
