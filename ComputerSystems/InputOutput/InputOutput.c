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
        long int binNum, remain, decNum = 0, i=1;

        FILE *fp;
        fp = fopen("binaryFile.txt", "a+");
        rewind(fp);

        fscanf(fp, "%ld", &binNum);
        fflush(fp);

        while(binNum != 0) {
                remain = binNum%10;
                decNum = decNum + remain*i;
                i=i*2;
                binNum = binNum/10;
        }

        fprintf(fp, "\r\n");
        fprintf(fp, "%ld", decNum);

        fclose(fp);
        return (EXIT_SUCCESS);
}
