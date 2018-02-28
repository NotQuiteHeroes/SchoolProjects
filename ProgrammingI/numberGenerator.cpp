//Creates phone numbers given first four numbers from user.
//If fourth number is even, fifth must be odd
//If fourth is odd, fifth must be even
//Last six digits equal 33
//Print all possible phone numbers

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void getFirstFour(vector<int>& numbers);
bool getEvenOdd(vector<int> numbers);
void getLastSix(bool evenOdd, vector<int>& numbers);
bool checkSum(vector<int> numbers);
void printNumbers(vector<int> numbers);


int main()
{
								vector<int>numbers(10);
								bool evenOdd;

								getFirstFour(numbers);
								evenOdd = getEvenOdd(numbers);
								getLastSix(evenOdd, numbers);

								return 0;
}

void getFirstFour(vector<int>& numbers)
{
								int num;
								for(int i = 0; i < 4; i++)
								{
																cout<<"Enter number #"<<i+1<<endl;
																cin>>num;
																while(num > 9 || num < 0)
																{
																								cout<<"Invalid input. Please enter a number between 0 and 9."<<endl;
																								cin >> num;
																}
																numbers[i] = num;
								}
}

bool getEvenOdd(vector<int> numbers)
{
								if(numbers[3] % 2 == 1)
								{
																return false;
								}

								return true;
}

void getLastSix(bool evenOdd, vector<int>& numbers)
{
								if(!evenOdd)
								{
																for(int i = 0; i < 10; i+=2)
																{
																								numbers[4] = i;

																								for(int j = 0; j < 10; j++)
																								{
																																numbers[5] = j;

																																for(int k = 0; k < 10; k++)
																																{
																																								numbers[6] = k;

																																								for(int l = 0; l<10; l++)
																																								{
																																																numbers[7] = l;

																																																for(int m = 0; m <10; m++)
																																																{
																																																								numbers[8] = m;

																																																								for(int n = 0; n<10; n++)
																																																								{
																																																																numbers[9] = n;

																																																																if(checkSum(numbers))
																																																																{
																																																																								printNumbers(numbers);
																																																																}
																																																								}
																																																}
																																								}
																																}
																								}
																}
								}
								else
								{
																for(int i = 1; i < 10; i+=2)
																{
																								numbers[4] = i;

																								for(int j = 0; j < 10; j++)
																								{
																																numbers[5] = j;

																																for(int k = 0; k < 10; k++)
																																{
																																								numbers[6] = k;

																																								for(int l = 0; l<10; l++)
																																								{
																																																numbers[7] = l;

																																																for(int m = 0; m <10; m++)
																																																{
																																																								numbers[8] = m;

																																																								for(int n = 0; n<10; n++)
																																																								{
																																																																numbers[9] = n;

																																																																if(checkSum(numbers))
																																																																{
																																																																								printNumbers(numbers);
																																																																}
																																																								}
																																																}
																																								}
																																}
																								}
																}
								}
}

bool checkSum(vector<int> numbers)
{
								int sum = 0;

								for(int i = 4; i < 10; i++)
								{
																sum = sum + numbers[i];
								}

								if(sum == 33)
								{
																return true;
								}

								return false;
}

void printNumbers(vector<int> numbers)
{
								cout<<numbers[0]<<numbers[1]<<numbers[2]<<" - ";
								cout<<numbers[3]<<numbers[4]<<numbers[5]<<" - ";
								cout<<numbers[6]<<numbers[7]<<numbers[8]<<numbers[9]<<endl;
}
