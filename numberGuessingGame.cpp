numberGuessingGame.cpp


#include <iostream>
#include <cstdlib>
#include<ctime>
#include <vector>
using namespace std;

/** 
 * Game: Game where user is able to guess numbers (can either play with computer or another player -if playing with another player, players will alternate in being the "computer")
 * User is to guess a number between 1-20, best guess out of 11 wins
**/

/**
 * Programming steps
 * 1. welcome page
 * 2. Ask if the user wants to play against computer or another player
 * 
 * a. IF COMPUTER Chosen: 
 * 1. commputer chooses a number
 * 3. player guesses a number
 * 4. computer guess to number, 
 * 5. if guess correct - prompt to to another guess ( 3 chances to guess the correct number)
 * 
 * b. IF PLAYER Chosen: 
 * 1. Player 1 choses a number, player 2 guesses that number 
 * 2. if Correct,  switch - player 2 pickes numberm player 1 guesses (3 chances to guess)
 * 3. Winner is the one who guesses in the least number of tries
 * 
 * 3. ask if they want to play again 
 * 4. if yes, enter new round
 * 5. if no, thank for playing + show final score 
 * */
void welcomeMessage()
{
    cout << "Welcome to our number guessing game!" << endl;
    cout << "You can play this game with a frined or alone, versing a commputer." << endl;
    cout << "If you would like to play against a computer enter \"computer\" ." << endl; 
    cout << "If you would like to play against another player, enter \"player\" ." << endl;
}
void gameRules (string &gameMode)
{
    if (gameMode == "computer")
    {
        cout << "The computer will choose a number between 1 - 20." << endl;
        cout << "You have 3 guesses to match the number the computer chose. Have fun!" << endl;
    }
    else if (gameMode == "player")
    {
        cout << "Player1 will start by picking a number and PLayer2 will guess the number within 3 guesses." << endl;
        cout << "After Player2 guesses the number, Player2 will then pick a number for Player1 to guess within 3 tries." << endl;
        cout << "The player who guesses the correct number in the least number of tries wins." << endl;
    }
}
//for single player mode
int computerRandomNumber()
{
    return rand() % 20 + 1;
}
//Checks if user input is a integer
bool isStringInt (string userInput)
{
    bool isInt = true; 
    for (int i=0; i< userInput.length(); i++)
    {
        if (userInput.at(i) >= 32 &&  userInput.at(i) <= 47)
        {
            isInt = false;
        }
        else if (userInput.at(i) >= 58 &&  userInput.at(i) <= 126)
        {
            isInt = false;
        }
    }
    return isInt;
}

int getPlayerGuess()
{
    string userGuess;
    cout << "Enter your guess:";
    cin >> userGuess;
    cout << endl;
    while (!isStringInt(userGuess))
    {
        cout << "Please enter a valid number between 1 - 20" << endl;
        cin >> userGuess;
    }
    int userGuessInt = stoi (userGuess);
    return userGuessInt;
}
int compareGuesses(int num1, int num2, int &score, bool &isGuessCorrect)
//compares user with computer
{
    if (num1 < num2)
    {
        cout << "User number is too big!" << endl;
        score++; 
    }
    else if( num1 > num2)
    {
        cout << "User number is too small!" << endl;
        score++;
    }
    else if (num1 == num2)
    {
        cout << "Yay you got it!" << endl;
        isGuessCorrect = true;
        score ++;
    }
}

//checks if inputted number matches the one player/computer has in mind
bool checkIfEqual( int num1, int num2)
{
    if (num2==num1)
    {
        return true;
    }
    else 
    {
        return false; 
    }
}
void singlePlayer(int &score)
{
    srand(time(0));
    int computerNum; 
    int playerGuess; 
    bool isGuessCorrect; 
    score = 0;
    int numGuesses = 0;
    computerNum = computerRandomNumber();
    // (for testing purposes) cout << computerNum;
    while (numGuesses < 3 && !isGuessCorrect)
    {
        playerGuess = getPlayerGuess();
        compareGuesses (computerNum, playerGuess, score, isGuessCorrect);
        ++ numGuesses; 
    }
    
}
//gets number from player1
int player1Num ()
{
    int player1N ;
    cout << "Player1 enter a number between 1 - 20. Make sure you dont let Player2 see it!" << endl;
    cin >> player1N; 
    return player1N;
}
//gets number from player2
int player2Num ()
{
    int player2N ;
    cout << "Player2 enter a number between 1 - 20. Make sure you dont let Player1 see it!" << endl;
    cin >> player2N; 
    return player2N;
}
void doublePlayer (vector <int> &scores)
{
    srand(time(0));
    int player1; 
    int player2; 
    bool isGuessCorrect; 
    int numGuesses =0;
    int score =0;
    
    player2 = player2Num();
    cout << "Player1, enter the number you think Player2 has in mind." << endl;
    while (numGuesses < 3 && !isGuessCorrect)
    {
        player1 = getPlayerGuess();
        compareGuesses (player2, player1, score, isGuessCorrect);
        numGuesses ++; 
    }
    scores.at(0) = score;
    score = 0;
    numGuesses =0;
    isGuessCorrect = false;
    player1 = player1Num();
    cout << "Player2, enter the number you think Player1 has in mind." << endl;
    while (numGuesses < 3 && !isGuessCorrect)
    {
        player2 = getPlayerGuess();
        compareGuesses (player1, player2, score, isGuessCorrect);
        numGuesses ++; 
    }
    scores.at(1) = score;
}
void finalScoreSingle(int &score)
{
    cout << "Your took a total of " << score << " tries to guess the correct number" << endl;
}
void playerWinner(vector <int> &score)
{
    if (score.at(0)< score.at(1))
    {
        cout << "Player1 wins!";
    }
    else if (score.at(0) > score.at(1))
    {
        cout << "Player2 wins!";
    }
    else
    {
        cout << "There was a TIE! Both Players wins!";
    }
}
void finalScoreDouble (vector <int> &score)
{
    cout << "Player1 took a total of " << score.at(0) << " to guess the right number." << endl;
    cout << "Player2 took a total of " << score.at(1) << " to guess the right number." << endl;
    playerWinner(score);
}
int main ()
{
    srand(time(0));
    int scoreS = 0; 
    vector <int> scoreD (2); 
    string playerMode; 
    string playAgain = "yes"; 
    welcomeMessage();
    cin >> playerMode; 
    while (playerMode != "player" && playerMode != "computer")
    {
        cout << "Please enter \"computer\" or \"player\" mode" << endl;
        cin >> playerMode;
    }
    while (playAgain == "yes" && playerMode == "computer")
    {
        gameRules(playerMode);
        singlePlayer(scoreS);
        
        cout << "Type \" yes \" to play again or anything else to quit.";
        cin >> playAgain; 
        cout << endl;
    }
    while (playAgain == "yes" && playerMode == "player")
    {
        gameRules(playerMode);
        doublePlayer(scoreD);
        
        cout << "Type \" yes \" to play again or anything else to quit.";
        cin >> playAgain; 
        cout << endl;
    }
    
    if (playerMode == "computer")
    {
        finalScoreSingle(scoreS);
    }
    if (playerMode == "player")
    {
        finalScoreDouble (scoreD);
    }
    
}