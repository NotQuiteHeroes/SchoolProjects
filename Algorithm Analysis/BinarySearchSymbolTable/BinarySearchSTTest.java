/**
 * Paige Eckstein
 * Algorithm Analysis
 * 2017
 *
 * BinarySearchST illustrates a symbol table
 * implemented with a binary search tree.
 *
 * Takes input in form of file with letters
 * given one per line
 * Output:
 *
 * size = x
 * min = A
 * max = Y
 *
 * keys()
 * ------
 * A 8
 * B 0
 * C 10
 *
 * etc. for each key and its corresponding last found position
 *
 * select()
 * --------
 * 0 A
 * 1 B
 * 2 C
 *
 * etc. for each key in alphabetical order, numbered for convenience
 *
 * key rank floor ceiling
 * ----------------------
 * A 0 A A
 * B 1 B B
 * C 2 C C
 * D 3 C E
 *
 * etc. for each letter in the alphabet (key)
 * where rank is the number of keys in the symbol table
 * that are strictly less than the key
 * floor is the largest key in the symbol table that is
 * less than or equal to the key
 * and ceiling is the smallest key in the symbol table
 * that is greater tan or equal to the key.
 *
 * To be used with BinarySearchSTTest.java as test client
 * and BSTtest.txt as test input.
 *
 * Example use:
 * java BinarySearchSTTest < BSTtest.txt
 */
import java.util.Scanner;

class BinarySearchSTTest {
public static void main(String[] args) {

        BinarySearchST<String, Integer> st = new BinarySearchST<String, Integer>(20);

        Scanner scan = new Scanner(System.in);

        //read in text from file
        for (int i = 0; scan.hasNextLine(); i++)
        {

                String key = scan.nextLine();
                st.put(key, i);

        }

        System.out.println("size = " + st.size());
        System.out.println("min = " + st.min());
        System.out.println("max = " + st.max());
        System.out.println();
        System.out.println("keys() \n -----------");
        for (String s : st.keys())
        {
                System.out.println(s + " " + st.get(s));
        }
        System.out.println();
        System.out.println("select() \n -----------");
        for (int i = 0; i < st.size(); i++)
        {
                System.out.println(i + " " + st.select(i));
        }
        System.out.println();
        System.out.println("key rank floor ceiling \n ---------------------");
        String[] alpha = {"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        for (String s : alpha)
        {
                System.out.println(s + " " + st.rank(s) + " " + st.floor(s)+ " " + st.ceiling(s));
        }


}
}
