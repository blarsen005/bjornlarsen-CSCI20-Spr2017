// Bjorn Larsen
// 2/28/2017

/*
Problem Statement:
    Create a program with the following two functions:
     - random number generator between two values of the user’s choice – accepts two values, swaps them (using the function),
       and outputs a random number between them.
     - swap function accepts two values and swaps them – accepts two values and swaps the values.
    Your main program needs to accept the smallest number first and then the largest. It should then send them to the random number generator.
    The random number generator should swap them and then runs and outputs the random number.
    
Pseudocode:
    1) Include iostream, clibst, time.
    2) Declare swap function with pass by reference variables.
    3) Declare RNG function with pass by value variables.
    4) In main, prompt user to input the two limits.
    5) Call RNG function with parameters lower limit and upper limit.
    6) Define swap function.
    7) Define RNG function. Call swap function and use time and rand/srand functions.
*/
 
 //Include iostream, clibst, time.
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 using namespace std;
 
 //Declare swap function.
 void SwapFunct(int&, int&);
 
 //Declare RNG function.
 void RngFunct(int, int);
 
 int main() {
      
     //Prompt user to input the two limits.
     int limitLow  = 0;
     int limitHigh = 0;
     
     cout << "Enter first limit: " << endl;
     cin >> limitLow;
     cout << "Enter second limit: " << endl;
     cin >> limitHigh;
     
     //Call RNG function with parameters lower limit and upper limit.
     RngFunct(limitLow, limitHigh);
     return 0;
 }
 
 
 //Define swap function with pass by reference variables.
 void SwapFunct(int& limitLow, int& limitHigh) {
     
     if(limitLow > limitHigh) { //Swap function applies if user inputs upper limit before lower limit.
         int x = 0;
         x = limitLow;
         limitLow = limitHigh;
         limitHigh = x;
     }
     
     else { //Parameters left as they are if user inputs lower limit then higher limit.
         limitLow = limitLow;
         limitHigh = limitHigh;
     }
     
     return;
 }
 
 //Define RNG function with pass by value variables. Call swap function and use time and rand/srand functions.
 void RngFunct(int limitLow, int limitHigh) {
     
     SwapFunct(limitLow, limitHigh);
     srand(time(0));
     int randomNum = 0;
     randomNum = (rand() % (limitHigh - limitLow + 1) + limitLow);
     cout << "A random number between " << limitLow << " and " << limitHigh << " is " << randomNum << "." << endl;
     return;
 }