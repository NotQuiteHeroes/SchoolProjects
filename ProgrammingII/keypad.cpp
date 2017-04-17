//Programming II
//7/8/16
//Paige Eckstein
//Given a number between 0 - 999, return the next highest number that does not include 
//a 1, 4, or 7.

#include<iostream>
#include<string>

using namespace std;

void getFirstDigit(int initialNumber, int& first);
void getSecondDigit(int initialNumber, int& second);
void getThirdDigit(int initialNumber, int& third);
bool containsDigit(int number);
void modifyNumber(int& number);

int main()
{
	int initialNumber, first, second, third;
	
	cout<<"Please enter a number between 0 - 999"<<endl;
	cin>>initialNumber;
	
	//Check to make sure number is within valid range
	while(initialNumber < 0 || initialNumber > 999)
	{
		cout<<"Invalid input. Please enter a number between 0 and 999"<<endl;
		cin>>initialNumber;
	}
	
	//If number is only one digit
	if(initialNumber < 10)
	{
		getFirstDigit(initialNumber, first);
		
		//returns true if first number is 1, 4, 7
		if(containsDigit(first))
		{
			modifyNumber(first);
		}
		
		cout<<first<<endl;
	}
	//If number is two digits
	else if(initialNumber < 99 && initialNumber > 9)
	{
		getFirstDigit(initialNumber, first);
		getSecondDigit(initialNumber, second);
		
		//returns true if second number is 1, 4, 7
		if(containsDigit(second))
		{
			modifyNumber(second);
			//sets digit in tens place to 0
			first = 0;
		}
		//If second number is valid, check if first number is valid
		else
		{
			if(containsDigit(first))
			{
				modifyNumber(first);
			}
		}
		
		cout<<second<<first<<endl;
	}
	//If number is three digits
	else if(initialNumber <= 999 && initialNumber > 99)
	{
		getFirstDigit(initialNumber, first);
		getSecondDigit(initialNumber, second);
		getThirdDigit(initialNumber, third);
		
		//If third number is 1, 4, 7, set first and second number to 0
		if(containsDigit(third))
		{
			modifyNumber(third);
			second = 0;
			first = 0;
		}
		//Check if second and first number are valid (not 1, 4, 7)
		else
		{
			if(containsDigit(second))
			{
				modifyNumber(second);
				first = 0;
			}
			else
			{
				if(containsDigit(first))
				{
					modifyNumber(first);
				}
			}
		}
		
		cout<<third<<second<<first<<endl;
	}
}
		
//get number in ones place
void getFirstDigit(int initialNumber, int& first)
{
	first = initialNumber % 10;
}

//get number in tens place
void getSecondDigit(int initialNumber, int& second)
{
	second = initialNumber/10 % 10;
}

//get number in hundreds place
void getThirdDigit(int initialNumber, int& third)
{
	third = initialNumber/100 % 10;
}

//returns true if number is 1, 4, or 7. Else returns false
bool containsDigit(int number)
{
	if(number == 1 || number == 4 || number == 7)
	{
		return true;
	}
	
	return false;
}

//If number is 1,4, or 7, call this to add one to get valid number
void modifyNumber(int& number)
{
	number += 1;
}	
