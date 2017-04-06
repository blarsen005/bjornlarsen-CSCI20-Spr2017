// Bjorn Larsen
// 4/6/2017

/*
Program Description:
    This program allows the user to play "Rock Paper Scissors Lizard Spock" against a computer. The computer chooses one of the five
    options and the user chooses one. The program determines who has won each round and outputs current score at the end of each round.
    The user can choose an option of best out of 3, 5, or 7 rounds. The program determines who wins based on who reaches required number of
    rounds first. Here are the specific rules to the game:

                    Scissors cuts Paper 

                    Paper covers Rock 

                    Rock crushes Lizard 

                    Lizard poisons Spock 

                    Spock smashes Scissors 

                    Scissors decapitates Lizard 

                    Lizard eats Paper 

                    Paper disproves Spock 

                    Spock vaporizes Rock 

                    Rock crushes Scissors 
    
Pseudocode:
    Create "Game" class:
        private data includes:
            Rounds computer/player needs to win
            Rounds computer/player has won
            Choice (RPSLS)
            Choice as an integer (for use in switch case)
        Mutator function to select random option for computer's choice (rock, paper, scissors, lizard, or spock)
            Uses Random Number Generator and switch case
        Mutator function to select player's choice
            Takes user input
            Do-while loop to set choice in private data.
        Accessor function to return selection (computer and player)
        Mutator function: while loop with nested switch case to turn number of rounds into rounds needed to win
            Default is to reenter number of rounds, while loop repeats
        Accessor function called in round of play
        Function to adjust round parameters
        Function to return rounds won
        Constructors: set number of rounds to 3, computer and player to rock
    Main:
        User cin number of rounds
        Call mutator function for rounds needed for computer/player to win
        While loop for round of play:
            Condition: Rounds needed to win is less than rounds won by either player
            Call function to select player choice
            Call computer choice function
            Switch conditions for user choice (RPSLS):
                Condition for computer wins (2 selections)
                    Accessor functions for choices on both sides; output computer choice beats player choice
                    Rounds won by computer +1
                Condition for player wins
                    Accessor functions for choices on both sides; output player choice beats computer choice
                    Rounds won by player +1
                Condition for tie
                    Accessor functions for choices on both sides; output both sides cancel
                    No Rounds won change
            Output the current score at the end of the round
        If Rounds needed for computer to win > Rounds for player, computer wins!
        If Rounds needed for player to win > round for computer, player wins!
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Create "Game" class
class Game {
    
    private:
        
        //Rounds computer/player needs to win
        int rounds_to_win;
        
        //Rounds computer/player has won
        int rounds_won;
        
        //Choice (RPSLS)
        string choice_;
        
        //Choice as an integer (for use in switch case)
        int choice_integer;
        
    public:
        
        //Mutator function to select random option for computer's choice (rock, paper, scissors, lizard, or spock)
        void SetComputerChoice() {
            
            //Uses Random Number Generator and Switch case
            srand(time(0)); //This sets random numbers to a seed based on the current time.
            int randomNum = 0;
            randomNum = (rand() % 5) + 1; //% 100 sets random number range 0-4. +1 changes it to 1-5.
            
            switch (randomNum) { //Computer selects choice based on the randomly generated number
                
                case 1:
                    choice_ = "rock";
                    choice_integer = 1;
                    break;
                    
                case 2:
                    choice_ = "paper";
                    choice_integer = 2;
                    break;
                    
                case 3:
                    choice_ = "scissors";
                    choice_integer = 3;
                    break;
                    
                case 4:
                    choice_ = "lizard";
                    choice_integer = 4;
                    break;
                    
                case 5:
                    choice_ = "spock";
                    choice_integer = 5;
                    break;
                    
                default:
                    choice_ = "rock";
                    choice_integer = 1;
            }
            
            return;
        }
        
        //Mutator function to select player's choice
        void SetPlayerChoice(string choice) {
            
            //Takes user input
            choice_ = choice;
            
            //Do-while loop to set choice in private data.
            do {
                if (choice_ == "rock") {
                    choice_integer = 1;
                }
                
                else if (choice_ == "paper") {
                    choice_integer = 2;
                }
                
                else if (choice_ == "scissors") {
                    choice_integer = 3;
                }
                
                else if (choice_ == "lizard") {
                    choice_integer = 4;
                }
                
                else if (choice_ == "spock") {
                    choice_integer = 5;
                }
                
                else { //Player gets to re-enter input
                    
                    cout << "Not a valid choice. Enter rock, paper, scissors, lizard, or spock: ";
                    cin >> choice;
                    choice_ = choice;
                    choice_integer = 0; //This is just a convention to active the loop
                } 
            } while (choice_integer == 0); //Loop repeats when "else" option occurs
            return;
        }
        
        //Accessor function to return selection (computer and player)
        string GetChoice() { //For use in telling player results
            return choice_;
        }
        
        int GetChoiceInteger() { //For use in determining outcome of results
            return choice_integer;
        }
        
        //Mutator function: while loop with nested switch case to turn number of rounds into rounds needed to win
        void SetNumRoundsToWin(int& rounds) { //& used to ascribe rounds a value of zero to reactive do-while loop in main
                
            switch (rounds) { 
                
                case 3: //These cases are equivalent to the operation: rounds_to_win = rounds / 2 + 1
                    rounds_to_win = 2;
                    break;
                    
                case 5:
                    rounds_to_win = 3;
                    break;
                    
                case 7:
                    rounds_to_win = 4;
                    break;
                
                //Default is to reenter number of rounds, while loop repeats
                default:
                    rounds = 0; //This is just a convention to active the loop
                    break;
            }
        }
        
        //Accessor function called in round of play
        int GetNumRoundsToWin() {
            return rounds_to_win;
        }
        
        //Function to adjust round parameters
        void IncreaseNumRoundsWon() {
            rounds_won = rounds_won + 1;
            return;
        }
        
        //Function to return rounds won
        int GetNumRoundsWon() {
            return rounds_won;
        }
        
        //Constructor Function
        Game();
};

//Constructors: set number of rounds to 3, computer and player to rock
Game::Game() {
    rounds_to_win = 2;
    rounds_won = 0;
    choice_ = "rock";
    choice_integer = 0;
    return;
}

int main() {
    
    string choice = "rock";
    int rounds = 3;
    
    Game computer;
    Game player;
    
    //User cin number of rounds
    do {
        
        cout << "Set number of rounds (3, 5, or 7): ";
        cin >> rounds;
        
        //Call mutator function for rounds needed for computer/player to win
        computer.SetNumRoundsToWin(rounds);
        player.SetNumRoundsToWin(rounds);
    } while (rounds == 0); //Setter function uses & to set value of rounds to zero
    
    cout << endl;
    
    //While loop for round of play
    //Condition: Rounds needed to win is less than rounds won by either player
    while (computer.GetNumRoundsWon() < computer.GetNumRoundsToWin() && player.GetNumRoundsWon() < player.GetNumRoundsToWin()) { //Num Rounds to Win is constant for both objects.
        
        //Call function to select player choice
        cout << "Enter rock, paper, scissors, lizard, or spock: ";
        cin >> choice;
        player.SetPlayerChoice(choice);
        
        //Call computer choice function
        computer.SetComputerChoice();
        
        cout << "Player: " << player.GetChoice() << endl;
        cout << "Computer: " << computer.GetChoice() << endl;
        
        /*
        Switch conditions for user choice (RPSLS):
            Condition for computer wins (2 selections)
                Accessor functions for choices on both sides; output computer choice beats player choice
                Rounds won by computer +1
            Condition for player wins
                Accessor functions for choices on both sides; output player choice beats computer choice
                Rounds won by player +1
            Condition for tie
                Accessor functions for choices on both sides; output both sides cancel
                No Rounds won change
        */
        switch (player.GetChoiceInteger()) {
            
            case 1: //Computer choice options nested in player choice options
                
                switch (computer.GetChoiceInteger()) {
                    
                    case 3:
                    case 4:
                        cout << "Player Wins Round." << endl;
                        player.IncreaseNumRoundsWon();
                        break;
                    
                    case 2:
                    case 5:
                        cout << "Computer Wins Round." << endl;
                        computer.IncreaseNumRoundsWon();
                        break;
                    
                    case 1:
                        cout << "Draw." << endl;
                        break;
                    
                    default:
                        cout << "Error." << endl;
                        return 2; //This indicates possible issue with the computer choice generation.
                }
                
                break;
            
            case 2:
                
                switch (computer.GetChoiceInteger()) {
                    
                    case 1:
                    case 5:
                        cout << "Player Wins Round." << endl;
                        player.IncreaseNumRoundsWon();
                        break;
                    
                    case 3:
                    case 4:
                        cout << "Computer Wins Round." << endl;
                        computer.IncreaseNumRoundsWon();
                        break;
                    
                    case 2:
                        cout << "Draw." << endl;
                        break;
                    
                    default:
                        cout << "Error." << endl;
                        return 2; //This indicates possible issue with the computer choice generation.
                }
                
                break;
            
            case 3:
                
                switch (computer.GetChoiceInteger()) {
                    
                    case 2:
                    case 4:
                        cout << "Player Wins Round." << endl;
                        player.IncreaseNumRoundsWon();
                        break;
                    
                    case 1:
                    case 5:
                        cout << "Computer Wins Round." << endl;
                        computer.IncreaseNumRoundsWon();
                        break;
                    
                    case 3:
                        cout << "Draw." << endl;
                        break;
                    
                    default:
                        cout << "Error." << endl;
                        return 2; //This indicates possible issue with the computer choice generation.
                }
                
                break;
            
            case 4:
                
                switch (computer.GetChoiceInteger()) {
                    
                    case 5:
                    case 2:
                        cout << "Player Wins Round." << endl;
                        player.IncreaseNumRoundsWon();
                        break;
                    
                    case 3:
                    case 1:
                        cout << "Computer Wins Round." << endl;
                        computer.IncreaseNumRoundsWon();
                        break;
                    
                    case 4:
                        cout << "Draw." << endl;
                        break;
                    
                    default:
                        cout << "Error." << endl;
                        return 2; //This indicates possible issue with the computer choice generation.
                }
                
                break;
            
            case 5:
                
                switch (computer.GetChoiceInteger()) {
                    
                    case 1:
                    case 3:
                        cout << "Player Wins Round." << endl;
                        player.IncreaseNumRoundsWon();
                        break;
                    
                    case 4:
                    case 2:
                        cout << "Computer Wins Round." << endl;
                        computer.IncreaseNumRoundsWon();
                        break;
                    
                    case 5:
                        cout << "Draw." << endl;
                        break;
                    
                    default:
                        cout << "Error." << endl;
                        return 2; //This indicates possible issue with the computer choice generation.
                }
                
                break;
            
            default: //This shouldn't get used but exists just in case.
                cout << "Invalid. Redo:" << endl;
                break;
        }
        
        //Output the current score at the end of the round
        cout << "Player: " << player.GetNumRoundsWon() << " Computer: " << computer.GetNumRoundsWon() << endl;
        cout << endl;
    }
    
    //If Rounds needed for player to win > round for computer, player wins!
    if (player.GetNumRoundsWon() > computer.GetNumRoundsWon()) {
        cout << "You Win!" << endl;
    }
    
    //If Rounds needed for computer to win > Rounds for player, computer wins!
    else if (player.GetNumRoundsWon() < computer.GetNumRoundsWon()) {
        cout << "You Lose!" << endl;
    }
    
    else {
        cout << "Error" << endl;
        return 3; //This indicates possible error in setting the round conditions.
    }
    
    return 0;
}