// Bjorn Larsen
// 4/20/2017 Blaze it

/*
Program Description:
    This program creates 3 different possible username options based on a first and last name input. Uses C strings.
    
Pseudocode:
    SIZE First = 10
    SIZE Last = 20
    Declare Arrays
    While Loop:
        Prompt user to input first and last
        Check that names aren't too long
        Check that names aren't the same
    Output 3 username options
    User chooses which they want
*/

#include <iostream>
#include <cstring>
using namespace std;

//SIZE First = 10
const int SIZE_FIRST = 10;

//SIZE Last = 20
const int SIZE_LAST = 20;

int main() {
    
    //Declare Arrays:
    char firstName[SIZE_FIRST]; //First Name[10]
    
    char lastName[SIZE_LAST]; //Last name[20]
    
    bool longName = true;
    bool sameName = true;
    
    //While Loop:
    while (longName||sameName) { //Names cannot be too long or the same
        
        //Prompt user to input first and last
        cout << "Enter First Name (10 characters max) and Last Name (20 characters max): " << endl;
        cin >> firstName;
        cin >> lastName;
        
        //Check that names aren't too long
        if (strlen(firstName) > SIZE_FIRST) { //if length of firstName is greater than 10
            cout << "First name is greater than 10 characters!" << endl << endl;
            longName = true; //resetting while loop condition
        }
        else if (strlen(lastName) > SIZE_LAST) { //if length of lastName is greater than 20
            cout << "Last name is greater than 20 characters!" << endl << endl;
            longName = true;
        }
        else {
            longName = false;
        }
        
        //Check that names aren't the same
        if (strcmp(firstName, lastName) == 0) { //When 2 strings have the same characters, function evaluates to 0
            cout << "Can't have same first and last name. Not in this town." << endl << endl;
            sameName = true;
        }
        else {
            sameName = false;
        }
    }
    
    //Output 3 username options
    cout << endl << "Which of the three usernames would you like (by number):" << endl << "1: ";
        for (int i = 0; i < 2; i++) { //Outputting string up to two 2 characters
            cout << firstName[i];
        }
    cout << lastName << endl << "2: ";
        for (int i = 0; firstName[i] != '\0'; i++) { //Outputting string until null operator
            cout << firstName[i];
        }
    cout << lastName << endl << "3: ";
        for (int i = 0; i < 1; i++) { //Outputting string up to 1 characters
            cout << firstName[i];
        }
    cout << lastName << endl;
    
    //User chooses which they want
    int username = 0;
    cin >> username;
    switch (username) {
        case 1:
        case 2:
        case 3:
            cout << "Great." << endl;
            break;
        default:
            cout << "Wrong." << endl;
    }
    
    return 0;
}