// Bjorn Larsen
// 4/25/2017

/*
Program Description:
    This program creates 3 different possible username options based on a first and last name input. Uses strings.
    
Pseudocode:
    SIZE First = 10
    SIZE Last = 20
    Function first username
    Function second username
    Function third username
    Declare Strings
    While Loop:
        Prompt user to input first and last
        Check that names aren't too long
        Check that names aren't the same
    Output 3 username options
    User chooses which they want
*/

#include <iostream>
#include <string>
using namespace std;

//SIZE First = 10
const int SIZE_FIRST = 10;

//SIZE Last = 20
const int SIZE_LAST = 20;

//Function first username
string First1(string firstName) { //First name string up to two 2 characters
    firstName.resize(2);
    return firstName;
}

//Function second username
string First2(string firstName) { //First name string
    return firstName;
}

//Function third username
string First3(string firstName) { //First name string up to two 1 character
    firstName.resize(1);
    return firstName;
}

int main() {
    
    //Declare Arrays:
    string firstName; //First Name
    
    string lastName; //Last name
    
    bool longName = true;
    bool sameName = true;
    
    //While Loop:
    while (longName||sameName) { //Names cannot be too long or the same
        
        //Prompt user to input first and last
        cout << "Enter First Name (10 characters max) and Last Name (20 characters max): " << endl;
        cin >> firstName;
        cin >> lastName;
        
        //Check that names aren't too long
        if (firstName.length() > SIZE_FIRST) { //if length of firstName is greater than 10
            cout << "First name is greater than 10 characters!" << endl << endl;
            longName = true; //resetting while loop condition
        }
        else if (lastName.length() > SIZE_LAST) { //if length of lastName is greater than 20
            cout << "Last name is greater than 20 characters!" << endl << endl;
            longName = true;
        }
        else {
            longName = false;
        }
        
        //Check that names aren't the same
        if (firstName.compare(lastName) == 0) { //When 2 strings have the same characters, function evaluates to 0
            cout << "Can't have same first and last name. Not in this town." << endl << endl;
            sameName = true;
        }
        else {
            sameName = false;
        }
    }
    
    string first1 = First1(firstName);
    string first2 = First2(firstName);
    string first3 = First3(firstName);
    
    //Output 3 username options
    cout << endl << "Which of the three usernames would you like (by number):" << endl;
    cout << "1: " << first1 + lastName << endl;
    cout << "2: " << first2 + lastName << endl;
    cout << "3: " << first3 + lastName << endl;
    
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