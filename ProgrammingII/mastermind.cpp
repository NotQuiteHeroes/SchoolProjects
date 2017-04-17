/*
Paige Eckstein
Programming II
7/17/16
Number Guessing Game: Player guesses five number combination. Hints will indicate which numbers are correct.
Hints: 1 = Right Number, Right Place; 2 = Right Number, Wrong Place; 0 = Wrong Number
*/

#include<iostream>
#include<vector>
#include<cstdlib> //srand, rand
#include<ctime> //time
#include<string> 
#include<algorithm> //find
#include<numeric> //accumulate
#include<locale> //isalpha

using namespace std;

void generateMasterNumber(string& masterNumber);
void printRules();
bool parseInput(string userInput, string masterNumber);
void generateAnswerKey(string userInput, string masterNumber, string& answerKey);
bool gamePlay(string masterNumber);
int getGameType();
void quitGame(string masterNumber);


int main()
{
	srand(time(NULL));
	 
	string masterNumber;
	int rounds;

	generateMasterNumber(masterNumber);
	
	cout<<"Welcome to Mastermind! Type 'h' to view hints or 'q' to give up during game."<<endl;
	printRules();
	int gameType = getGameType();
	bool winner = false;
	
	//Freeplay
	if(gameType == 1)
	{
		while(!winner)
		{
			winner = gamePlay(masterNumber);
		}
		
		quitGame(masterNumber);
	}
	//Limited rounds
	else
	{
		int i = 0;
		cout<<"Enter number of rounds:"<<endl;
		cin>>rounds;
		
		while(i < rounds && !winner)
		{
			winner = gamePlay(masterNumber);
			i++;
		}
		
		cout<<"Out of guesses!"<<endl;
		quitGame(masterNumber);
	}
	
	return 0;
}

/*Creates temporary vector of strings to later be concatenated for masterNumber */ 
void generateMasterNumber(string& masterNumber)
{
	vector<string> tmpNumbers;
	int tmpNumber;
	
	for(int i = 0; i < 5; i++)
	{
		tmpNumber = rand() % 9;
		//
		tmpNumbers.push_back(to_string(tmpNumber));
	}
	
	//concatenate tmpNumbers elements
	masterNumber = accumulate(begin(tmpNumbers), end(tmpNumbers), string());
}

void printRules()
{
	cout<<"===============Hints===================="<<endl;
	cout<<"1 = Correct! Right Number, Right Place"<<endl;
	cout<<"2 = Close! Right Number, Wrong Place"<<endl;
	cout<<"3 = Wrong! Wrong Number, Wrong Place"<<endl;
	cout<<"'h' = hints               'q' = quit"<<endl;
	cout<<"========================================="<<endl;
}

/*Validate userInput for use with generateAnswerKey. Print hints or give up when prompted by user*/
bool parseInput(string userInput, string masterNumber)
{

	//Check size of input first
	if(userInput.size() > 5)
	{
		cout<<"Invalid input. Too many numbers. Try again."<<endl;
		gamePlay(masterNumber);
		return false;
	}
	
	//check if any character of userInput is letter instead of number
	for(int i = 0; i < 5; i++)
	{
		if(isalpha(userInput.at(i)))
		{
			//Check if user is prompting for hints
			if(userInput.at(i) == 'h' || userInput.at(i) == 'H')
			{
				printRules();
				return false;
			}
			//Check if user wants to give up
			else if(userInput.at(i) == 'q' || userInput.at(i) == 'Q')
			{
				quitGame(masterNumber);
			}
			//any other letters are invalid
			else
			{
				cout<<"Invalid input. Enter numbers between 0-9. Try again."<<endl;
				gamePlay(masterNumber);
				return false;
			}
		}
	}
		
	return true;	
}

//Choose freeplay or limited play
int getGameType()
{
	int gameType;
	
	cout<<"Choose game type: "<<endl;
	cout<<"1. Freeplay. No guess limit."<<endl;
	cout<<"2. Limit. Set number of guesses."<<endl;
	cout<<"Choose 1 or 2."<<endl;
	cin>>gameType;
	
	while(gameType != 1 && gameType != 2)
	{
		cout<<"Invalid input. Choose 1 or 2."<<endl;
		getGameType();
	}
	
	return gameType;
}

/*Get user guess. Call parseInput to validate user input. If valid, generate answer key. Return true if player wins, return false if not. */
bool gamePlay(string masterNumber)
{

	string answerKey;
	string userInput;
	
	cout<<"Enter your five digit guess without spaces: "<<endl;
	cin>>userInput;
	
	//if valid input, generate answer key
	if(parseInput(userInput, masterNumber)){
		generateAnswerKey(userInput, masterNumber, answerKey);
	}
	
	cout<<answerKey<<endl;
	
	//'11111' answerKey means all right numbers in all right positions
	if(answerKey == "11111")
	{
		cout<<"!!Winner!!"<<endl;
		return true;
	}
	else
	{
		return false;
	}
}

//Generate hints by comparing userInput to masterNumber
void generateAnswerKey(string userInput, string masterNumber, string& answerKey)
{

	vector<string> tmpAnswers;
	
	for(int i = 0; i < 5; i++)
	{
		
		//right number right place
		if(userInput.at(i) == masterNumber.at(i))
		{
			tmpAnswers.push_back("1");
		}
		//right number, wrong place
		else if(find(masterNumber.begin(), masterNumber.end(), userInput.at(i)) != masterNumber.end())
		{
			tmpAnswers.push_back("2"); 
		}
		//wrong number, wrong place
		else
		{
			tmpAnswers.push_back("0");
		}
	}
	
	//concatenate tmpAnswers vector
	answerKey = accumulate(begin(tmpAnswers), end(tmpAnswers), answerKey);
}

//print correct answer before exiting		
void quitGame(string masterNumber)
{
	cout<<masterNumber<<endl;
	cout<<"Thanks for playing!"<<endl;
}
	
	
