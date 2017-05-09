// Bjorn Larsen
// 5/7/2017

/*
To run your program you need to following commands in order:
Open a terminal from your folder (right click on your folder and open new terminal window)
g++ -Wall -g -c lab21.cpp     
This compiles the file with the main function. If you named it differently, you should change the name from lab21 to your file name
This should create a file called lab21.o
g++ -Wall -g -c MyClass.cpp
This compiles the class. If you named it differently, you should change the name from MyClass.cpp to your file name
This should create a file called MyClass.o
g++ -Wall -g -o lab21exe lab21.o MyClass.o
This compiles the two object files into an executable named lab21exe.
./lab21exe
run this to test that your program works.
*/

using namespace std;

int randomNumber();

// Program starts here
int main() {
  // Create a MyClass Object
  MyClass object;

  //Send a number to the Object
  object.SetNumber(randomNumber());

  // Call the output member function
  object.Output();

  // This ends our program
  return 0;
}