/*
   Paige Eckstein
   Operating Systems Design
   Algorithm to show frame replacement and page fault
   of LRU algoritm
 */

#include <stdio.h>

int findLRU(int time[], int n)
{
        int minimum = time[0], position = 0;

        for(int i = 1; i < n; ++i)
        {
                if(time[i] < minimum) {
                        minimum = time[i];
                        position = 1;
                }
        }

        return position;
}

int main(){
        int refString[15] = {0, 1, 2, 5, 4, 6, 2, 5, 0, 1, 3, 2, 1, 0, 2};
        int faults = 0, counter = 0, position = 0, framesTotal = 3, pages = 15, flag1, flag2;
        int frames[3] = {-1, -1, -1};
        int time[10];

        for(int i = 0; i < pages; i++)
        {
                flag1 = flag2 = 0;

                for(int j = 0; j < framesTotal; ++j)
                {
                        if(frames[j] == refString[i])
                        {
                                counter++;
                                time[j] = counter;
                                flag1 = flag2 = 1;
                                break;
                        }
                }

                if(flag1 == 0) {
                        for(int k = 0; k < framesTotal; ++k)
                        {
                                if(frames[k] == -1)
                                {
                                        counter++;
                                        faults++;
                                        frames[k] = refString[i];
                                        time[k] = counter;
                                        flag2 = 1;
                                        break;
                                }
                        }
                }

                if(flag2 == 0)
                {
                        position = findLRU(time, framesTotal);
                        counter++;
                        faults++;
                        frames[position] = refString[i];
                        time[position] = counter;
                }

                printf("\n");

                for(int m = 0; m < framesTotal; ++m)
                {
                        printf("%d\t", frames[m]);
                }
        }

        printf("\n\nTotal Page Faults: \t%d\n", faults);

        return 0;
}
