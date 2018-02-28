#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void rules();
void scoreRules();
vector<int> roll();
int getPlayers();
vector<string> determineOrder(int noOfPlayers);
vector< vector<int> > setupScore();
void gamePlay(int noOfPlayers, vector<string> names, vector<vector<int> >scoreCards);
vector<int> getKeepers(vector<int>die);
vector<vector<int> > score(vector<int> die, vector<vector<int> > scoreCards, int index);
void finalScore(int noOfPlayers, vector<vector<int> > scoreCards, vector<string>names);

int main()
{
        string playAgain = "y";
        while(playAgain == "y" || playAgain == "yes")
        {
                rules();
                int noOfPlayers = getPlayers();
                vector<string> names = determineOrder(noOfPlayers);
                vector<vector<int> > scoreCards = setupScore();
                gamePlay(noOfPlayers, names, scoreCards);
                cout<<"Would you like to play again? Enter yes or no."<<endl;
                cin>>playAgain;
                while(playAgain != "yes" && playAgain != "no")
                {
                        cout<<"Invalid input. Please enter 'yes' or 'no'."<<endl;
                        cin>>playAgain;
                }
        }


        return 0;
}

void rules()
{
        cout<<"===========================Welcome to Yahtzee!========================="<<endl;
        cout<<"Rules:\n";
        cout<<"*The game consists of 13 rounds.\n";
        cout<<"*Each player rolls five dice and attempts to score different combinations.\n";
        cout<<"*Each turn consists of 3 rolls.\n";
        cout<<"*A round is complete when each player has taken their turn.\n";
        cout<<"*For each roll, the player may choose to keep any number of dice he or she wishes.\n";
        cout<<"*The object of the game is to fill every possible scoring combination, \n";
        cout<<" and the player with the highest total score wins!\n";
        cout<<"*Per round, each player must enter a score into one of the combinations.\n";
        cout<<"*The player may enter a 0 into any box if he or she does not wish to \n";
        cout<<" enter a score for the current dice combination left at the end of the turn.\n";
        cout<<"*Good luck and have fun!!"<<endl;
        cout<<"======================================================================="<<endl;
}

void scoreRules()
{
        cout<<"===Upper Section==="<<endl;
        cout<<"1. Aces - Add all ones in hand."<<endl;
        cout<<"2. Twos - Add all twos in hand."<<endl;
        cout<<"3. Threes - Add all threes in hand."<<endl;
        cout<<"4. Fours - Add all fours in hand."<<endl;
        cout<<"5. Fives - Add all fives in hand."<<endl;
        cout<<"6. Sixes - Add all sixes in hand."<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"===Lower Section==="<<endl;
        cout<<"7. Three of a Kind - Add all dice in hand."<<endl;
        cout<<"8. Four of a Kind - Add all dice in hand."<<endl;
        cout<<"9. Full House - Three of a Kind and a separate Pair. 25pts."<<endl;
        cout<<"10. Small Straight - Four sequential numbers. 30pts."<<endl;
        cout<<"11. Large Straight - Five sequential numbers. 40pts."<<endl;
        cout<<"12. YAHTZEE! - Roll five of the same number. 50pts."<<endl;
        cout<<"13. Chance - Add the total of all five dice."<<endl;
}

vector<int> roll()
{
        vector<int> die(5, -1);
        srand(time(NULL));

        for(int i = 0; i < 5; i++)
        {
                die[i] = rand() % 6+1;
        }

        return die;
}


int getPlayers()
{
        int noOfPlayers = 0;

        cout<<"Please enter the number of players: "<<endl;
        cin>>noOfPlayers;

        while(noOfPlayers > 4 || noOfPlayers < 1)
        {
                cout<<"Please enter a valid number between 1 and 4."<<endl;
                cin>>noOfPlayers;
        }

        return noOfPlayers;
}


vector<string> determineOrder(int noOfPlayers)
{
        vector<int>order;
        vector<string> names(4);

        if(noOfPlayers == 1)
        {
                cout<<"Enter your name: "<<endl;
                cin>>names[0];
                return names;
        }
        else
        {
                srand(time(NULL));
                for(int i = 0; i < noOfPlayers; i++)
                {
                        int roll = rand() % 30 + 1;
                        cout<<"Player "<<i+1<<" your total is: "<<roll<<endl;;
                        order.push_back(roll);
                }

                sort(order.rbegin(), order.rend());

                for(int j = 0; j < noOfPlayers; j++)
                {
                        cout<<"Player with total "<<order[j]<<" enter your name: "<<endl;
                        cin>>names[j];
                }

                return names;
        }
}

vector< vector<int> > setupScore()
{
        vector< vector<int> > scoreCards(4, vector<int>(13, -1));

        for(int i = 0; i < 4; i++)
        {
                scoreCards[i][13] = 0;
        }

        return scoreCards;
}

void gamePlay(int noOfPlayers, vector<string> names, vector<vector<int> > scoreCards)
{
        const int MAX = 13;
        int round = 1;
        srand(time(NULL));
        int noToHold;

        while(round <= MAX)
        {
                for(int i = 0; i < noOfPlayers; i++)
                {
                        vector<int>die1(5);
                        vector<int>die2(5);
                        vector<int>die3(5);



                        cout<<"===== Round: "<<round<<" ====="<<endl;
                        cout<<names[i]<<" it is your turn!"<<endl;
                        cout<<"Roll 1: "<<endl;

                        die1 = roll();

                        die2 = getKeepers(die1);

                        cout<<"Roll 2: "<<endl;

                        die3 = getKeepers(die2);

                        cout<<"Roll 3: "<<endl;

                        scoreCards = score(die3, scoreCards, i);
                }

                round++;
        }

        finalScore(noOfPlayers, scoreCards, names);
}


