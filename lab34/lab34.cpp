// Bjorn Larsen
// 4/4/2017

/*
Program Description:
    This is a debugged number summing program.
    
Pseudocode:
    1. First correct any style that makes it harder to read.
    2. Then, rubber duck debug through individual lines of the program.
    3. Run and look for other errors.
    4. For errors in syntax: go to the line referenced by the error output.
    5. For errors in logic: find the source of the error. If necessary, isolate specific parts of the program using comment blocks.
*/

/***************************************************
Sum of numbers 
Write a program that reads in positive integers from the user, each separated by a space, and the whole terminated by a negative number
(e.g. 3 22 10 -2), and outputs the sum of the numbers entered (notincluding the terminated negative number!).
***************************************************/

#include <iostream>
using namespace std; 

//Here is the write-up for the discussion of debugging the program below.
void DebugWriteup() {
    cout << endl;
    cout << "Here was my process for the debugging of the program: " << endl;
    cout << "   1. First correct any style that makes it harder to read." << endl;
    cout << "   2. Then, rubber duck debug through individual lines of the program." << endl;
    cout << "   3. Run and look for other errors." << endl;
    cout << "   4. For errors in syntax: go to the line referenced by the error output." << endl;
    cout << "   5. For errors in logic: find the source of the error. If necessary, isolate specific parts of the program using comment blocks." << endl;
    cout << endl;
    cout << "So in terms of how it actually went, the inital tweaking of bad style present in the program made it much easier to notice actual" << endl;
    cout << "mistakes. At that point I looked through the program as if I was a compiler and ended up changing 'cin >> sum' to 'cin >> num'," << endl;
    cout << "preventing an infinite loop. I then ran the program, with there being no style errors, but noticing the final sum coming out to 0." << endl;
    cout << "Because of this I looked for the final value of sum, only to find that there was no final value of sum because 'num' had been written" << endl;
    cout << "instead. At this point there were no errors to the program. If necessary I planned on isolating and running specific chunks of code" << endl;
    cout << "but that was not needed. Overall I would say fixing the style (aka writing with good style to begin with) was especially helpful as well" << endl;
    cout << "as reading through the code as if I was the compiler (similar to rubber ducky debugging) were effective methods." << endl;
    cout << endl;
    cout << "Effective debugging is important for programmers because it can save a lot of time and effort, especially if done after programming" << endl;
    cout << "specific chunks of the program before the whole thing is finished." << endl;
    return;
}

int main(){
    
    // initialization
    int num = 0;
    int sum = 0;
    cout << "Enter numbers separated by spaces and terminated with a negative number." << endl; //style change
    // read first number
    cin >> num;
    while (num >= 0) {
        
        // add in to the sum
        sum = sum + num; //FIXED: num on left side changed to sum
        
        // read in next number (getting ready for next loop test)
        cin >> num; //FIXED: changed to num
    }
    
    cout << "Sum was " << sum << endl;
    
    DebugWriteup(); //Output of the debug write-up (not part of summing integer program).
    
    return 0;
}