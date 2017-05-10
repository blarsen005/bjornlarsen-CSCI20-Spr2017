#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 *  This class is to show how to
 *  break our class into an interface and implementation
 *  file. It will set a member variable to 0 on initialization
 *  and output it using the Output() function.
 */
class MyClass {
 public:
  /*
   * Constructor
   * Initialize our member variable num_ to 0
   */
  MyClass();
  /*
   * Output our member variable using cout
   */
  void Output();
  void SetNumber(int num);
  int GetNumber();
 private:
  int num_;
};