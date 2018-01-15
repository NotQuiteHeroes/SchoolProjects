/*
 * LSD class
 * Paige Eckstein
 * Algorithm Analysis
 *
 * No Dependencies
 * To be used with LSDtest.java
 * and textfile containing equal length words
 *
 * Least-Significant-Digit first string sort Algorithm
 * is a type of counting sort based on key-indexing
 * that works by counting the number of objects having
 * distinct key values then using arithmetic to calculate
 * the position of each object in the output sequence
 *
 * LSD string sort starts with the right-most character,
 * performs the key-indexing/count, then moves to the next right-most
 * character and so forth in this manner.
 */
import java.util.ArrayList;

class LSD
{
public static void sort(ArrayList<String> a, int W)
{
        int N = a.size();

        //extended ASCII alphabet size for radix
        int R = 256;

        //auxiliary array to be used in intermediate movement
        String[] aux = new String[N];

        //start at end of word and move to the left
        //sorting by key-indexed counting on ith character
        for(int i = W-1; i >= 0; i--)
        {
                //holds frequency counts for each character
                int[] count = new int[R+1];

                //compute frequency counts
                for(int j = 0; j < N; j++)
                {
                        count[a.get(j).charAt(i) + 1]++;
                }

                //transform counts to indices
                //this is the key-indexed counting
                //computes cumulates
                for(int k = 0; k < R; k++)
                {
                        count[k+1] += count[k];
                }

                //move data using auxiliary array
                for(int m = 0; m < N; m++)
                {
                        aux[count[a.get(m).charAt(i)]++] = a.get(m);
                }

                //copy data back to original array list
                for(int n = 0; n < N; n++)
                {
                        a.set(n,aux[n]);
                }
        }
}
}
