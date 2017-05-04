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
    
    if (nameLength<10)
    {
         while (*head != '\0')
         {
                cout << *head;
                head++;
         }
     }
     else
     {
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
     }

     cout << endl;

     tail = &name[strlen(name) - 1];

     if (nameLength < 10)
     {
          while (tail != name)
          {
                 cout << *tail;
                 tail--;
          }
     }
     cout << endl;

     head = name;
     tail = &name[strlen(name) - 1];

     head++;
     tail--;

     if (*head == *tail)
     {
         cout << "It is an palindrome!" << endl;
     }
     else
     {
         cout << "It is not an palindrome" << endl;
     }

     return 0; 
}