/**
 * Paige Eckstein
 * Software Systems Engineering
 *
 * This program takes a number and reverses its order before printing the
 * results.
 *
 * The number to reverse can be provided as a command line argument, or
 * it can be obtained from the user upon running the program.
 *
 * Compilation:
 * g++ reverseNum.cpp -o ReverseNum
 *
 * Execution:
 * ReverseNum.exe
 * or
 * ReverseNum.exe 123
 *
 * Example input and output:
 * ReverseNum.exe -123
 * -321
 *
 */
#include <iostream>
#include <cmath>

using namespace std;

int reverseNum(int num);

int main(int argc, char *argv[])
{
        int num;
        //if command line argument given, use this as number to reverse
        if(argc > 1)
        {
                num = stoi(argv[1]);
        }
        //otherwise, get number from user
        else
        {
                cout << "Enter a number to reverse: "<<endl;
                cin>>num;
        }
        cout << num << " reversed is: ";
        num = reverseNum(num);
        cout << num << endl;

        return 0;
}

/**
 * [reverseNum Takes integer and reverses its order]
 * @param  num [Number to reverse]
 * @return     [Given number in reverse order]
 */
int reverseNum(int num)
{
        bool negative = false;
        int reversed = 0;

        //if number is negative, set negative flag
        //and get absolute value of number to work with
        if(num < 0)
        {
                negative = true;
                num = abs(num);
        }

        while(num > 0)
        {
                //split number into inidividual parts (num%10) then swap
                //its position (reversed*10 + individual part)
                //finally remove digit last worked with from num (num/=10)
                reversed = reversed*10 + num%10;
                num /= 10;
        }

        //if the number was initially negative, add the negative sign back on
        if(negative)
        {
                reversed = -reversed;
        }

        return reversed;
}
