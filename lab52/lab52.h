
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber(){
   srand(time(0));
   return ((rand()% 10) + 1);
}