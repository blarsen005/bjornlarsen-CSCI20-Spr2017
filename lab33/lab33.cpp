// Bjorn Larsen
// 3/30/2017

/*
Program Description:
    This program generates a random number and then runs a guessing game with the user. The user enters an initial guess and then the whole guessing
    game takes place inside a for loop which counts up number of guesses each time the loop runs. Once 10 guesses are reached, the program ends and
    the user loses. Within the for loop, contains the conditionals for if the number is right or wrong. Obviously if it's right, then the user wins,
    and if not, then an output is chosen based on if the user guessed too high or low. There is also a while loop for if the user guesses outside the
    range of 1 to 50, (located before the other conditionals) and does not count towards the number of guesses as dictated by the for loop.
    
Pseudocode:
    1. Computer generate random number between 1 and 50.
    2. Prompt user to enter value between 1 and 50.
    3. While user number above 50 or below 1, get new number.
    4. If statement for user number above random number.
    5. If statement for user number below random number.
    6. When user inputs actual answer, output Just right.
        Bonus: Add For loop where it counts number of guesses, and once user uses 10 guesses they lose.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Computer generate random number between 1 and 50.
int RngFunction() {
    
    srand(time(0)); //This sets random numbers to a seed based on the current time.
    return (rand() % 50) + 1; //% 100 sets random number range 0-49. +1 changes it to 1-50.
}

int main() {
    
    int randomNum = RngFunction(); //randomNum contains value for the time-based generated number throughout the whole of the program.
    int guess = 1;
    int numGuesses = 0;
    
    //Prompt user to enter value between 1 and 50.
    cout << "Enter a number between 1 and 50: ";
    cin >> guess;
    
    //Add For loop where it counts number of guesses, and once user uses 10 guesses they lose.
    for (numGuesses = 1; numGuesses < 10; numGuesses++) { //Initial state; condition; increment change
    
        if (guess != randomNum) { //Incorrect guess. Not a loop so guesses can keep counting
        
            //While user number above 50 or below 1, get new number.
            while (guess < 1 || guess > 50) { //Does not count for counting mechanism
                    
                cout << "Invalid. Enter a number between 1 and 50: ";
                cin >> guess; //This guess is either invalid again, or runs through the other
            }
            
            //If statement for user number above random number.
            if (guess > randomNum) { //if instead of while so counting mechanism can work
                
                cout << "Too High! Try again: ";
                cin >> guess;
            }
            
            //If statement for user number below random number.            
            else if (guess < randomNum) {
                
                cout << "Too Low! Try again: ";
                cin >> guess;
            }
        }
        
        else { //guess == randomNum
            cout << "Just Right." << endl;
            return 0;
        }
    }
    
    cout << "Ran out of Guesses. You Lose!" << endl; //Output reached once numGuesses == 10
    return 0;
}