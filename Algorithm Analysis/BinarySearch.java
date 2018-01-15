/**
 * Paige Eckstein
 * Algorithm Analysis
 * 2017
 *
 * Basic Binary Search
 * Hardcoded array to search through given for example
 * Asks user for number to find in array, then prints
 * number and position it is found at.
 * If number isn't found, print message stating so.
 *
 */
import java.util.Scanner;

public class BinarySearch
{
public static void main(String[] args)
{
        Scanner scan = new Scanner(System.in);
        System.out.println("What number are you searching for?");
        int searchTerm = scan.nextInt();

        int[] numbers = {1, 4, 15, 23, 55, 68, 70, 87, 99, 102};

        boolean found = search(searchTerm, numbers);
        if(!found)
        {
                System.out.println("No such number found.");
        }

}

public static boolean search(int searchTerm, int[] numbers)
{
        int low = 0;
        int high = numbers.length - 1;
        int mid;

        while(low <= high)
        {
                mid = low + (high-low)/2;

                if(numbers[mid] == searchTerm)
                {
                        System.out.println("Number " + searchTerm + " found at position " + mid);
                        return true;
                }
                else if(numbers[mid] < searchTerm)
                {
                        low = mid + 1;
                }
                else
                {
                        high = mid - 1;
                }
        }
        return false;
}
}
