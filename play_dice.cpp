// play_dice.cpp : The purpose of this system is to play the dice game of craps.
// Author:		David Batista
// Date:			February 21, 2021

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

//dice values
struct diceValues
{
    int die1;
    int die2;
    int sum;
    char play_again;
    char start_game;
    int last;
    int wins;
    int losses;
    int rolls;
    int games_played;
};

//function prototype
void loadData();
void startCheck();
void startGames();
void contGame();

//structures
using namespace std;
diceValues diceValues1;


int main()
{
    //get rand value
    srand(time(NULL));

    //call loadData function
    loadData();

    //start game check
    startCheck();

    //start function
    startGames();

    //continue game
    contGame();

    return(0);
}

//function define

void loadData()
{
    diceValues1.die1 = 0;
    diceValues1.die2 = 0;
    diceValues1.sum = 0;
    diceValues1.play_again = ' ';
    diceValues1.start_game = ' ';
    diceValues1.play_again = ' ';
    diceValues1.last = 0;
    diceValues1.wins = 0;
    diceValues1.losses = 0;
    diceValues1.rolls = 0;
    diceValues1.games_played = 0;

}//end of loadData()

void startCheck()
{
    cout << "Press S to start the game or X to exit." << endl;
    cin >> diceValues1.start_game;
    if (diceValues1.start_game == 'X') 
    { 
        cout << "Next time you should play the game :}" << endl;
        exit(0);

    }    diceValues1.games_played++;
}//end of startChecks()

void startGames()
{
    do
    {
        //roll die
        diceValues1.die1 = rand() % 6 + 1;
        diceValues1.die2 = rand() % 6 + 1;
        diceValues1.sum = diceValues1.die1 + diceValues1.die2;

        //update num of rolls
        diceValues1.rolls++;

        //let player know the result of the roll
        cout << "Let’s roll two dice! You got " << diceValues1.die1 << " and " << diceValues1.die2 << ". " << endl << "Your sum is " << diceValues1.sum << ". ";

        if ((diceValues1.sum == 7) || (diceValues1.sum == 11))
        {

            cout << "Player won!!!" << endl;
            diceValues1.wins++;
            cout << "Press S to start the game or X to exit." << endl;
            cin >> diceValues1.start_game;

            diceValues1.play_again = ' ';

            if (diceValues1.start_game == 'X')
            {
                cout << "You played " << diceValues1.games_played << " games, you won " << diceValues1.wins << " and you lost " << diceValues1.losses << "! You rolled " << diceValues1.rolls << " times!" << endl;
                exit(0);
            }
            else
                diceValues1.games_played++;
            startGames();

        }

        else if ((diceValues1.sum == 2) || (diceValues1.sum == 3) || (diceValues1.sum == 12))
        {

            cout << "Player Lose!!!" << endl;
            diceValues1.losses++;
            cout << "Press S to start the game or X to exit." << endl;
            cin >> diceValues1.start_game;

            diceValues1.play_again = ' ';

            if (diceValues1.start_game == 'X')
            {
                cout << "You played " << diceValues1.games_played << " games, you won " << diceValues1.wins << " and you lost " << diceValues1.losses << "! Your rolled " << diceValues1.rolls << " times!" << endl;
                exit(0);
            }
            else
                diceValues1.games_played++;
            startGames();
        }

        else
        {
            diceValues1.last = diceValues1.sum;
            cout << "This is your point! Press C to throw again!" << endl;
            cin >> diceValues1.play_again;
            diceValues1.rolls++;
            diceValues1.start_game = ' ';
        }

    } while (diceValues1.start_game == 'S');
}//end of startGames()

void contGame()
{
    do
    {
        //update roll die
        diceValues1.die1 = rand() % 6 + 1;
        diceValues1.die2 = rand() % 6 + 1;
        diceValues1.sum = diceValues1.die1 + diceValues1.die2;

        cout << "Let’s roll two dice! You got " << diceValues1.die1 << " and " << diceValues1.die2 << ". " << endl << "Your point was " << diceValues1.last << ". ";

        if (diceValues1.sum == 7)
        {
            cout << "Player Lose!!!" << endl;
            diceValues1.losses++;
            cout << "Press S to start the game or X to exit." << endl;
            cin >> diceValues1.start_game;

            diceValues1.play_again = ' ';

            if (diceValues1.start_game == 'X')
            {
                cout << "You played " << diceValues1.games_played << " games, you won " << diceValues1.wins << " and you lost " << diceValues1.losses << "! You rolled " << diceValues1.rolls << " times!" << endl;
                exit(0);
            }
            else
                diceValues1.games_played++;
            startGames();
        }

        else if (diceValues1.sum == diceValues1.last)
        {
            cout << "Player Won!!!" << endl;
            diceValues1.wins++;
            cout << "Press S to start the game or X to exit." << endl;
            cin >> diceValues1.start_game;

            diceValues1.play_again = ' ';

            if (diceValues1.start_game == 'X')
            {
                cout << "You played " << diceValues1.games_played << " games, you won " << diceValues1.wins << " and you lost " << diceValues1.losses << "! You rolled " << diceValues1.rolls << " times!" << endl;
                exit(0);
            }
            else
                diceValues1.games_played++;
            startGames();
        }

        else
        {
            cout << "Press C to throw again!" << endl;
            cin >> diceValues1.play_again;
            diceValues1.rolls++;
        }

    } while (diceValues1.play_again == 'C');
}//end of contGame()