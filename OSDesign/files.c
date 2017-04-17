/*
   Paige Eckstein
   Program to illustrate I/O operations for adding a file to end of contiguous file
   system and linked list file system. Assume linked list does not implement
   FAT. Given 100 files in system.
 */

#include <stdio.h>

int main()
{
        int cio = 0;

        //adding element to end of contiguous system only requires one write operation
        //as files are stored sequentially - no need to read every element, simply
        //find end of list and add one (write one)
        for(int i = 0; i < 100; i++) {
                if(i == 99) {
                        cio++;
                }
        }

        int llio = 0;

//adding element to end of linked list without pointer to last element
//requires reading through every element (100) plus writing one to end
//If pointer to last element is provided, would only take three operations
//one to read in last element, one to write new last element, and one to write
//new last element pointer
        for(int j = 0; j < 100; j++) {
                llio++;
        }
        llio += 1; //for final write

        printf("Total operations for contiguous system: %d", cio);
        printf("\nTotal operations for linked list: %d\n", llio);
}
