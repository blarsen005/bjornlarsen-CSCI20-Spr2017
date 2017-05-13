// Bjorn Larsen
// 5/9/2017

/*
Problem Description:

Create a program of your choice. This should have personal meaning for you and help you understand how programming can help in your field.
Requirements

    A class
    A decision or loop (or both)
    An array or strings (or both)
    File Input/Output
    Appropriate user input/output and user error handling
*/

/*
This program will guide a user through the process of creating a character for Dungeons and Dragons 5E. It is intended
to be useful both for newbies unfamiliar to the franchise as well as for experienced players. Throughout the program, the
user will be prompted to input a large amount of information, mostly by use of the console and a bit through use of file input.
When the program is finished, all information will be output to a separate character sheet. The program will take place in terms
of three overall steps/phases. The first part will be preliminary information, which includes information such as base stats
(rolled randomly), race, and class. The second part will be further character information that is based off of the
preliminary information, such as accounting for certain features of race or class that might affect stats. The final phase
is battle-related information, such as items and spells. This program is also going to use separate files for storing information
about races and classes; their features will be output onto the character sheet, and they will affect character attributes by way
of several conditions in certain functions. The alternative would be to create a few dozen classes, which seems sub-optimal.
The reason I am creating this program is because I am going to be guiding some players this summer through this exact same process
and if the program turns out well they could even use this instead of asking me to explain it to them. Also I'm going to need to
know all the races and classes before the summer so writing this program will force me to research them.
*/

/*
Step 1: Introduce player to character creation process. During ANY step of the program, the user
can type "/info" to receive the information regarding the specifics of the current step and/or more detailed information. During most
of the steps of character creation, user can input "/skip" to skip the current step. This cannot be done for stats, class, or race, and
the program will remind the user of what steps they skipped at the end of the program.

Step 2: Ability Scores rolled, stored in an array. Each array value will be 4d6 dropping the lowest value. If the sum of all the values
are too high or too low, reroll them again. If the sum is within a certain range, display the stats in order from highest to lowest. These
will be allocated later.

Step 3: Player selects a race for the character, and base speed is set as well. Pertinent Race information is included in file used for final
output.

Step 4: Player decides a class for the character.

Step 5: At this point, the character object will be created based on race and class. The constructor will set any level one class features or
racial traits, as well as proficiency bonus. Base stats will also be added to the base class.

Step 6: User now gets to input name and alignment.

Step 7: User is prompted they are to create their background and submit it as a file to the program, with an example background listed in the
program folder. This background will not be stored in the class. Any features, traits, bonds, ideals, flaws, proficiencies, etc that are
a result of the background should be included in the file.

Phase 2:
Step 8: User gets to assign ability scores now. Within the base class sit 6 variables for str, dex, con, int, wis, and cha, and user lists
which stats they want to be their highest, and which to be lowest. Add lower any stats that are affected by racial modifiers. (Also make
sure ability modifer get functions are in place.)

Step 9: Functions for saving throws. User will enter skills.

Step 10: Set Initiative

Steo 11: Set hit points - hit die plus constitution modifier

Step 12: Set languages.

Phase 3:
Step 13: Choose equipment (from pre-determined set)

Step 14: Determine Armor Class.

Step 15: Set/Choose Weapons/Spells

Step 16: User is done - Output to character sheet
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 6; //Number of stats

class Character {
    private:
        int base_stats[6];
        string race_;
        string class_;
    public:
        Character();
        void SetStats(int stats[]);
        int GetStats();
};

void PrintInfo(string stopWord) {
    
    string inputWord;
    string line;
    
    ifstream FSinfo; //Object for info file to be read
    stringstream LSline; //Object for lines to be read
    FSinfo.open("info_text.txt");
    
    cout << endl;
    while (inputWord != stopWord) { //Skipping through file until appropriate section
        FSinfo >> inputWord;
    }
    
    FSinfo >> inputWord; //Go to next word (after stopWord)
    while (inputWord != "*/") { //*/ indicates the end of part of info file to be read
    
        LSline.clear();
        getline(FSinfo, line); //reads the file input for the whole line into a string
        LSline.str(line); //and the string is enterred into the stringstream object
        
        while (!LSline.eof()) { //The use of reading by lines is so each return in the file can correspond to an endl in the console
            LSline >> inputWord;
            cout << inputWord << " ";
        }
        
        cout << endl;
    }
    FSinfo.close();
    cout << endl;
}

/*
During ANY step of the program, the user
can type "/info" to receive the information regarding the specifics of the current step and/or more detailed information. During most
of the steps of character creation, user can input "/skip" to skip the current step. This cannot be done for stats, class, or race, and
the program will remind the user of what steps they skipped at the end of the program.
*/
int main() {
    
    //Program-related variables
    string command = "/null"; //This is to be used to continue the program, get info, or skip the current step
    
    //Character-related variables
    int baseStats[SIZE] = {15, 14, 13, 12, 10, 8}; //Initialized to standard array
    
    //Step 1: Introduce player to character creation process.
    cout << "ヽ༼ຈل͜ຈ༽ﾉ DUNGEONS AND DRAGONS 5E CHARACTER CREATORヽ༼ຈل͜ຈ༽ﾉ" << endl << endl;
    
    while (command != "/go") { //User must enter go to continue the program; this condition will appear at many points during the program
    
        cout << "Type '/info' for more information or '/go' to begin." << endl;
        cin >> command;
        
        if (command == "/info") { //This loop will likely appear at several points throughout the program
            PrintInfo("STEP1");
        }
        else if (command != "/go") {
            cout << "Invalid. ";
        }
    }
    command = "/null";
    cout << endl;
    
    /*
    Step 2: Ability Scores rolled, stored in an array. Each array value will be 4d6 dropping the lowest value. If the sum of all the values
    are too high or too low, reroll them again. If the sum is within a certain range, display the stats in order from highest to lowest. These
    will be allocated later.
    */
    while (command != "/go") {
        
        cout << "Rolling base stats. Type '/info' for more info or '/go' to proceed." << endl;
        cin >> command;
        
        if (command == "/info") { //This loop will likely appear at several points throughout the program
            PrintInfo("STEP2");
        }
        else if (command != "/go") {
            cout << "Invalid. ";
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        srand(time(0)); //This sets random number to a seed based on the current time.
        int randomNum1 = (rand() % 6) + 1; //% 6 sets random number range 0-5. +1 changes it to 1-6.
        srand(time(0) + 1); //This sets random number to a different seed based on current time
        int randomNum2 = (rand() % 6) + 1;
        srand(time(0) + 2);
        int randomNum3 = (rand() % 6) + 1;
        srand(time(0) + 3);
        int randomNum4 = (rand() % 6) + 1;
    }    
    
    
    
    return 0;
}