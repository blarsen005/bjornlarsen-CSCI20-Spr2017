// Bjorn Larsen
// 3/2/2017

/*
Program Description:
    This program prompts the user to enter two variables that determine the range for a random number generator.
    If the user enters the limits in the wrong order, the limits are swapped. The random number created by the
    generator is gets used as the value for pounds, which is then converted to kilograms, and back again to pounds.
    All these values are then output. The program also confirms that the initial pounds value and then final
    pounds value are equal, and if not, it lets the user know there was an error converting the values in the program.
    
Psuedocode:
    1) Declare Swap + RNG Function with 2 parameters.
    2) Declare Pounds to Kilograms function with single parameter.
    3) Declare Kilograms to Pounds function with single parameter.
    4) In main, Initialize and have user input two variables for RNG function.
    5) Call RNG Function.
    6) Call Kilograms to Pounds function using the return from the RNG function.
    7) Call Pounds to kilograms function using the return from the kilograms to pounds function.
    8) Test that pounds are equivalent to finalpounds.
    9) Output random number, pounds, kilograms, and final pounds.
    10) Define the 3 functions.
    
    11) Use comments to identify the scopes of all variables.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const double KG_PER_POUND = 0.453592; //KG_PER_POUND is a global variable with a scope of the whole file.

//Declare Swap + RNG Function with 2 parameters.
int SwapRngFunct(int&, int&);

//Declare Pounds to Kilograms function with single parameter.
double PoundsToKilograms(double);

//Declare Kilograms to Pounds function with single parameter.
double KilogramsToPounds(double);

int main() {
     
     //Initialize and have user input two variables for RNG function.
     int limitLow       = 0; //The scope of each variables is the entirety of main below where they were defined.
     int limitHigh      = 0; //
     int randomNum      = 0; //
     double pounds      = 0; //
     double kilograms   = 0; //
     double finalPounds = 0; //
     
     cout << "Enter first limit: " << endl;
     cin >> limitLow;
     cout << "Enter second limit: " << endl;
     cin >> limitHigh;
     
     //Call RNG Function.
     randomNum = SwapRngFunct(limitLow, limitHigh);
     
     //Call Kilograms to Pounds function using the return from the RNG function.
     pounds = randomNum;
     kilograms = PoundsToKilograms(pounds);
     
     //Call Pounds to kilograms function using the return from the kilograms to pounds function.
     finalPounds = KilogramsToPounds(kilograms);
     
     //Test that pounds are equivalent to finalpounds.
     if(pounds = finalPounds) {
         cout << "_______________________________________" << endl;
         cout << "Random Number: " << randomNum            << endl;
         cout << "Pounds: " << pounds << " lbs"            << endl;
         cout << "Kilograms: " << kilograms << " kg"       << endl;
         cout << "Final pounds: " << finalPounds << " lbs" << endl;
         cout << "_______________________________________" << endl;
     }
     
     else {
         cout << "Conversion error." << endl;
     }
     
     return 0;
}

//SwapRngFunct function definition.
int SwapRngFunct(int& limitLow, int& limitHigh) { //Scope of these variables is whole of SwapRngFunct.
     
     if(limitLow > limitHigh) {
         int x = limitLow; //Scope of x is just the rest of "if(limitLow > limitHigh)".
         limitLow = limitHigh;
         limitHigh = x;
     }
     
     else {
         limitLow = limitLow;
         limitHigh = limitHigh;
     }
     
     srand(time(0));
     int randomNum = 0;
     randomNum = (rand() % (limitHigh - limitLow + 1) + limitLow);
     return randomNum;
}

//PoundsToKilograms function definition.
double PoundsToKilograms(double pounds) { //Scope of pounds is the whole of PoundsToKilograms.
    return pounds * KG_PER_POUND;
}

//KilogramsToPounds function definition.
double KilogramsToPounds(double kilograms) { //Scope of kilograms is whole of KilogramsToPounds.
    return kilograms * (1 / KG_PER_POUND);
}