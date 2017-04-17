/*
   Paige Eckstein
   Operating Systems Design
   Algorithm to show frame replacement and page fault
   of FIFO algoritm
 */

#include <stdio.h>

int main(){
        int refString[15] = {0, 1, 2, 5, 4, 6, 2, 5, 0, 1, 3, 2, 1, 0, 2};
        int faults = 0, framesTotal = 3, pages = 15;
        int frames[3] = {-1, -1, -1};

        for(int i = 0; i < pages; i++)
        {
                int k = 0;
                for(int j = 0; j < framesTotal; j++)
                {
                        if(refString[i] == frames[j])
                        {
                                k++;
                                faults--;
                        }
                }
                faults++;
                if((faults <= framesTotal) && (k == 0))
                {
                        frames[i] = refString[i];
                }
                else if(k == 0)
                {
                        frames[(faults-1) % framesTotal] = refString[i];
                }
                printf("\n");
                for(int m = 0; m < framesTotal; m++) {
                        printf("%d\t", frames[m]);
                }
        }
        printf("\nTotal Page Faults: \t%d\n", faults);
        return 0;
}
