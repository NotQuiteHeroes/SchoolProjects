/*
 * MSD class
 * Paige Eckstein
 * Algorithm Analysis
 *
 * No Dependencies
 * To be used with MSDtest.java
 * and textfile containing any length words
 *
 * most-Significant-Digit first string sort Algorithm
 * is a type of counting sort based on key-indexing
 * that works by partiting information into pieces
 * according to first character then recursively
 * sorts all strings that start with each character
 *
 * MSD string sort starts with the left-most character,
 * performs the key-indexing/count, then moves to the next left-most
 * character and so forth in this manner.
 */
import java.util.ArrayList;

class MSD
{
//extended ASCII
private static final int R = 256;
//cut off for insertion sort
private static final int cutOff = 15;

//public sort, used to call recursive private sort
public static void sort(ArrayList<String> a)
{
        int N = a.size();
        //auxiliary array to be used in transitional movement
        String[] aux = new String[N];
        //private recursive sort
        sort(a, 0, N-1, 0, aux);
}

//private recursive sort
//start from a.get(lo) to a.get(hi) starting at the dth character
private static void sort(ArrayList<String> a, int lo, int hi, int d, String[] aux)
{
        if(hi <= lo + cutOff)
        {
                insertion(a, lo, hi, d);
                return;
        }

        //holds frequency counts for each character
        int[] count = new int[R+2];

        //compute frequency counts
        for(int i = lo; i <= hi; i++)
        {
                int c = a.get(i).charAt(d);
                count[c+2]++;
        }

        //transform counts to indicies
        for(int r = 0; r < R+1; r++)
        {
                count[r+1] += count[r];
        }

        //move information using auxiliary array
        for(int i = lo; i <= hi; i++)
        {
                int c = a.get(i).charAt(d);
                aux[count[c+1]++] = a.get(i);
        }

        //copy back
        for(int i = lo; i <= hi; i++)
        {
                a.set(i, aux[i-lo]);

                //recursive call to sort for each character
                for(int r = 0; r < R; r++)
                {
                        sort(a, lo + count[r], lo + count[r+1] - 1, d+1, aux);
                }
        }
}

//insertion sort for small subarrays segmented by sort above
//assumes first d characters are equal
private static void insertion(ArrayList<String> a, int lo, int hi, int d)
{
        for(int i = lo; i <= hi; i++)
        {
                for(int j = i; j > lo && less(a.get(j), a.get(j-1), d); j--)
                {
                        exchange(a, j, j-1);
                }
        }
}

//swap function
private static void exchange(ArrayList<String> a, int i, int j)
{
        String temp = a.get(i);
        a.set(i, a.get(j));
        a.set(j, temp);
}

//if v is less than w, starting at character d
private static boolean less(String v, String w, int d)
{
        return v.substring(d).compareTo(w.substring(d)) < 0;
}
}
