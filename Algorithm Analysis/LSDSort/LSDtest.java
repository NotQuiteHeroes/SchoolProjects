
/*
 * LSD class test client
 * Paige Eckstein
 * Algorithm Analysis
 *
 * No Dependencies
 * To be used with LSD.java
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
import java.util.Scanner;
import java.util.ArrayList;

class LSDtest
{
public static void main(String[] args)
{
        //create scanner and LSD object
        Scanner scan = new Scanner(System.in);
        LSD lsd = new LSD();

        //array list to hold words from text file
        ArrayList<String> a = new ArrayList<String>();

        //populate array list of words
        while(scan.hasNext())
        {
                a.add(scan.nextLine());
        }

        int N = a.size();

        //get length of first word in array list of words
        int W = a.get(0).length();

        //make sure all words are the same length in the array list
        for(int i = 0; i < N; i++)
        {
                assert a.get(i).length() == W : "String/word length must be the same!";
        }

        //sort Array list of words
        lsd.sort(a, W);

        //print sorted array list
        for(String word: a)
        {
                System.out.println(word);
        }

}
}