vector<int> getKeepers(vector<int>die)
{
        for(int j = 0; j < 5; j++)
        {
                cout<<die[j]<<" ";
        }

        int noToHold;

        cout<<endl;
        cout<<"Enter the number of dice you want to re-roll: "<<endl;
        cin>>noToHold;

        while(noToHold > 5)
        {
                cout<<"Invalid input. Please enter a number between 1 and 5."<<endl;
                cin>>noToHold;
        }

        vector<int> keepers(noToHold);

        for(int k = 0; k < noToHold; k++)
        {
                cout<<"Enter the die position (1-5) of die "<<k+1<<" you want to roll again."<<endl;
                cin>>keepers[k];
        }

        for(int m = 0; m < noToHold; m++)
        {
                int n = keepers[m] - 1;
                die[n] = rand() % 6+1;
        }
        return die;
}

vector<vector<int> > score(vector<int> die, vector<vector<int> > scoreCards, int index)
{
        int scoreBoxNo = 0;
        int sum = 0;
        string answer, upLow;

        cout<<endl;
        cout<<"Your final dice are: "<<endl;
        for(int i = 0; i < 5; i++)
        {
                cout<<die[i]<<" ";
        }

        cout<<endl;

        scoreRules();
        cout<<"Please enter 'upper' or 'lower' to score: "<<endl;
        cin>>upLow;

        while(upLow != "upper" && upLow != "lower")
        {
                cout<<"Invalid input. Please enter 'upper' or 'lower'."<<endl;
                cin>>upLow;
        }

        if(upLow == "upper")
        {
                cout<<"Please enter number to score: "<<endl;
                cin>>scoreBoxNo;

                while(scoreBoxNo < 1 && scoreBoxNo > 6)
                {
                        cout<<"Invalid input. Please enter a number between 1 and 6."<<endl;
                        cin>>scoreBoxNo;
                }

                while(scoreCards[index][scoreBoxNo-1] != -1)
                {
                        cout<<"Score already exists. Please enter a different score box."<<endl;
                        cin>>scoreBoxNo;
                }

                for(int i = 0; i < 5; i++)
                {
                        if(die[i] == scoreBoxNo)
                        {
                                sum = sum + scoreBoxNo;
                        }
                }
        }

        else if(upLow == "lower")
        {
                cout<<"Please enter number to score: "<<endl;
                cin>>scoreBoxNo;

                while(scoreBoxNo < 7 && scoreBoxNo > 13)
                {
                        cout<<"Invalid input. Please enter a number between 7 and 13."<<endl;
                        cin>>scoreBoxNo;
                }

                while(scoreCards[index][scoreBoxNo-1] != -1)
                {
                        cout<<"Score already exists. Please enter a different box to score."<<endl;
                        cin>>scoreBoxNo;
                }

                switch(scoreBoxNo)
                {
                case 7:
                        cout<<"Do you have three of a kind? Enter 'yes' or 'no'. "<<endl;
                        cin>>answer;

                        if(answer == "yes")
                        {
                                for(int j = 0; j < 5; j++)
                                {
                                        sum = sum + die[j];
                                }
                        }
                        else
                        {
                                sum = 0;
                        }
                        break;

                case 8:
                        cout<<"Do you have four of a kind? Enter 'yes' or 'no'."<<endl;
                        cin>>answer;

                        if(answer == "yes")
                        {
                                for(int k = 0; k < 5; k++)
                                {
                                        sum = sum + die[k];
                                }
                        }
                        else
                        {
                                sum = 0;
                        }
                        break;

                case 9:
                        cout<<"Do you have a Full House? Enter 'yes' or 'no'."<<endl;
                        cin>>answer;

                        if(answer == "yes")
                        {
                                sum = 25;
                        }
                        else
                        {
                                sum = 0;
                        }
                        break;

                case 10:
                        cout<<"Do you have a Small Straight? Enter 'yes' or 'no'."<<endl;
                        cin>>answer;

                        if(answer == "yes")
                        {
                                sum = 30;
                        }
                        else
                        {
                                sum = 0;
                        }
                        break;

                case 11:
                        cout<<"Do you have a Large Straight? Enter 'yes' or 'no'. "<<endl;
                        cin>>answer;

                        if(answer == "yes")
                        {
                                sum = 40;
                        }
                        else
                        {
                                sum = 0;
                        }
                        break;

                case 12:
                        cout<<"Do you have YAHTZEE? Enter 'yes' or 'no'."<<endl;
                        cin>>answer;

                        if(answer == "yes")
                        {
                                sum = 50;
                                scoreCards[index][13] = 100;
                        }
                        else
                        {
                                sum = 0;
                        }
                        break;

                case 13:
                        cout<<"Chance!"<<endl;

                        for(int m = 0; m < 5; m++)
                        {
                                sum = sum + die[m];
                        }
                        break;
                }
        }

        scoreBoxNo = scoreBoxNo - 1;
        scoreCards[index][scoreBoxNo] = sum;
        return scoreCards;
}

void finalScore(int noOfPlayers, vector<vector<int> > scoreCards, vector<string> names)
{
        vector<int> finalScores(4, 0);
        int finalScore = 0;
        for(int i = 0; i < noOfPlayers; i++)
        {
                for(int j = 0; j < 13; j++)
                {
                        finalScore = finalScore + scoreCards[i][j];
                }

                finalScores[i] = finalScore;

                cout<<"Player "<<i+1<<" your final score is: "<<finalScore<<endl;
        }

        int winner = 0;
        int currentHigh = 0;
        for(int k = 0; k < noOfPlayers; k++)
        {
                if(finalScores[k] > currentHigh)
                {
                        currentHigh = finalScores[k];
                        winner = k;
                }
        }

        cout<<names[winner]<<" you have won!!!"<<endl;
}
