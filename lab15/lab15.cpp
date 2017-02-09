// Bjorn Larsen
// 2/9/2017

/*
This program is a "Mad Lib," a game of sorts where a user first enters words that fall within specific categories,
and then those words are added into a sentence. This creates potentially funny, often awkward, and usually ridiculous results.
This particular Mad Lib is based off of Gene Wilder's performance in Willy Wonka and the Chocolate Factory.

Mad Lib template:
    ______,(exclamation) sir! ______!(exclamation) Under section 37B of the contract signed by him, it states quite clearly that all ______(plural noun) shall
    become ______(adjective) and ______(adjective) if - and you can ______(verb) it for yourself in this ______(adjective) copy: I, the ______(adjective), shall forfeit
    all rights, privileges, and ______(plural noun) herein and herein contained, et cetera, et cetera... Fax mentis ______(funny-sounding word) gloria
    cultum, et cetera, et cetera... Memo bis punitor ______(funny-sounding word)! It's all there, black and white, ______(adjective) as _____(noun)! You stole
    fizzy lifting ______(plural noun)! You ______(past-tense verb) into the ______(part of a building or room) which now has to be washed and sterilized, so you get
    ______(noun)! You ______(verb)! Good day, sir! 
*/

 #include <iostream>
 #include <string>
 using namespace std;
 
 int main() {
     
     //Initializing all the user inputs as strings:
     string exclamation1  = "Wrong"; //The words from the original line are pre-loaded.
     string pluralNoun1   = "offers";
     string adjective1    = "null";
     string adjective2    = "void";
     string verb1         = "see";
     string adjective3    = "photostatic";
     string adjective4    = "undersigned";
     string pluralNoun2   = "licenses";
     string funnyWord1    = "incendium";
     string funnyWord2    = "delacatum";
     string adjective5    = "clear";
     string noun1         = "crystal";
     string pluralNoun3   = "drinks";
     string pastTenseVerb = "bumped";
     string partRoom      = "ceiling";
     string noun2         = "nothing";
     string verb2         = "lose";
     
     
     //Note: This section would probably have been easier if done in tandem with initializing the variables.
     cout << "Enter an exclamation:" << endl; //User inputs for each word.
     cin >> exclamation1;
     
     cout << "Enter a plural noun:" << endl;
     cin >> pluralNoun1;
     
     cout << "Enter an adjective:" << endl;
     cin >> adjective1;
     
     cout << "Enter another adjective:" << endl;
     cin >> adjective2;
     
     cout << "Enter a verb:" << endl;
     cin >> verb1;
     
     cout << "Enter a third adjective:" << endl;
     cin >> adjective3;
     
     cout << "Enter a fourth adjective:" << endl;
     cin >> adjective4;
     
     cout << "Enter another plural noun:" << endl;
     cin >> pluralNoun2;
     
     cout << "Enter a funny-sounding or made-up word:" << endl;
     cin >> funnyWord1;
     
     cout << "Enter another funny-sounding or made-up word:" << endl;
     cin >> funnyWord2;
     
     cout << "Enter a fifth adjective:" << endl;
     cin >> adjective5;
     
     cout << "Enter a noun:" << endl;
     cin >> noun1;
     
     cout << "Enter a third plural noun:" << endl;
     cin >> pluralNoun3;
     
     cout << "Enter a past-tense verb:" << endl;
     cin >> pastTenseVerb;
     
     cout << "Enter a part of a room or building:" << endl;
     cin >> partRoom;
     
     cout << "Enter another noun:" << endl;
     cin >> noun2;
     
     cout << "Enter another verb:" << endl;
     cin >> verb2;
     
     cout << endl;
     
     
     //endl used so it doesn't suck to read.
     //The final Mad Lib comes out as according to:
     
     cout << "Output:" << endl;
     
     cout << exclamation1 << ", sir! " << exclamation1 << "! Under section 37B of the contract signed by him, it states quite clearly that all " << endl
          << pluralNoun1 << " shall become " << adjective1 << " and " << adjective2 << " if - and you can " << verb1 << " it for yourself in this " << endl
          << adjective3 << " copy: I, the " << adjective4 << ", shall forfeit all rights, privileges, and " << pluralNoun2 << " herein and herein " << endl
          << "contained, et cetera, et cetera... Fax mentis " << funnyWord1 << " gloria cultum, et cetera, et cetera... Memo bis punitor " << funnyWord2 << "! " << endl
          << "It's all there, black and white, " << adjective5 << " as " << noun1 << "! You stole fizzy lifting " << pluralNoun3 << "! You " << endl
          << pastTenseVerb << " into the " << partRoom << " which now has to be washed and sterilized, so you get " << noun2 << "! You " << verb2 << "! " << endl
          << "Good day, sir!" << endl;
     
     
     return 0;
     
 }