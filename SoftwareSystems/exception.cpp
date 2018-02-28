/*
   Paige Eckstein
   Software Systems
   12/16/16
   This program accepts a list of integers between the range -100 to 100 and
   outputs the sum of their squares
   Shows example of exception handling
 */

#include <cmath> //sqrt
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int returnSum(vector<int> initialNumbers);

int main() {
        vector<int> initialNumbers;
        int tempNumber;
        string tempString;

        cout << "Enter numbers to square and sum, one at a time." << endl;
        cout << "Enter * on a blank line when finished." << endl;

        try {
                do {
                        // get input from user until *
                        getline(cin, tempString);

                        // convert user input to int
                        tempNumber = atoi(tempString.c_str());

                        // if not in range, throw error to catch block
                        if (tempNumber < -100 || tempNumber > 100) {
                                throw "Number must be between -100 and 100";
                        }

                        // if valid number add to initialNumbers vector
                        initialNumbers.push_back(tempNumber);
                } while (tempString != "*");

                int sum = returnSum(initialNumbers);
                cout << "Total sum is: " << sum << endl;
        } catch (const char *errorMessage) {
                cout << "Error: " << errorMessage << endl;
        }
        return 0;
}

int returnSum(vector<int> initialNumbers) {
        int sum = 0;
        for (int i = 0; i < initialNumbers.size() - 1; i++) {
                sum += pow(initialNumbers[i], 2);
        }

        return sum;
}
