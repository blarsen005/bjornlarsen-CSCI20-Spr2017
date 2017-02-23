// Bjorn Larsen
// 2/23/2017

/*
Program Description:
    This program executes a function which generates and outputs a random number. The random number is within the range 1-100
    and is created from a seed based on current time.
    
Pseudocode:
    1) Include libraries <cstdlib> and <ctime>.
    2) Create a function template RngFunction.
    3) Within the RngFunction: 
       Set srand with seed time(0).
       Initialize a variable to be output.
       Use rand() to assign a random number to said variable.
       Output the number.
    4) Call the function in int main.
*/

 //Include libraries <cstdlib> and <ctime>.
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 using namespace std;
 
 //Create a function template RngFunction.
 void RngFunction() {
     
     srand(time(0)); //This sets random numbers to a seed based on the current time.
     int randomNum = 0;
     randomNum = (rand() % 100) + 1; //% 100 sets random number range 0-99. +1 changes it to 1-100.
     cout << "Your random number is " << randomNum << endl;
     
 }
 
 int main() {
     
     //Call the function in int main.
     RngFunction();
     
     return 0;
     
 }