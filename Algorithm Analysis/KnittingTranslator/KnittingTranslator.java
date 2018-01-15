/**
 * Paige Eckstein
 * Algorithm Analysis
 * Knitting Translator for German to English usage
 *
 * To be used with text file of German - English
 * translation pairs.
 *
 * Usage:
 * javac KnittingTranslator.java
 *
 */
import java.util.Scanner;
import java.util.Hashtable;
import java.util.Arrays;

import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;

import java.lang.StringBuilder;

class KnittingTranslator
{

static Scanner scan = new Scanner(System.in);

public static void main(String[] args)
{
        //Hashtable to hold German terms as keys
        //and English terms as values
        Hashtable<String, String> terms = populateDictionary();

        if(args.length == 0)
        {
                menu(terms);
        }
        else
        {
                translate(terms, args);
        }
}

/**
 * populateDictionary reads in translation pairs from text file, splits
 * them into key value pairs and returns hashtable of pairs
 * @return [Hashtable containing German terms as keys, and English pairs]
 */
static Hashtable<String, String> populateDictionary()
{
        Hashtable<String, String> terms = new Hashtable<>();

        try{
                FileReader fr = new FileReader("terms.txt");
                BufferedReader br = new BufferedReader(fr);
                String line = br.readLine();
                //read in line by line from terms file
                while(line != null)
                {
                        //split German term from English term
                        String[] splitTerms = line.split(" ");
                        //create map entry with German term as key
                        //and English term as value
                        terms.put(splitTerms[0], splitTerms[1]);
                        line = br.readLine();
                }
                br.close();
        }
        catch (IOException e)
        {
                System.out.println("*********************************************");
                System.out.println("Cannot find dictionary.");
                System.out.println("Please make sure dictionary text file ");
                System.out.println("exists in the same folder as the application.");
                System.out.println("Also make sure it is named terms.txt.");
                System.out.println("*********************************************");

        }
        return terms;
}

/**
 * Menu options for user to translate terms or update dictionary
 * @param Hashtable terms [German terms are keys, English terms are values]
 */
static void menu(Hashtable terms)
{
        System.out.println("Enter 1 to translate text.");
        System.out.println("Enter 2 to update the dictionary.");
        System.out.println("Enter 3 to exit.");
        int choice = scan.nextInt();
        scan.nextLine();

        switch(choice)
        {
        case 1:
                translate(terms);
                break;
        case 2:
                updateDictionary(terms);
                break;
        case 3:
                System.out.println("Thanks, goodbye!");
                return;
        default:
                System.out.println("Please enter a number between 1 and 3.\n");
                menu(terms);
        }
}

/**
 * Translate gets text from user in German to translate into English
 * @param Hashtable terms [German terms are keys, English terms are values]
 */
static void translate(Hashtable terms)
{
        System.out.println("Enter text to translate: ");
        //get text to translate from user
        String input = scan.nextLine();
        while(input.equals(""))
        {
                System.out.println("Please enter text to translate. This cannot be blank.");
                input = scan.nextLine();
        }
        //tokenize input and store to array
        String[] splitInput = tokenize(input.toLowerCase());

        StringBuilder sb = new StringBuilder();

        //for each individual word, number, or punctuation mark in tokenized array
        for(String term : splitInput)
        {
                //if element is punctuation or a number, simply keep as is
                if(!Character.isLetter(term.charAt(0)))
                {
                        sb.append(term + " ");
                }
                //if element exists as key in hashtable terms, return the value
                else if(terms.containsKey(term))
                {
                        sb.append(terms.get(term) + " ");
                }
                //if element doesn't exist as key in hastable terms, simply keep as is
                else
                {
                        sb.append(term + " ");
                }
        }

        System.out.println(sb);

        System.out.println("Would you like to save the translation? yes/no");
        String answer = scan.nextLine();
        if(answer.equals("yes") || answer.equals("Yes") || answer.equals("y"))
        {
                saveTranslation(sb.toString());
        }

        menu(terms);
}

/**
 * translate to be used with command line arguments
 * @param Hashtable terms [German terms as keys, English terms as values]
 * @param String[]  input [command line arguments]
 */
static void translate(Hashtable terms, String[] input)
{
        //recombine input into single string to resplit to our specifications
        String fullInput = Arrays.toString(input);
        //tokenize input and store to array
        String[] splitInput = tokenize(fullInput.toLowerCase());

        StringBuilder sb = new StringBuilder();

        //for each individual word, number, or punctuation mark in tokenized array
        for(String term : splitInput)
        {
                //if element is punctuation or a number, simply keep as is
                if(!Character.isLetter(term.charAt(0)))
                {
                        sb.append(term + " ");
                }
                //if element exists as key in hashtable terms, return the value
                else if(terms.containsKey(term))
                {
                        sb.append(terms.get(term) + " ");
                }
                //if element doesn't exist as key in hastable terms, simply keep as is
                else
                {
                        sb.append(term + " ");
                }
        }

        System.out.println(sb);
}
/**
 * tokenize uses regex to remove whitespace from user input String
 * then splits into elements, making punctuation its own element
 * separate from the words themselves
 * @param  String input         [user input string to translate]
 * @return                      [returns tokenized input as array]
 */
static String[] tokenize(String input)
{
        //regex to split punctuation from words
        String regex = "\\s+|(?=\\p{Punct})|(?<=\\p{Punct})";
        //replace all removes whitespace before splitting using regex defined above
        return input.replaceAll("\\s+(?=\\p{Punct})", "").split(regex);
}

/**
 * updateDictionary allows user to add their own translation pair to
 * textfile terms.txt
 */
static void updateDictionary(Hashtable terms)
{
        System.out.println("Enter the German term to add: ");
        String germanTerm = scan.nextLine();
        while(germanTerm.equals(""))
        {
                System.out.println("Please enter German term to add. This cannot be blank.");
                germanTerm = scan.nextLine();
        }
        System.out.println("Enter the English translation: ");
        String englishTerm = scan.nextLine();
        while(englishTerm.equals(""))
        {
                System.out.println("Please enter English translation. This cannot be blank.");
                englishTerm = scan.nextLine();
        }

        BufferedWriter bw = null;

        try{
                //connect to terms.txt file
                bw = new BufferedWriter(new FileWriter("terms.txt", true));
                //add new translation pair in format:
                //GermanTerm EnglishTerm
                bw.write(germanTerm + " " + englishTerm);
                //append newline after adding text
                bw.newLine();
                bw.flush();
        } catch (IOException e) {
                e.printStackTrace();
        } finally {
                try {
                        if(bw != null)
                        {
                                bw.close();
                        }
                } catch (IOException e2) {}
        }
        menu(terms);
}

/**
 * saveTranslation will take a translated text and save it to a text file
 * called savedTranslation.txt
 * @param String translation [already translated text to be saved]
 */
static void saveTranslation(String translation)
{
        BufferedWriter bw = null;

        try{
                bw = new BufferedWriter(new FileWriter("savedTranslation.txt", true));
                bw.write(translation);
                //append newline after adding text
                bw.newLine();
                bw.flush();
        } catch (IOException e) {
                e.printStackTrace();
        } finally {
                try {
                        if(bw != null)
                        {
                                bw.close();
                        }
                } catch (IOException e2) {}
        }
}

}
