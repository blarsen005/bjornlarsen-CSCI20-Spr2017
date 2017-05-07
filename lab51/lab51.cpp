// Bjorn Larsen
// 5/4/2017

//Take the following code and comment it to demonstrate that you understand what it is doing.  It has some errors, you should describe these.

#include <iostream> 
#include <iostream> //iostream has been included twice, but this is fine
#include <cstring> 
using namespace std;   

int main() {
    int nameLength = 0;
    //The pointer "name" is being initialized to point to a new location in memory that stores a character array,
    //but the array has not been given a size.
    //The next line implies the size should be set to 10.
    char * name = new char[]; 

    cout << "Please enter a 10 letter word or less" << endl;
    cin >> name; //values are added to the character array; stored in name

    char * head  = name; //head now points to name
    char * tail = name; //tail now points to name
    //This would find the length of the array points to by name, and sotre it into nameLength
    //But strlen is accessing the memory location rather than the actual value because of *, so there is an error
    nameLength = strlen(*name);

    cout << "Your word is " << firststr << endl; //ERROR: firststr is not initialized
    
    if (nameLength<10) //Condition based on prior char array size
    {
         while (*head != '\0') //When account for null terminator the size in the condition above should be 11
         {
                cout << *head; //outputs character in name, as head points to
                head++; //array value increments up (like with array[i])
         }
     }
     else
     { //Because above condition must be less than 10, a 10 letter word or higher will be too big
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
     }

     cout << endl;

     tail = &name[strlen(name) - 1]; //Associates tail with the final character of tail

     if (nameLength < 10) //Condition based on prior char array size
     {
          while (tail != name) //Runs until tail character is the same as name character
          {
                 cout << *tail; //So it will output the name backwards until the letter
                 tail--;
          }
     }
     cout << endl;

     head = name; //Resets head (full name)
     tail = &name[strlen(name) - 1]; //Resets tail (final character of name)

     head++; //Head now will point to second character first
     tail--; //Tail now will point to second to last character first

     if (*head == *tail) //second letter of name equal to second to last letter of name; logical error
     { //logical error as all the first and last part of the name would need to mirror each other, not just the second letters
         cout << "It is an palindrome!" << endl; //typo
     }
     else
     {
         cout << "It is not an palindrome" << endl; //typo
     }

     return 0; 
}