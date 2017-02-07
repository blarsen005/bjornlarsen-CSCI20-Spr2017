// Created by: Bjorn Larsen
// 2/7/2017

/*
This program displays to the user a cash voucher displaying the number of cents the user has input,
the amount of each coin equivalent, the total cash equivalent, and the total cash returning to the user
after a fee of 10.9%. 

This program does not round final cash values to 2 decimal places.

Pseudocode:
    1) Initialize variables for cents input, quarters, dimes, nickels, pennies, and pre/post fee cash values.
       Also include a variable for remaining cents during calculations.
    2) Prompt user to input number of cents. Display input back to the user.
    3) Divide cents by 25 for # of quarters, mod for remaining cents.
       Divide by 10 for number of dimes, mod for remainder.
       Divide by 5 for number of nickels, mod for number of pennies.
    4) Display coin varieties.
    5) Convert cents input to a float.
    6) Divide cents by 100 for pre-fee cash value.
    7) Apply fee to cents input. Divide by 100 for post-fee cash value.
    8) Display pre/post-fee cash values.
*/

 #include <iostream>
 using namespace std;
 
 int main() {
     int centsInitial    = 0; // centsInitial must be initialized as an integer for coin calculations.
     int centsRemaining  = 0;
     int numQuarters     = 0;
     int numDimes        = 0;
     int numNickels      = 0;
     int numPennies      = 0;
     double preFeeValue  = 0;
     double postFeeValue = 0;
     
     cout << "How many cents do you enter?" << endl;
     cin >> centsInitial;
     cout << "You have entered " << centsInitial << " cents." << endl;
     
       numQuarters    = centsInitial / 25;
       centsRemaining = centsInitial % 25;
       numDimes       = centsRemaining / 10;
       centsRemaining = centsRemaining % 10;
       numNickels     = centsRemaining / 5;
       numPennies     = centsRemaining % 5;
     
     cout << "That was " << numQuarters << " quarters, " << numDimes << " dimes, "
          << numNickels << " nickels, and " << numPennies << " pennies." << endl;
     
     double centsInitial2  = centsInitial; // New float variable equivalent to input for cash values.
       preFeeValue  = centsInitial2 / 100;
       postFeeValue = (centsInitial2 * 0.891) / 100; // 100% - fee of 10.9% = 89.1% => 0.891
     
     cout << "The total is $" << preFeeValue << ". After the fee you get $" << postFeeValue << " in cash.";
     
     return 0;
     
 }