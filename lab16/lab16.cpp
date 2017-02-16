// Bjorn Larsen
// 2/16/2017

/*
This program creates a customizable monster using a struct template. User can select the monster's name,
head, eyes, ears, nose, and mouth.

Pseudocode:
    1) Create a MonsterStruct with data members Name, Head, Eyes, Ears, Nose, and Mouth.
    2) Create a struct variable for the monster.
    3) Prompt user to enter names for the monster's head, eyes, ears, nose, and mouth.
    4) Output the Monster
*/

#include <iostream>
#include <string>
using namespace std;

 struct MonsterStruct {
     
     string name  = "OneMonster"; // Monster's name is being included as a characteristic of the object.
     string head  = "head";
     string eyes  = "eyes";
     string ears  = "ears";
     string nose  = "nose";
     string mouth = "mouth";
     
 };
 
 int main () {
     
     MonsterStruct monster; // MonsterStruct template nhas now been applied to variable "monster."
     
     // User is inputting monster's name and each part of the face.
     cout << "Name:" << endl;
     cin >> monster.name;
     
     cout << "Head:" << endl;
     cin >> monster.head;
     
     cout << "Eyes:" << endl;
     cin >> monster.eyes;
     
     cout << "Ears:" << endl;
     cin >> monster.ears;
     
     cout << "Nose:" << endl;
     cin >> monster.nose;
     
     cout << "Mouth:" << endl;
     cin >> monster.mouth;
     
     // Here is the final output line of the monster and all its characteristics.
     cout << endl << monster.name << ": " << monster.head << ", " << monster.eyes << ", " << monster.ears << ", " << monster.nose << ", " << monster.mouth << endl;
     
     return 0;
     
 }