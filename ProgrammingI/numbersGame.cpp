#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>



using namespace std;

struct Values
{
								int value1;
								int value2;
								string operator1;
								int answer;
};

Values getValues(Values values);
void gamePlay(Values values);
void displayValues(Values values);


int main()
{
								Values values;
								string goAgain = "y";

								while(goAgain == "y")
								{
																values = getValues(values);
																gamePlay(values);

																cout<<"Would you like to play again? Enter 'y' or 'n'."<<endl;
																cin>>goAgain;
								}


								return 0;
}


Values getValues(Values values)
{
								int i = 0;
								string operators[3];
								operators[0] = "+";
								operators[1] = "-";
								operators[2] = "*";

								srand(time(NULL));

								values.value1 = rand() % 50 + 1;
								values.value2 = rand() % 50 + 1;
								i = rand() % 3 + 1;
								values.operator1 = operators[i-1];

								if(values.operator1 == "+")
								{
																values.answer = values.value1 + values.value2;
								}
								else if(values.operator1 == "-")
								{
																values.answer = values.value1 - values.value2;
								}
								else if(values.operator1 == "*")
								{
																values.answer = values.value1*values.value2;
								}

								return values;
}

void gamePlay(Values values)
{
								int count = 1;
								int guess;

								int value1 = values.value1;
								int value2 = values.value2;
								string operator1 = values.operator1;
								int answer = values.answer;

								displayValues(values);

								cout<<endl;
								cout<<endl;

								while(count != 0) {

																cout<<"Enter a guess for any single blank: "<<endl;
																cin>>guess;


																if(guess == value1)
																{
																								cout<<"Correct!"<<endl;
																								count--;
																}
																else if(guess == value2)
																{
																								cout<<"Correct!"<<endl;
																								count--;
																}
																else if(guess == answer)
																{
																								cout<<"Correct!"<<endl;
																								count--;
																}
																else
																{
																								cout<<"Incorrect! Try again."<<endl;
																}
								}


								cout<<value1<<" "<<operator1<<" "<<value2<<" =  "<<answer;
								cout<<endl;
								cout<<"Good Job!"<<endl;

}

void displayValues(Values values)
{
								srand(time(NULL));

								int i = rand() % 3 + 1;
								int j = rand() % 3 + 1;
								string tmpValue1, tmpValue2, tmpValue3;

								while(j == i)
								{
																j = rand() % 3 + 1;
								}

								for(int k = 1; k < 4; k++)
								{
																if(i != k)
																{
																								switch(k)
																								{
																								case 1:
																																tmpValue1 = " ___ ";
																																break;
																								case 2:
																																tmpValue2 = " ___ ";
																																break;
																								case 3:
																																tmpValue3 = " ___ ";
																																break;
																								}
																}
																else if(i == k)
																{
																								switch(k)
																								{
																								case 1:
																																tmpValue1 = to_string(values.value1);
																																break;
																								case 2:
																																tmpValue2 = to_string(values.value2);
																																break;
																								case 3:
																																tmpValue3 = to_string(values.answer);
																																break;
																								}

																}

																if(j == k)
																{
																								switch(k)
																								{
																								case 1:
																																tmpValue1 = to_string(values.value1);
																																break;
																								case 2:
																																tmpValue2 = to_string(values.value2);
																																break;
																								case 3:
																																tmpValue3 = to_string(values.answer);
																																break;
																								}
																}
								}
								cout<<tmpValue1<<" "<<values.operator1<<" "<<tmpValue2<<" = "<<tmpValue3<<endl;
}
