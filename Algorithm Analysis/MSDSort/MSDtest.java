/*
 * MSD class test client
 * Paige Eckstein
 * Algorithm Analysis
 *
 * No Dependencies
 * To be used with MSD.java
 * and textfile containing any length words
 *
 * Most-Significant-Digit first string sort Algorithm
 * is a type of counting sort based on key-indexing
 * that works by partiting information into pieces
 * according to first character then recursively
 * sorts all strings that start with each character
 *
 * MSD string sort starts with the left-most character,
 * performs the key-indexing/count, then moves to the next left-most
 * character and so forth in this manner.
 */
import java.util.Scanner;
import java.util.ArrayList;

class MSDtest
{
public static void main(String[] args)
{
        //create scanner and MSD objects
        Scanner scan = new Scanner(System.in);
        MSD msd = new MSD();

        //create array list to hold words from text file
        ArrayList<String> a = new ArrayList<String>();

        //populate array list
        while(scan.hasNext())
        {
                a.add(scan.nextLine());
        }

        //sort array list of terms
        msd.sort(a);

        //print out sorted array list
        for(String word: a)
        {
                System.out.println(word);
        }
}
}
