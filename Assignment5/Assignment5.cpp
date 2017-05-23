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
When the program is finished, all information will be output to a separate character sheet. The user will enter preliminary information,
which includes information such as base stats (rolled randomly), race, and class. They will then enter further character information
that is based off of the preliminary information, such as accounting for certain features of race or class that might affect
stats. Lastly, the user will enter battle-related information, such as items and spells. This program is also going to use
separate files for storing information about races, classes, and spells, as well as general information.
The reason I am creating this program is because I am going to be guiding some players this summer through this exact same process
and if the program turns out well they could even use this instead of asking me to explain it to them. Also I'm going to need to
know all the races and classes before the summer so writing this program will force me to research them.
*/

/*
Algorithm
Step 1: Introduce player to character creation process. During ANY step of the program, the user
can type "/info" to receive the information regarding the specifics of the current step and/or more detailed information. During most
of the steps of character creation, user can input "/skip" to skip the current step. This cannot be done for stats, class, or race, and
the program will remind the user of what steps they skipped at the end of the program.

Step 2: First create he character object.

Step 3: Ability Scores rolled, stored in an array. Each array value will be 4d6 dropping the lowest value. If the sum of all the values
are too high or too low, reroll them again. If the sum is within a certain range, display the stats in order from highest to lowest. These
will be allocated later.

Step 4: Player selects a race for the character, and base speed is set as well. Pertinent Race information is included in file used for final
output.

Step 5: Player decides a class for the character. Each class will have a primary stat, hit die, saving throw proficiencies, and armor and
weapons proficiencies. Each class starts with features at level one and will gain access to more as they level up. Write down the character’s
level one class features under the features section of the character sheet. Also write down your proficiency bonus.

Step 6: User now gets to input name and alignment.

Step 7: User is prompted they are to create their background and submit it as a file to the program, with an example background listed in the
program folder. Any features, traits, bonds, ideals, flaws, proficiencies, etc that are a result of the background should be included in the file.

Step 8: User gets to assign ability scores now. Within the base class sit 6 variables for str, dex, con, int, wis, and cha, and user lists
which stats they want to be their highest, and which to be lowest. Add/lower any stats that are affected by racial modifiers. (Also make
sure ability modifer get functions are in place.)

Step 9: Functions for saving throws. User will enter skills.

Step 10: Set Initiative and Passive Wisdom

Steo 11: Set hit points - hit die plus constitution modifier

Step 12: Set languages.

Step 13: Choose equipment (from pre-determined set)

Step 14: Determine Armor Class.

Step 15: Set/Choose Weapons/Spells

Step 16: User is done - Output to character sheet

Pseudocode:
Class
    private
        All character attributes, including race, class, name, alignment, stats, and more.
    public
        Constructor sets all attributes to zero, except proficiency
        Get/Set functions for attributes
        Get functions for more attributes, including proficiency modifiers
Print Info from file function
Main
    Initialize any variables that will be used to execute the program
    Initialize any variables that are used to indicate what has been skipped
    Initialize any variables that are pertinent to the character
    Output beginning of program
    Create Character Object
    Roll Ability Scores
        For loop with four different random numbers that change each iteration - set to values in the array
    Select Race (Get info from external file) Set speed
    Select Class (Get info from external file) Set features
    Select name & alignment
    User inputs file containing background
    Assign ability scores (in order of highest to lowest) assigned to class
    Select skills (function in class determining number and variety of skills)
    Select languages (function in class determining number and variety of languages)
    Choose equipment (& determine AC) & weapons
    If user is a spellcaster select skills (from external file)
    Output to character sheet
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 6; //Number of stats

//Class
class Character {
    
    //All character attributes, including race, class, name, alignment, stats, and more.
    private:
        
        string race_;
        string class_;
        int speed_;
        int proficiency_;
        string name_;
        string alignment_;
        string background_;
        string skills_;
        string languages_;
        double wealth_;
        string armor_;
        bool shield_; //They do or don't have a shield, hence the boolean
        string weapon_;
        string equipment_;
        string cantrips_;
        string spells_;
        int str_;
        int dex_;
        int con_;
        int int_;
        int wis_;
        int cha_;
        
    public:
        
        void SetRaceAndSpeed(string race, string subRace) { //These are set simultaneously. Input: race, subrace; Output: nothing
            if (subRace != "N/A") { //Race is set as subrace if one exists
                race_ = subRace;
            }
            else {
                race_ = race;
            }
            if (race == "Dwarf" || race == "Halfling" || race == "Gnome") { //Smaller races have lower speed
                speed_ = 25;
            }
            else if (subRace == "High Elf" || subRace == "Drow" || race == "Human" || race == "Dragonborn" || race == "Half-Elf" || race == "Half-Orc" || race == "Tiefling") {
                speed_ = 30;
            }
            else if (subRace == "Wood Elf") { //Wood Elves get higher speed
                speed_ = 35;
            }
        }
        string GetRace() { //Input: nothing; Output: speed
            return race_;
        }
        int GetSpeed() { //Input: nothing; Output: speed
            return speed_;
        }
        
        string GetRaceFeatures() { //Input: nothing; Output: features. Race Features that can be accountaed for by the program are not always completely accoutned for
            string features = "N/A";
            if (race_ == "Hill Dwarf" || race_ == "Mountain Dwarf") {
                features = "Darkvision, Dwarven Resilience, Dwarven Combat Training, Tool Proficiency, Stonecunning";
                if (race_ == "Hill Dwarf") {
                    features = features + ", Dwarven Toughness";
                }
                else if (race_ == "Mountain Dwarf") {
                    features = features + ", Dwarven Armor Training";
                }
            }
            else if (race_ == "High Elf" || race_ == "Wood Elf" || race_ == "Drow") {
                features = "Darkvision, Keen Senses, Fey Ancestry, Trance";
                if (race_ == "High Elf") {
                    features = features + ", Elf Weapon Training, Cantrip, Extra Language";
                }
                else if (race_ == "Wood Elf") {
                    features = features + ", Elf Weapon Training, Fleet of Foot, Mask of the Wild";
                }
                else if (race_ == "Drow") {
                    features = features + ", Superior Darkvision, Sunlight Sensitivity, Drow Magic, Drow Weapon Training";
                }
            }
            else if (race_ == "Lightfoot Halfling" || race_ == "Stout Halfling") {
                features = "Lucky, Brave, Halfling Nimbleness";
                if (race_ == "Lightfoot Halfling") {
                    features = features + ", Naturally Stealthy";
                }
                else if (race_ == "Stout Halfling") {
                    features = features + ", Stout Resilience";
                }
            }
            //Humans have no special racial features
            else if (race_.find("Dragonborn") != string::npos) { //Dragonborn Base Traits are the same regardless of Ancestry
                features = "Breath Weapon, Damage Resilience";
            }
            else if (race_ == "Forest Gnome" || race_ == "Rock Gnome") {
                features = "Darkvision, Gnome Cunning";
                if (race_ == "Forest Gnome") {
                    features = features + ", Natural Illusionist, Speak with Small Beasts";
                }
                else if (race_ == "Rock Gnome") {
                    features = features + ", Artificer's Lore, Tinker";
                }
            }
            else if (race_ == "Half-Elf") {
                features = "Darkvision, Fey Ancestry, Skill Versatility";
            }
            else if (race_ == "Half-Orc") {
                features = "Darkvision, Menacing, Relentless Endurance, Savage Attacks";
            }
            else if (race_ == "Tiefling") {
                features = "Darkvision, Hellish Resistance, Infernal Legacy";
            }
            return features;
        }
        
        void SetClass(string charClass, string subClass) { //Input: class, subclass; Output: nothing
            if (subClass != "N/A") { //Class is set as subclass if one exists
                class_ = subClass;
            }
            else {
                class_ = charClass;
            }
        }
        string GetClass() { //Input: nothing; Output: class
            return class_;
        }
        
        string GetClassFeatures() { //Input: nothing; Output: features. Class Features that can be accountaed for by the program are not always completely accoutned for
            string features = "N/A";
            if (class_ == "Barbarian") {
                features = "Rage, Unarmored Defense";
            }
            else if (class_ == "Bard") {
                features = "Spellcasting, Bardic Inspiration";
            }
            else if (class_.find("Cleric") != string::npos) { //This condition indicates that "Cleric" exists somewhere in string class_. This type of condition will be used frequently.
                features = "Spellcasting";
                if (class_ == "Life Cleric") {
                    features = features + ", Disciple of Life";
                }
                else if (class_ == "Light Cleric") {
                    features = features + ", Warding Flare";
                }
                else if (class_ == "Tempest Cleric") {
                    features = features + ", Wrath of the Storm";
                }
                else if (class_ == "Trickery Cleric") {
                    features = features + ", Blessing of the Trickster";
                }
                else if (class_ == "War Cleric") {
                    features = features + ", War Priest";
                }
            }
            else if (class_ == "Druid") {
                features = "Druidic, Spellcasting";
            }
            else if (class_ == "Fighter") {
                features = "Fighting Style, Second Wind";
            }
            else if (class_ == "Monk") {
                features = "Unarmored Defense, Martial Arts";
            }
            else if (class_ == "Paladin") {
                features = "Divine Sense, Lay on Hands";
            }
            else if (class_ == "Ranger") {
                features = "Favored Enemy, Natural Explorer";
            }
            else if (class_ == "Rogue") {
                features = "Expertise, Sneak Attack, Thieves' Cant";
            }
            else if (class_.find("Sorcerer") != string::npos) {
                features = "Spellcasting";
                if (class_.find("Draconic Bloodline") != string::npos) { //Features are not affected by Draconic Ancestry at level 1
                    features = features + ", Draconic Resilience";
                }
                else if (class_ == "Wild Magic Sorcerer") {
                    features = features + ", Wild Magic Surge, Tides of Chaos";
                }
            }
            else if (class_.find("Warlock") != string::npos) {
                features = "Pact Magic";
                if (class_.find("Archfey") != string::npos) {
                    features = features + ", Fey Presence";
                }
                else if (class_.find("Fiend") != string::npos) {
                    features = features + ", Dark One's Blessing";
                }
                else if (class_.find("Great Old One") != string::npos) {
                    features = features + ", Awakened Mind";
                }
            }
            else if (class_ == "Wizard") {
                features = "Spellcasting, Arcane Recovery";
            }
            return features;
        }
        
        int GetProficiency() { //Input: nothing; Output: proficiency
            return proficiency_; //This is set as 2 by the constructor
        }
        
        void SetNameAndAlignment(string name, string alignment) { //Input: name, alignment; Output: nothing
            name_ = name;
            alignment_ = alignment;
        }
        string GetName() { //Input: nothing; Output: name
            return name_;
        }
        string GetAlignment() { //Input: nothing; Output: alignment
            return alignment_;
        }
        
        void SetBackground(string file) { //Input: file; Output: nothing
            background_ = file;
        }
        string GetBackground() { //Input: nothing; Output: background
            return background_;
        }
        
        //STRENGTH
        void SetStr(int str) { //Input: str; Output: nothing
            if (race_ == "Mountain Dwarf" || race_.find("Dragonborn") != string::npos || race_ == "Half-Orc") {
                str_ = str + 2;
            }
            else if (race_ == "Human") {
                str_ = str + 1;
            }
            else {
                str_ = str;
            }
        }
        int GetStr() { //Input: nothing; Output: str
            return str_;
        }
        int StrMod() { //Input: nothing; Output: modifier
            if (str_ >= 10) {
                return (str_ - 10) / 2;
            }
            else if (str_ < 10) { //Negative bonus
                return (str_ - 11) / 2;
            }
        }
        void AddStr() { //Input: nothing; Output: nothing
            str_ = str_ + 1;
        }
        int StrSave() { //Input: nothing; Output: save
            if (class_ == "Barbarian" || class_ == "Fighter" || class_ == "Paladin" || class_ == "Ranger") {
                return StrMod() + GetProficiency();
            }
            else {
                return StrMod();
            }
        }
        
        //DEXTERITY
        void SetDex(int dex) { //Input: dex; Output: nothing
            if (race_ == "High Elf" || race_ == "Wood Elf" || race_ == "Drow" || race_ == "Lightfoot Halfling" || race_ == "Stout Halfling") {
                dex_ = dex + 2;
            }
            else if (race_ == "Human" || race_ == "Forest Gnome") {
                dex_ = dex + 1;
            }
            else {
                dex_ = dex;
            }
        }
        int GetDex() { //Input: nothing; Output: dex
            return dex_;
        }
        int DexMod() { //Input: nothing; Output: modifier
            if (dex_ >= 10) {
                return (dex_ - 10) / 2;
            }
            else if (dex_ < 10) { //Negative bonus
                return (dex_ - 11) / 2;
            }
        }
        void AddDex() { //Input: nothing; Output: nothing
            dex_ = dex_ + 1;
        }
        int DexSave() { //Input: nothing; Output: save
            if (class_ == "Bard" || class_ == "Monk" || class_ == "Ranger" || class_ == "Rogue") {
                return DexMod() + GetProficiency();
            }
            else {
                return DexMod();
            }
        }
        
        //CONSTITUTION
        void SetCon(int con) { //Input: con; Output: nothing
            if (race_ == "Mountain Dwarf" || race_ == "Hill Dwarf" || race_ == "Stout Halfling") {
                con_ = con + 2;
            }
            else if (race_ == "Human" || race_ == "Rock Gnome" || race_ == "Half-Orc") {
                con_ = con + 1;
            }
            else {
                con_ = con;
            }
        }
        int GetCon() { //Input: nothing; Output: con
            return con_;
        }
        int ConMod() { //Input: nothing; Output: modifier
            if (con_ >= 10) {
                return (con_ - 10) / 2;
            }
            else if (con_ < 10) { //Negative bonus
                return (con_ - 11) / 2;
            }
        }
        void AddCon() { //Input: nothing; Output: nothing
            con_ = con_ + 1;
        }
        int ConSave() { //Input: nothing; Output: save
            if (class_ == "Barbarian" || class_ == "Fighter" || class_.find("Sorcerer") != string::npos) {
                return ConMod() + GetProficiency();
            }
            else {
                return ConMod();
            }
        }
        
        //INTELLIGENCE
        void SetInt(int intel) { //Input: int; Output: nothing
            if (race_ == "Forest Gnome" || race_ == "Rock Gnome") {
                int_ = intel + 2;
            }
            else if (race_ == "High Elf" || race_ == "Human" || race_ == "Tiefling") {
                int_ = intel + 1;
            }
            else {
                int_ = intel;
            }
        }
        int GetInt() { //Input: nothing; Output: int
            return int_;
        }
        int IntMod() { //Input: nothing; Output: modifier
            if (int_ >= 10) {
                return (int_ - 10) / 2;
            }
            else if (int_ < 10) { //Negative bonus
                return (int_ - 11) / 2;
            }
        }
        void AddInt() { //Input: nothing; Output: nothing
            int_ = int_ + 1;
        }
        int IntSave() { //Input: nothing; Output: save
            if (class_ == "Druid" || class_ == "Rogue" || class_.find("Warlock") != string::npos) {
                return IntMod() + GetProficiency();
            }
            else {
                return IntMod();
            }
        }
        
        //WISDOM
        void SetWis(int wis) { //Input: wis; Output: nothing
            if (race_ == "Hill Dwarf" || race_ == "Wood Elf" || race_ == "Human") {
                wis_ = wis + 1;
            }
            else {
                wis_ = wis;
            }
        }
        int GetWis() { //Input: nothing; Output: wis
            return wis_;
        }
        int WisMod() { //Input: nothing; Output: modifier
            if (wis_ >= 10) {
                return (wis_ - 10) / 2;
            }
            else if (wis_ < 10) { //Negative bonus
                return (wis_ - 11) / 2;
            }
        }
        void AddWis() { //Input: nothing; Output: nothing
            wis_ = wis_ + 1;
        }
        int WisSave() { //Input: nothing; Output: save
            if (class_ == "Druid" || class_.find("Cleric") != string::npos || class_ == "Monk" || class_.find("Warlock") != string::npos || class_ == "Wizard") {
                return WisMod() + GetProficiency();
            }
            else {
                return WisMod();
            }
        }
        
        //CHARISMA
        void SetCha(int cha) { //Input: cha; Output: nothing
            if (race_ == "Half-Elf" || race_ == "Tiefling") {
                cha_ = cha + 2;
            }
            else if (race_ == "Drow" || race_ == "Lightfoot Halfling" || race_ == "Human" || race_.find("Dragonborn") != string::npos) {
                cha_ = cha + 1;
            }
            else {
                cha_ = cha;
            }
        }
        int GetCha() { //Input: nothing; Output: cha
            return cha_;
        }
        int ChaMod() { //Input: nothing; Output: modifier
            if (cha_ >= 10) {
                return (cha_ - 10) / 2;
            }
            else if (cha_ < 10) { //Negative bonus
                return (cha_ - 11) / 2;
            }
        }
        void AddCha() { //Input: nothing; Output: nothing
            cha_ = cha_ + 1;
        }
        int ChaSave() { //Input: nothing; Output: save
            if (class_ == "Bard" || class_.find("Cleric") != string::npos || class_ == "Paladin" || class_.find("Sorcerer") != string::npos || class_.find("Warlock") != string::npos) {
                return ChaMod() + GetProficiency();
            }
            else {
                return ChaMod();
            }
        }
        
        int DetermineNumSkills() { //Input: nothing; Output: num skills
            int numSkills = 2; //All backgrounds grant two skills to a character
            if (race_ == "Elf" || race_ == "Half-Orc") {
                numSkills = numSkills + 1;
            }
            else if (race_ == "Half-Elf") {
                numSkills = numSkills + 2;
            }
            if (class_ == "Barbarian" || class_.find("Cleric") != string::npos || class_ == "Druid" || class_ == "Fighter" || class_ == "Monk" || class_ == "Paladin" || class_.find("Sorcerer") != string::npos || class_.find("Warlock") != string::npos || class_ == "Wizard") {
                numSkills = numSkills + 2;
                if (class_ == "Knowledge Cleric" || class_ == "Nature Cleric") {
                    numSkills = numSkills + 2;
                }
            }
            else if (class_ == "Bard" || class_ == "Ranger") {
                numSkills = numSkills + 3;
            }
            else if (class_ == "Rogue") {
                numSkills = numSkills + 4;
            }
            return numSkills;
        }
        void SetSkills(string skills) { //Input: skills; Output: nothing
            skills_ = skills;
        }
        string GetSkills() { //Input: nothing; Output: skills
            return skills_;
        }
        
        int GetInitiative() { //Input: nothing; Output: proficiency
            return DexMod();
        }
        
        int GetPassivePerception() { //Input: nothing; Output: passive perception
            return 10 + WisMod();
        }
        
        int GetHitDie() { //Input: nothing; Output: hit die
            int die;
            if (class_ == "Barbarian") {
                die = 12;
            }
            else if (class_ == "Fighter" || class_ == "Paladin" || class_ == "Ranger") {
                die = 10;
            }
            else if (class_ == "Bard" || class_.find("Cleric") != string::npos || class_ == "Druid" || class_ == "Monk" || class_ == "Rogue" || class_.find("Warlock") != string::npos) {
                die = 8;
            }
            else if (class_.find("Sorcerer") != string::npos || class_ == "Wizard") {
                die = 6;
            }
            return die;
        }
        
        int GetHP() { //Input: nothing; Output: Max HP
            int hp = GetHitDie() + ConMod();
            if (race_ == "Hill Dwarf" || race_.find("Dragonborn") != string::npos) {
                hp = hp + 1;
            }
            if (class_.find("Draconic Sorcerer") != string::npos && race_.find("Dragonborn") == string::npos) { //Dragonborn who are Draconic Sorcerers don't benefit from extra hp.
                hp = hp + 1;
            }
            return hp;
        }
        
        void SetLanguages() { //Input: nothing; Output: nothing. Base languages determined by race
            languages_ = "Common"; //All races know common
            if (race_ == "Hill Dwarf" || race_ == "Mountain Dwarf") {
                languages_ = languages_ + ", Dwarvish";
            }
            if (race_ == "High Elf" || race_ == "Wood Elf" || race_ == "Drow" || race_ == "Half-Elf") {
                languages_ = languages_ + ", Elvish";
            }
            if (race_ == "Forest Gnome" || race_ == "Rock Gnome") {
                languages_ = languages_ + ", Gnomish";
            }
            if (race_ == "Lightfoot Halfling" || race_ == "Stout Halfling") {
                languages_ = languages_ + ", Halfling";
            }
            if (race_ == "Half-Orc") {
                languages_ = languages_ + ", Orc";
            }
            if (race_.find("Dragonborn") != string::npos || class_.find("Draconic Sorcerer") != string::npos) {
                languages_ = languages_ + ", Draconic";
            }
            if (race_ == "Tiefling") {
                languages_ = languages_ + ", Infernal";
            }
        }
        void AddLanguage(string language) { //Input: language; Output: nothing
            languages_ = languages_ + ", " + language;
        }
        string GetLanguages() { //Input: nothing; Output: languages
            return languages_;
        }
        
        void SetWealth() { //Input: nothing; Output: nothing. Base Wealth set randomly by class
            int randomNum;
            if (class_ == "Bard" || class_.find("Cleric") != string::npos || class_ == "Fighter" || class_ == "Paladin" || class_ == "Ranger") {
                for (int i = 0; i < 5; i++) {
                    srand(time(0)); //This sets random number to a seed based on the current time
                    int randomNum = (rand() % 4) + 1; //% 5 sets random number range 0-4. +1 changes it to 1-5
                    wealth_ = wealth_ + randomNum;
                }
                wealth_ = wealth_ * 10; //Multiplier
            }
            if (class_ == "Rogue" || class_.find("Warlock") != string::npos || class_ == "Wizard") {
                for (int i = 0; i < 4; i++) {
                    srand(time(0)); //This sets random number to a seed based on the current time
                    int randomNum = (rand() % 4) + 1; //% 4 sets random number range 0-3. +1 changes it to 1-4
                    wealth_ = wealth_ + randomNum;
                }
                wealth_ = wealth_ * 10;
            }
            if (class_.find("Sorcerer") != string::npos) {
                for (int i = 0; i < 3; i++) {
                    srand(time(0)); //This sets random number to a seed based on the current time
                    int randomNum = (rand() % 4) + 1; //% 3 sets random number range 0-2. +1 changes it to 1-3
                    wealth_ = wealth_ + randomNum;
                }
                wealth_ = wealth_ * 10;
            }
            if (class_ == "Barbarian" || class_ == "Druid") {
                for (int i = 0; i < 2; i++) {
                    srand(time(0)); //This sets random number to a seed based on the current time
                    int randomNum = (rand() % 4) + 1; //% 2 sets random number range 0-1. +1 changes it to 1-2
                    wealth_ = wealth_ + randomNum;
                }
                wealth_ = wealth_ * 10;
            }
            if (class_ == "Monk") { //No multiplier
                for (int i = 0; i < 5; i++) {
                    srand(time(0)); //This sets random number to a seed based on the current time
                    int randomNum = (rand() % 4) + 1; //% 4 sets random number range 0-3. +1 changes it to 1-4
                    wealth_ = wealth_ + randomNum;
                }
            }
        }
        int GetWealth() { //Input: nothing; Output: wealth
            return wealth_;
        }
        
        void AddShield() { //Input: nothing; Output: nothing
            shield_ = true;
            wealth_ = wealth_ - 10;
        }
        string GetShield() { //Input: nothing; Output: shield
            if (shield_ == true) {
                return ", shield";
            }
            else {
                return "";
            }
        }
        void SetArmor(string armor) { //Input: armor; Output: nothing
            armor_ = armor; //This is all the armor setting is. The rest is subtracting wealth:
            if (armor == "Padded") {
                wealth_ = wealth_ - 5;
            }
            else if (armor == "Leather" || armor == "Hide") {
                wealth_ = wealth_ - 10;
            }
            else if (armor == "Ring Mail") {
                wealth_ = wealth_ - 30;
            }
            else if (armor == "Studded Leather") {
                wealth_ = wealth_ - 45;
            }
            else if (armor == "Chain Shirt" || armor == "Scale Mail") {
                wealth_ = wealth_ - 50;
            }
            else if (armor == "Chain Mail") {
                wealth_ = wealth_ - 75;
            }
            else if (armor == "Splint") {
                wealth_ = wealth_ - 200;
            }
        }
        string GetArmor() { //Input: nothing; Output: armor
            return armor_;
        }
        int GetAC() { //Input: nothing; Output: AC
            int AC = 0;
            if (armor_ == "None") {
                AC = 10 + DexMod();
            }
            else if (armor_ == "Padded" || armor_ ==  "Leather") {
                AC = 11 + DexMod();
            }
            else if (armor_ == "Studded Leather") {
                AC = 12 + DexMod();
            }
            else if (armor_ == "Hide") {
                if (DexMod() > 2) {
                    AC = 14;
                }
                else {
                    AC = 12 + DexMod();
                }
            }
            else if (armor_ == "Chain Shirt") {
                if (DexMod() > 2) {
                    AC = 15;
                }
                else {
                    AC = 13 + DexMod();
                }
            }
            else if (armor_ == "Scale Mail") {
                if (DexMod() > 2) {
                    AC = 15;
                }
                else {
                    AC = 13 + DexMod();
                }
            }
            else if (armor_ == "Ring Mail") {
                AC = 14;
            }
            else if (armor_ == "Chain Mail") {
                AC = 16;
            }
            else if (armor_ == "Splint") {
                AC = 17;
            }
            if (shield_ == true && AC != 0) {
                AC = AC + 2;
            }
            if (armor_ == "None" && shield_ == false && class_ == "Monk") { //Accounting for Unarmored Defense
                AC = 10 + DexMod() + WisMod();
            }
            return AC;
        }
        
        void SetWeapon(string weapon) { //Input: weapon; Output: nothing
            weapon_ = weapon;
            if (weapon == "Dart") {
                wealth_ = wealth_ - 0.05;
            }
            else if (weapon == "Club" || weapon == "Sling") {
                wealth_ = wealth_ - 0.1;
            }
            else if (weapon == "Greatclub" || weapon == "Quarterstaff") {
                wealth_ = wealth_ - 0.2;
            }
            else if (weapon == "Javelin") {
                wealth_ = wealth_ - 0.5;
            }
            else if (weapon == "Sickle" || weapon == "Spear" || weapon == "Net") {
                wealth_ = wealth_ - 1;
            }
            else if (weapon == "Dagger" || weapon == "Light Hammer" || weapon == "Whip") {
                wealth_ = wealth_ - 2;
            }
            else if (weapon == "Handaxe" || weapon == "Mace" || weapon == "Pike" || weapon == "Trident" || weapon == "War Pick") {
                wealth_ = wealth_ - 5;
            }
            else if (weapon == "Battleaxe" || weapon == "Flail" || weapon == "Lance" || weapon == "Shortsword" || weapon == "Blowgun") {
                wealth_ = wealth_ - 10;
            }
            else if (weapon == "Morningstar" || weapon == "Warhammer") {
                wealth_ = wealth_ - 15;
            }
            else if (weapon == "Glaive" || weapon == "Halberd") {
                wealth_ = wealth_ - 20;
            }
            else if (weapon == "Crossbow, Light" || weapon == "Shortbow" || weapon == "Rapier" || weapon == "Scimitar") {
                wealth_ = wealth_ - 25;
            }
            else if (weapon == "Greataxe") {
                wealth_ = wealth_ - 30;
            }
            else if (weapon == "Greatsword" || weapon == "Crossbow, Heavy" || weapon == "Longbow") {
                wealth_ = wealth_ - 50;
            }
            else if (weapon == "Crossbow, Hand") {
                wealth_ = wealth_ - 75;
            }
        }
        string GetWeapon() { //Input: nothing; Output: weapon
            return weapon_;
        }
        int GetAttackBonus() { //Input: nothing; Output: attack bonus
            int bonus = 0;
            if (class_ == "Monk" && weapon_ == "Unarmed Strike" && GetDex() >= GetStr()) {
                bonus = DexMod() + GetProficiency();
            }
            else if (weapon_ == "Club" || weapon_ == "Greatclub" || weapon_ == "Handaxe" || weapon_ == "Javelin" || weapon_ == "Light Hammer" || weapon_ == "Mace" || weapon_ == "Quarterstaff" || weapon_ == "Sickle" || weapon_ == "Spear" || weapon_ == "Unarmed Strike" || weapon_ == "Battleaxe" || weapon_ == "Flail" || weapon_ == "Glaive" || weapon_ == "Greataxe" || weapon_ == "Greatsword" || weapon_ == "Halberd" || weapon_ == "Lance" || weapon_ == "Longsword" || weapon_ == "Maul" || weapon_ == "Morningstar" || weapon_ == "Pike" || weapon_ == "Trident" || weapon_ == "War Pick" || weapon_ == "Warhammer") {
                bonus = StrMod() + GetProficiency();
            }
            else if (weapon_ == "Crossbow, Light" || weapon_ == "Shortbow" || weapon_ == "Sling" || weapon_ == "Blowgun" || weapon_ == "Crossbow, Hand" || weapon_ == "Crossbow, Heavy" || weapon_ == "Longbow" || weapon_ == "Net") {
                bonus = DexMod() + GetProficiency();
            }
            else if (weapon_ == "Dagger" || weapon_ == "Dart" || weapon_ == "Rapier" || weapon_ == "Scimitar" || weapon_ == "Shortsword" || weapon_ == "Whip") { //Finesse wepons - Can choose dex or str
                if (GetStr() > GetDex()) {
                    bonus = StrMod() + GetProficiency();
                }
                else if (GetDex() >= GetStr()) { //If they are equal, defaults to dex because it's more likely user is choosing finesse if they have higher dex anyway
                    bonus = DexMod() + GetProficiency();
                }
            }
            return bonus;
        }
        int GetDamageDie() { //Input: nothing; Output: damage die
            int die = 0;
            if (class_ == "Monk" && weapon_ == "Unarmed Strike") {
                die = 4;
            }
            else if (weapon_ == "Unarmed Strike" || weapon_ == "Blowgun") {
                die = 1;
            }
            else if (weapon_ == "Club" || weapon_ == "Dagger" || weapon_ == "Light Hammer" || weapon_ == "Sickle" || weapon_ == "Dart" || weapon_ == "Sling" || weapon_ == "Whip") {
                die = 4;
            }
            else if (weapon_ == "Handaxe" || weapon_ == "Javelin" || weapon_ == "Mace" || weapon_ == "Quarterstaff" || weapon_ == "Spear" || weapon_ == "Shortbow" || weapon_ == "Scimitar" || weapon_ == "Shortsword" || weapon_ == "Trident" || weapon_ == "Crossbow, Hand") {
                die = 6;
            }
            else if (weapon_ == "Greatclub" || weapon_ == "Crossbow, Light" || weapon_ == "Battleaxe" || weapon_ == "Flail" || weapon_ == "Longsword" || weapon_ == "Morningstar" || weapon_ == "Rapier" || weapon_ == "War Pick" || weapon_ == "Warhammer" || weapon_ == "Longbow") {
                die = 8;
            }
            else if (weapon_ == "Glaive" || weapon_ == "Halberd" || weapon_ == "Pike" || weapon_ == "Crossbow, Heavy") {
                die = 10;
            }
            else if (weapon_ == "Greataxe" || weapon_ == "Lance") {
                die = 12;
            }
            else if (weapon_ == "Greatsword" || weapon_ == "Maul") { //Die is normally output in the form "1d(Die)". In the case of these weapons, 2d6 are usually rolled, so instead a conditional has it converted to 2d6 wherever this function is called
                die = 206;
            }
            return die;
        }
        
        void SetEquipment(string equipment) { //Input: equipment; Output: nothing
            if (equipment_ == "N/A") { //There isn't anything set to equipment
                equipment_ = equipment;
            }
            else { //Equipment is being added
                equipment_ = equipment_ + ", " + equipment;
            }
        }
        string GetEquipment() { //Input: nothing; Output: equipment
            return equipment_;
        }
        
        void SetCantrip(string cantrip) { //Input: cantrip; Output: nothing
            if (cantrips_ == "N/A") { //Nothing has been set to equipment
                cantrips_ = cantrip;
            }
            else { //Cantrip is being added
                cantrips_ = cantrips_ + ", " + cantrip;
            }
        }
        string GetCantrips() { //Input: nothing; Output: cantrips
            return cantrips_;
        }
        
        void SetSpell(string spell) { //Input: nothing; Output: spells
            if (spells_ == "N/A") { //Nothing has been set to spells
                spells_ = spell;
            }
            else { //spell is being added
                spells_ = spells_ + ", " + spell;
            }
        }
        string GetSpells() { //Input: nothing; Output: spells
            return spells_;
        }
        
        string GetSpellcastingAbility() { //Input: nothing; Output: ability
            string ability;
            if (class_ == "Bard" || class_.find("Sorcerer") != string::npos || class_.find("Warlock") != string::npos) {
                ability = "Charisma";
            }
            else if (class_.find("Cleric") != string::npos || class_ == "Druid") {
                ability = "Wisdom";
            }
            else if (class_ == "Wizard") {
                ability = "Intelligence";
            }
            return ability;
        }
        int GetSpellSlots() { //Input: nothing; Output: spell slots
            int spellSlots = 0;
            if (class_ == "Bard" || class_.find("Cleric") != string::npos || class_ == "Druid" || class_.find("Sorcerer") != string::npos || class_ == "Wizard") {
                spellSlots = 2;
            }
            else if (class_.find("Warlock") != string::npos) {
                spellSlots = 1;
            }
            return spellSlots;
        }
        int GetSpellAttackModifier() { //Input: nothing; Output: spell modifier
            int modifier = 0;
            if (GetSpellcastingAbility() == "Charisma") {
                modifier = ChaMod() + GetProficiency();
            }
            else if (GetSpellcastingAbility() == "Wisdom") {
                modifier = WisMod() + GetProficiency();
            }
            else if (GetSpellcastingAbility() == "Intelligence") {
                modifier = IntMod() + GetProficiency();
            }
            return modifier;
        }
        
        void OutputToCharacterSheet() { //Input: nothing; Output: nothing. This print function exists in the class to access the object functions.
            
            ofstream outFS;
            outFS.open("character_sheet.txt");
            
            outFS << "DUNGEON AND DRAGONS, 5TH EDITION CHARACTER SHEET" << endl;
            outFS << endl;
            
            outFS << " - - - - GENERAL INFO - - - - " << endl;
            outFS << "Character Name: " << GetName() << endl;
            outFS << "Alignment: " << GetAlignment() << endl;
            outFS << "Level: 1" << endl;
            outFS << "Experience Points: 0" << endl;
            outFS << "Class: " << GetClass() << endl;
            outFS << "Race: " << GetRace() << endl;
            outFS << "Background: Detailed below" << endl;
            outFS << "Player Name: - " << endl;
            outFS << endl;
            
            outFS << " - - - - STATS - - - - " << endl;
            outFS << "Strength: " << GetStr() << "  Modifier: " << StrMod() << endl;
            outFS << "Dexterity: " << GetDex() << "  Modifier: " << DexMod() << endl;
            outFS << "Constitution: " << GetCon() << "  Modifier: " << ConMod() << endl;
            outFS << "Intelligence: " << GetInt() << "  Modifier: " << IntMod() << endl;
            outFS << "Wisdom: " << GetWis() << "  Modifier: " << WisMod() << endl;
            outFS << "Charisma: " << GetCha() << "  Modifier: " << ChaMod() << endl;
            outFS << endl;
            
            outFS << " - - - - SKILLS AND SAVING THROWS - - - - " << endl;
            outFS << "Inspiration: None" << endl;
            outFS << "Proficiency Bonus: " << GetProficiency() << endl;
            outFS << "Passive Perception: " << GetPassivePerception() << endl;
            outFS << endl;
            outFS << "Str Saving Throw: " << StrSave() << endl;
            outFS << "Dex Saving Throw: " << DexSave() << endl;
            outFS << "Con Saving Throw: " << ConSave() << endl;
            outFS << "Int Saving Throw: " << IntSave() << endl;
            outFS << "Wis Saving Throw: " << WisSave() << endl;
            outFS << "Cha Saving Throw: " << ChaSave() << endl;
            outFS << endl;
            outFS << "Skills with proficiency (Make sure this matches with below data): " << GetSkills() << endl;
            if (GetSkills().find("Athletics") != string::npos) {
                outFS << "Athletics: " << StrMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Athletics: " << StrMod() << endl;
            }
            if (GetSkills().find("Acrobatics") != string::npos) {
                outFS << "Acrobatics: " << DexMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Acrobatics: " << DexMod() << endl;
            }
            if (GetSkills().find("Stealth") != string::npos) {
                outFS << "Stealth: " << DexMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Stealth: " << DexMod() << endl;
            }
            if (GetSkills().find("Sleight of Hand") != string::npos) {
                outFS << "Sleight of Hand: " << DexMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Sleight of Hand: " << DexMod() << endl;
            }
            if (GetSkills().find("Arcana") != string::npos) {
                outFS << "Arcana: " << IntMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Arcana: " << IntMod() << endl;
            }
            if (GetSkills().find("Nature") != string::npos) {
                outFS << "Nature: " << IntMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Nature: " << IntMod() << endl;
            }
            if (GetSkills().find("History") != string::npos) {
                outFS << "History: " << IntMod() + GetProficiency() << endl;
            }
            else {
                outFS << "History: " << IntMod() << endl;
            }
            if (GetSkills().find("Religion") != string::npos) {
                outFS << "Religion: " << IntMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Religion: " << IntMod() << endl;
            }
            if (GetSkills().find("Investigation") != string::npos) {
                outFS << "Investigation: " << IntMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Investigation: " << IntMod() << endl;
            }
            if (GetSkills().find("Animal Handling") != string::npos) {
                outFS << "Animal Handling: " << WisMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Animal Handling: " << WisMod() << endl;
            }
            if (GetSkills().find("Perception") != string::npos) {
                outFS << "Perception: " << WisMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Perception: " << WisMod() << endl;
            }
            if (GetSkills().find("Insight") != string::npos) {
                outFS << "Insight: " << WisMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Insight: " << WisMod() << endl;
            }
            if (GetSkills().find("Survival") != string::npos) {
                outFS << "Survival: " << WisMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Survival: " << WisMod() << endl;
            }
            if (GetSkills().find("Medicine") != string::npos) {
                outFS << "Medicine: " << WisMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Medicine: " << WisMod() << endl;
            }
            if (GetSkills().find("Deception") != string::npos) {
                outFS << "Deception: " << ChaMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Deception: " << ChaMod() << endl;
            }
            if (GetSkills().find("Performance") != string::npos) {
                outFS << "Performance: " << ChaMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Performance: " << ChaMod() << endl;
            }
            if (GetSkills().find("Intimidation") != string::npos) {
                outFS << "Intimidation: " << ChaMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Intimidation: " << ChaMod() << endl;
            }
            if (GetSkills().find("Persuasion") != string::npos) {
                outFS << "Persuasion: " << ChaMod() + GetProficiency() << endl;
            }
            else {
                outFS << "Persuasion: " << ChaMod() << endl;
            }
            outFS << endl;
            
            outFS << " - - - - COMBAT STATS - - - - " << endl;
            outFS << "Armor Class: " << GetAC() << endl;
            outFS << "Initiative: " << GetInitiative() << endl;
            outFS << "Speed: " << GetSpeed() << endl;
            outFS << "Hit Point Maximum: " << GetHP() << endl;
            outFS << "Hit Die: 1d" << GetHitDie() << endl;
            outFS << endl;
            
            outFS << " - - - - FEATURES, TRAITS, AND LANGUAGES - - - - " << endl;
            outFS << "Features: " << GetClassFeatures() << endl;
            outFS << "Traits: " << GetRaceFeatures() << endl;
            outFS << "Languages: " << GetLanguages() << endl;
            outFS << endl;
            
            outFS << " - - - - WEALTH AND EQUIPMENT - - - - " << endl;
            outFS << "Starting Wealth (Treasure): " << GetWealth() << " gp" << endl;
            outFS << "Armor: " << GetArmor() + GetShield() << endl;
            outFS << "Weapon: " << GetWeapon() << endl;
            outFS << "Atk Bonus: 1d20+" << GetAttackBonus() << endl;
            outFS << "Damage Bonus: ";
            if (GetDamageDie() == 206) {
                outFS << "2d6";
            }
            else {
                outFS << "1d" << GetDamageDie();
            }
            outFS << "+" << GetAttackBonus() - GetProficiency() << endl;
            outFS << "Other Equipment: " << GetEquipment() << endl;
            outFS << endl;
            
            if (GetClass() == "Bard" || GetClass().find("Cleric") != string::npos || GetClass() == "Druid" || GetClass().find("Sorcerer") != string::npos || GetClass().find("Warlock") != string::npos || GetClass() == "Wizard") {
                outFS << " - - - - SPELLS - - - - " << endl;
                outFS << "Cantrips: " << GetCantrips() << endl;
                outFS << "Spells: " << GetSpells() << endl;
                outFS << "Spellcasting Ability: " << GetSpellcastingAbility() << endl;
                outFS << "Spell Slots: " << GetSpellSlots() << endl;
                outFS << "Spell Save DC: " << 8 + GetSpellAttackModifier() << endl;
                outFS << "Spell Attack Modifier: " << GetSpellAttackModifier() << endl;
                outFS << endl;
            }
            
            outFS << " - - - - BACKGROUND - - - - " << endl;
            if (GetBackground() != "N/A") {
                string inputWord;
                string line;
                ifstream inFS; //Object for info file to be read
                inFS.open(GetBackground());
                stringstream lineLS; //Object for lines to be read
                
                while (!inFS.eof()) { //*/ indicates the end of part of info file to be read
                
                    lineLS.clear();
                    getline(inFS, line); //reads the file input for the whole line into a string
                    lineLS.str(line); //and the string is enterred into the stringstream object
                    
                    while (!lineLS.eof()) { //The use of reading by lines is so each return in the file can correspond to an endl in the character sheet
                        lineLS >> inputWord;
                        outFS << inputWord << " ";
                    }
                    outFS << endl;
                }
                inFS.close();
            }
            else {
                outFS << "N/A";
            }
            
            outFS.close();
        }
        
        Character() {
            race_ = "N/A";
            class_ = "N/A";
            speed_ = 0;
            proficiency_ = 2; //+2 for all characters
            name_ = "N/A";
            alignment_ = "N/A";
            background_ = "N/A";
            skills_ = "N/A";
            languages_ = "N/A";
            wealth_ = 0.00;
            armor_ = "N/A";
            shield_ = false;
            weapon_ = "N/A";
            equipment_ = "N/A";
            cantrips_ = "N/A";
            spells_ = "N/A";
            str_ = 0;
            dex_ = 0;
            con_ = 0;
            int_ = 0;
            wis_ = 0;
            cha_ = 0;
        }
};

void PrintInfo(string stopWord, string file) { //Input: stop word, file name; Output: nothing
    
    string inputWord;
    string line;
    
    ifstream infoFS; //Object for info file to be read
    stringstream lineLS; //Object for lines to be read
    infoFS.open(file);
    
    cout << endl;
    while (inputWord != stopWord) { //Skipping through file until appropriate section
        infoFS >> inputWord;
    }
    
    infoFS >> inputWord; //Go to next word (after stopWord)
    while (inputWord != "*/") { //*/ indicates the end of part of info file to be read
    
        lineLS.clear();
        getline(infoFS, line); //reads the file input for the whole line into a string
        lineLS.str(line); //and the string is enterred into the stringstream object
        
        while (!lineLS.eof()) { //The use of reading by lines is so each return in the file can correspond to an endl in the console
            lineLS >> inputWord;
            cout << inputWord << " ";
        }
        
        cout << endl;
    }
    infoFS.close();
    cout << endl;
}

/*
During ANY steps of the program, the user
can type "/info" to receive the information regarding the specifics of the current step and/or more detailed information. During most
of the steps of character creation, user can input "/skip" to skip the current step. This cannot be done for stats, class, or race, and
the program will remind the user of what steps they skipped at the end of the program.
*/
int main() {
    
    //Initialize any variables that will be used to execute the program
    string command = "/null"; //This is to be used to continue the program, get info, or skip the current step
    int sum = 0; //Used to find sum of an array
    int min = 0; //Used to find minimum value of an array
    int loopVar = 0; //Additional variable to be used in loops that can't have a reinitialized variable every iteration
    int randomNum1 = 0; //Used in rolling stats
    int randomNum2 = 0;
    int randomNum3 = 0;
    int randomNum4 = 0;
    int c = 0; //Used in Swapping
    bool swapMade = true; //Used in Swapping, set to true to start first iteration
    string stat = "N/A"; //Used in allocating stats
    string s = "N/A"; //Used in allocating stats
    bool statsGood = false; //Used to make sure stats have been allocate properly
    
    //Initialize any variables that are used to indicate what has been skipped
    bool step1 = true; //Stats
    bool step2 = true; //Name
    bool step3 = true; //Alignment
    bool step4 = true; //Background
    bool step5 = true; //Skills
    bool step6 = true; //Languages
    bool step7 = true; //Armor
    bool step8 = true; //Weapon
    bool step9 = true; //Equipment
    bool step10 = true; //Spells
    
    //Initialize any variables that are pertinent to the character. Most of these are user inputs, and all are set as "N/A" for consistency
    int baseStats[SIZE] = {15, 14, 13, 12, 10, 8}; //Initialized to standard array
    string race = "N/A";
    string subRace = "N/A";
    string charClass = "N/A";
    string subClass = "N/A";
    string name = "N/A";
    string alignment = "N/A";
    string file = "N/A"; //Used for character background
    string skills = "N/A";
    string skillsTotal = "N/A";
    string bonusLanguage = "N/A";
    string armor = "N/A";
    string weapon = "N/A";
    string equipment = "N/A";
    string cantrip = "N/A";
    string spell = "N/A";
    
    //Step 1: Introduce player to character creation process.
    //Output beginning of program
    cout << "ヽ༼ຈل͜ຈ༽ﾉ DUNGEONS AND DRAGONS 5E CHARACTER CREATORヽ༼ຈل͜ຈ༽ﾉ" << endl << endl;
    
    while (command != "/go") { //User must enter go to continue the program; this condition will appear at many points during the program
        
        cout << "Type '/info' for more information or '/go' to begin." << endl;
        cin >> command;
        
        if (command == "/info") { //This condition will likely appear at several points throughout the program
            PrintInfo("START", "info_text.txt");
        }
        else if (command != "/go") {
            cout << "Invalid. ";
        }
    }
    command = "/null";
    cout << endl;
    
    //Step 2: At this point, the character object will be created.
    //Create Character Object
    Character character;
    
    /*
    Step 3: Ability Scores rolled, stored in an array. Each array value will be 4d6 dropping the lowest value. If the sum of all the values
    are too high or too low, reroll them again. If the sum is within a certain range, display the stats in order from highest to lowest. These
    will be allocated later.
    */
    //Roll Ability Scores
    while (command != "/go" && command != "/skip") {
        
        cout << "Rolling base stats. Type '/info' for more information, '/go' to proceed, or '/skip' to skip this step." << endl;
        cin >> command;
        
        if (command == "/info") { //This loop will likely appear at several points throughout the program
            PrintInfo("STATS", "info_text.txt");
        }
        else if (command == "/skip") {
            cout << "Ok, using standard Array..." << endl;
            step1 = false; //User will be notified of their skip at end of program
        }
        else if (command != "/go") {
            cout << "Invalid. ";
        }
    }
    
    if (command != "/skip") {
        cout << "Rolling..." << endl;
        while (sum < 69 || sum > 75) { //Make sure stats aren't too high or too low
            sum = 0;
            //For loop with four different random numbers that change each iteration - set to values in the array
            for (int i = 0; i < SIZE; i++) {
                
                //Rolling 4d6, using loopVar to differentiate each roll:
                srand(time(0) + loopVar); //This sets random number to a seed based on the current time
                randomNum1 = (rand() % 6) + 1; //% 6 sets random number range 0-5. +1 changes it to 1-6
                srand(time(0) + loopVar + 1); //This sets random number to a different seed based on current time
                randomNum2 = (rand() % 6) + 1;
                srand(time(0) + loopVar + 2);
                randomNum3 = (rand() % 6) + 1;
                srand(time(0) + loopVar + 3);
                randomNum4 = (rand() % 6) + 1;
                loopVar = loopVar + 4; //This results in different random numbers every iteration
                
                //Finding minimum value:
                min = randomNum1;
                if (randomNum2 < min) {
                    min = randomNum2;
                }
                if (randomNum3 < min) {
                    min = randomNum3;
                }
                if (randomNum4 < min) {
                    min = randomNum4;
                }
                
                baseStats[i] = randomNum1 + randomNum2 + randomNum3 + randomNum4 - min; //Subtracts off minimum value
                sum = baseStats[i] + sum;
            }
        }
        
        while (swapMade) { //This loop arranges the array into descending order
            swapMade = false;
            for (int i = 0; i < SIZE - 1; i++) { //SIZE - 1 since the array value is being compared to the value in the next location
                if (baseStats[i + 1] > baseStats[i]) { //Swap is made and while loop will restart
                    c = baseStats[i];
                    baseStats[i] = baseStats[i + 1];
                    baseStats[i + 1] = c;
                    swapMade = true;
                }
            }
        }
    }
    
    cout << "Your base stats are: ";
    for (int i = 0; i < SIZE; i++) {
        cout << baseStats[i];
        if (i != SIZE - 1) {
            cout << ", ";
        }
    }
    
    command = "/null";
    cout << endl << endl;
    
    /*
    Step 4: Player selects a race for the character, and base speed is set as well. Pertinent Race information is included in file used for final
    output.
    */
    //Select Race (Get info from external file) Set speed
    cout << "List of races:" << endl;
    cout << "Dwarf" << endl;
    cout << "Elf" << endl;
    cout << "Halfling" << endl;
    cout << "Human" << endl;
    cout << "Dragonborn" << endl;
    cout << "Gnome" << endl;
    cout << "Half-Elf" << endl;
    cout << "Half-Orc" << endl;
    cout << "Tiefling" << endl;
    
    while (race != "Dwarf" && race != "Elf" && race != "Halfling" && race != "Human" && race != "Dragonborn" && race != "Gnome" && race != "Half-Elf" && race != "Half-Orc" && race != "Tiefling") { //Race must = a main race to continue

        cout << "Enter the race you would like to select or type '/info' to view race information." << endl;
        cin >> race;
        cin.ignore();
        if (race == "/info") {
            cout << "Which race would you like to know more about? (or /info again for general information)" << endl;
            cin >> race;
            if (race == "/info") {
                PrintInfo("RACES", "info_text.txt");
            }
            else if (race != "Dwarf" && race != "Elf" && race != "Halfling" && race != "Human" && race != "Dragonborn" && race != "Gnome" && race != "Half-Elf" && race != "Half-Orc" && race != "Tiefling") {
                cout << "Invalid (names are case sensitive). ";
            }
            else {
                PrintInfo(race, "race_info.txt"); //reading different file, using the race name as the stop word
                race = "N/A"; //Reset loop
            }
        }
        //Setting Dwarf subrace:
        else if (race == "Dwarf") {
            while (subRace != "Hill Dwarf" && subRace != "Mountain Dwarf") {
                cout << "Enter subrace: 'Hill Dwarf' or 'Mountain Dwarf'" << endl;
                getline(cin, subRace);
                if (subRace != "Hill Dwarf" && subRace != "Mountain Dwarf") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
        }
        //Setting Elf subrace:
        else if (race == "Elf") {
            while (subRace != "High Elf" && subRace != "Wood Elf" && subRace != "Drow") {
                cout << "Enter subrace: 'High Elf', 'Wood Elf', or 'Drow'" << endl;
                getline(cin, subRace);
                if (subRace != "High Elf" && subRace != "Wood Elf" && subRace != "Drow") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
        }
        //Setting Halfling subrace:
        else if (race == "Halfling") {
            while (subRace != "Lightfoot Halfling" && subRace != "Stout Halfling") {
                cout << "Enter subrace: 'Lightfoot Halfling' or 'Stout Halfling'" << endl;
                getline(cin, subRace);
                if (subRace != "Lightfoot Halfling" && subRace != "Stout Halfling") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
        }
        //Setting Dragonborn ancestry:
        else if (race == "Dragonborn") {
            while (subRace != "Black" && subRace != "Blue" && subRace != "Brass" && subRace != "Bronze" && subRace != "Copper" && subRace != "Gold" && subRace != "Green" && subRace != "Red" && subRace != "Silver" && subRace != "White") {
                cout << "Enter dragon ancestry: 'Black' or 'Blue' or 'Brass' or 'Bronze' or 'Copper' or 'Gold' or 'Green' or 'Red' or 'Silver' or 'White'" << endl;
                getline(cin, subRace);
                if (subRace != "Black" && subRace != "Blue" && subRace != "Brass" && subRace != "Bronze" && subRace != "Copper" && subRace != "Gold" && subRace != "Green" && subRace != "Red" && subRace != "Silver" && subRace != "White") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
            subRace = subRace + " " + race;
        }
        //Setting Gnome subrace:
        else if (race == "Gnome") {
            while (subRace != "Forest Gnome" && subRace != "Rock Gnome") {
                cout << "Enter subrace: 'Forest Gnome' or 'Rock Gnome'" << endl;
                getline(cin, subRace);
                if (subRace != "Forest Gnome" && subRace != "Rock Gnome") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
        }
        else if (race != "Human" && race != "Half-Elf" && race != "Half-Orc" && race != "Tiefling") {
            cout << "Invalid (names are case sensitive). ";
        }
    }
    
    character.SetRaceAndSpeed(race, subRace); //Speed determined from race
    cout << "Your race is " << character.GetRace() << "." << endl;
    cout << "Your racial traits are " << character.GetRaceFeatures() << "." << endl;
    cout << "Your walking speed is " << character.GetSpeed() << "." << endl << endl;
    
    /*
    Step 5: Player decides a class for the character. Each class will have a primary stat, hit die, saving throw proficiencies, and armor and
    weapons proficiencies. Each class starts with features at level one and will gain access to more as they level up. Write down the character’s
    level one class features under the features section of the character sheet. Also write down your proficiency bonus.
    */
    //Select Class (Get info from external file) Set features
    cout << "List of classes:" << endl;
    cout << "Barbarian" << endl;
    cout << "Bard" << endl;
    cout << "Cleric" << endl;
    cout << "Druid" << endl;
    cout << "Fighter" << endl;
    cout << "Monk" << endl;
    cout << "Paladin" << endl;
    cout << "Ranger" << endl;
    cout << "Rogue" << endl;
    cout << "Sorcerer" << endl;
    cout << "Warlock" << endl;
    cout << "Wizard" << endl;
    
    while (charClass != "Barbarian" && charClass != "Bard" && charClass != "Cleric" && charClass != "Druid" && charClass != "Fighter" && charClass != "Monk" && charClass != "Paladin" && charClass != "Ranger" && charClass != "Rogue" && charClass != "Sorcerer" && charClass != "Warlock" && charClass != "Wizard") { //Class must = a main class to continue

        cout << "Enter the class you would like to select or type '/info' to view class information." << endl;
        cin >> charClass;
        cin.ignore();
        if (charClass == "/info") {
            cout << "Which class would you like to know more about? (or /info again for general information)" << endl;
            getline(cin, charClass);
            if (charClass == "/info") {
                PrintInfo("CLASSES", "info_text.txt");
            }
            else if (charClass != "Barbarian" && charClass != "Bard" && charClass != "Cleric" && charClass != "Druid" && charClass != "Fighter" && charClass != "Monk" && charClass != "Paladin" && charClass != "Ranger" && charClass != "Rogue" && charClass != "Sorcerer" && charClass != "Warlock" && charClass != "Wizard") {
                cout << "Invalid (names are case sensitive). ";
            }
            else {
                PrintInfo(charClass, "class_info.txt"); //reading different file, using the class name as the stop word
                charClass = "N/A"; //Reset loop
            }
        }
        //Setting Cleric subclass:
        else if (charClass == "Cleric") {
            while (subClass != "Knowledge" && subClass != "Life" && subClass != "Light" && subClass != "Nature" && subClass != "Tempest" && subClass != "Trickery" && subClass != "War") {
                cout << "Enter Divine Domain: 'Knowledge' or 'Life' or 'Light' or 'Nature' or 'Tempest' or 'Trickery' or 'War'" << endl;
                getline(cin, subClass);
                if (subClass != "Knowledge" && subClass != "Life" && subClass != "Light" && subClass != "Nature" && subClass != "Tempest" && subClass != "Trickery" && subClass != "War") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
            subClass = subClass + " " + charClass;
        }
        //Setting Sorcerer subclass:
        else if (charClass == "Sorcerer") {
            while (subClass != "Draconic Bloodline" && subClass != "Wild Magic") {
                cout << "Enter Sorcerous Origins: 'Draconic Bloodline' or 'Wild Magic'" << endl;
                getline(cin, subClass);
                if (subClass != "Draconic Bloodline" && subClass != "Wild Magic") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
            if (subClass == "Draconic Bloodline") { //Dragon Ancestry must be set for Draconic Bloodline
                while (subClass != "Black" && subClass != "Blue" && subClass != "Brass" && subClass != "Bronze" && subClass != "Copper" && subClass != "Gold" && subClass != "Green" && subClass != "Red" && subClass != "Silver" && subClass != "White") {
                    cout << "Enter dragon ancestry: 'Black' or 'Blue' or 'Brass' or 'Bronze' or 'Copper' or 'Gold' or 'Green' or 'Red' or 'Silver' or 'White'" << endl;
                    getline(cin, subClass);
                    if (subClass != "Black" && subClass != "Blue" && subClass != "Brass" && subClass != "Bronze" && subClass != "Copper" && subClass != "Gold" && subClass != "Green" && subClass != "Red" && subClass != "Silver" && subClass != "White") {
                        cout << "Invalid (names are case sensitive). ";
                    }
                }
                subClass = subClass + " Draconic Bloodline " + charClass;
            }
            else {
                subClass = subClass + " " + charClass;
            }
        }
        //Setting Warlock subclass:
        else if (charClass == "Warlock") {
            while (subClass != "Archfey" && subClass != "The Fiend" && subClass != "The Great Old One") {
                cout << "Enter Otherworldly Patron: 'Archfey' or 'The Fiend' or 'The Great Old One'" << endl;
                getline(cin, subClass);
                if (subClass != "Archfey" && subClass != "The Fiend" && subClass != "The Great Old One") {
                    cout << "Invalid (names are case sensitive). ";
                }
            }
            subClass = charClass + " of " + subClass;
        }
        else if (charClass != "Barbarian" && charClass != "Bard" && charClass != "Druid" && charClass != "Fighter" && charClass != "Monk" && charClass != "Paladin" && charClass != "Ranger" && charClass != "Rogue" && charClass != "Wizard") {
            cout << "Invalid (names are case sensitive). ";
        }
    }
    
    //Set Class + additional Info
    character.SetClass(charClass, subClass);
    cout << "Your class is " << character.GetClass() << "." << endl;
    cout << "Your class features are: " << character.GetClassFeatures() << "." << endl;
    cout << "Your proficiency modifier is +" << character.GetProficiency() << "." << endl << endl;
    
    //Step 6: User now gets to input name and alignment.
    //Select name & alignment
    while (command != "/go" && command != "/skip") { //Name
        cout << "You are about to enter your character's name. Type '/info' for more information, '/go' to continue, or '/skip' to skip the current step." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("NAME", "info_text.txt");
        }
        else if (command != "/skip" && command != "/go") {
            cout << "Invalid (Did you mean to type '/go'?). ";
        }
    }
    
    if (command == "/skip") {
        step2 = false; //User will be reminded of the skip at end of program
        name = "N/A";
    }
    else {
        cout << "Enter your character's name:" << endl;
        cin.ignore();
        getline(cin, name); //Character name can have spaces and whatnot
    }
    
    command = "/null";
    
    while (command != "/go" && command != "/skip") { //Alignment
        cout << "You are about to enter your character's alignment. Type '/info' for more information, '/go' to continue, or '/skip' to skip the current step." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("ALIGNMENT", "info_text.txt");
        }
        else if (command != "/skip" && command != "/go") {
            cout << "Invalid (Did you mean to type '/go'?). ";
        }
    }
    
    if (command == "/skip") {
        step3 = false; //User will be reminded of the skip at end of program
        alignment = "N/A";
    }
    else {
        cout << "Enter your character's alignment:" << endl;
        cin.ignore();
        getline(cin, alignment);
    }
    
    character.SetNameAndAlignment(name, alignment);
    if (character.GetName() != "N/A") {
        cout << "Your name is " << character.GetName() << "." << endl;
    }
    if (character.GetAlignment() != "N/A") {
        cout << "Your alignment is " << character.GetAlignment() << "." << endl;
    }
    cout << endl;
    
    /*
    Step 7: User is prompted they are to create their background and submit it as a file to the program, with an example background listed in the
    program folder. Any features, traits, bonds, ideals, flaws, proficiencies, etc that are a result of the background should be included in the file.
    */
    //User inputs file containing background
    while (file == "/info" || file == "N/A") {
        cout << "Enter name of file containing background text (type '/info' for more information or '/skip' to use sample background)." << endl;
        cin >> file;
        if (file == "/info") {
            PrintInfo("BACKGROUND", "info_text.txt");
        }
        else if (file == "/skip") {
            step4 = false;
        }
        else {
            cout << "Checking file..." << endl;
            ifstream FSin;
            FSin.open(file);
            if (FSin.good() == true) {
                cout << "File accepted." << endl;
            }
            else {
                cout << "Invalid file name. ";
                file = "N/A";
            }
            FSin.close();
        }
    }
    
    if (step4 == false) {
        file = "N/A";
    }
    
    character.SetBackground(file);
    command = "/null";
    cout << endl;
    
    /*
    Step 8: User gets to assign ability scores now. Within the base class sit 6 variables for str, dex, con, int, wis, and cha, and user lists
    which stats they want to be their highest, and which to be lowest. Add/lower any stats that are affected by racial modifiers. (Also make
    sure ability modifer get functions are in place.)
    */
    //Assign ability scores (in order of highest to lowest) assigned to class
    while (command != "/go") {
        cout << "Now that you know what you are doing (or not?), it's time to allocate stats. Type '/go' to proceed, or '/info' for more info." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("ALLOCATION", "info_text.txt");
        }
        else if (command != "/go") {
            cout << "Invalid. ";
        }
    }
    
    cout << "Rank in order how you want your stats to be allocated from highest to lowest." << endl;
    cout << "str, dex, con, int, wis, cha" << endl;
    while (statsGood == false) {
        for (int i = 0; i < SIZE; i++) {
            while (stat != "str" && stat != "dex" && stat != "con" && stat != "int" && stat != "wis" && stat != "cha") {
                cout << "Input your rank " << i + 1 << " stat. This stat will be assigned with base value " << baseStats[i] << "." << endl;
                cin >> stat;
                if (stat == "str") {
                    character.SetStr(baseStats[i]);
                }
                else if (stat == "dex") {
                    character.SetDex(baseStats[i]);
                }
                else if (stat == "con") {
                    character.SetCon(baseStats[i]);
                }
                else if (stat == "int") {
                    character.SetInt(baseStats[i]);
                }
                else if (stat == "wis") {
                    character.SetWis(baseStats[i]);
                }
                else if (stat == "cha") {
                    character.SetCha(baseStats[i]);
                }
                else {
                    cout << "Invalid. Stats are str, dex, con, int, wis, cha. ";
                }
            }
            stat = "N/A";
        }
        if (character.GetStr() != 0 && character.GetDex() != 0 && character.GetCon() != 0 && character.GetInt() != 0 && character.GetWis() != 0 && character.GetCha() != 0) {
            statsGood = true;
        }
        else {
            cout << "Invalid, it seems like you tried to input something twice, so now you'll have to redo this part." << endl;
        }
    }
    
    statsGood = false;

    if (character.GetRace() == "Half-Elf") {
        cout << "You are a Half-Elf, so you get to choose two stats of your own volition to add bonuses to." << endl;
        cout << "Enter two of: str, dex, con, int, wis (you already get bonuses to Charisma!)" << endl;
        for (int i = 0; i < 2; i++) {
            stat = "N/A";
            while (stat != "str" && stat != "dex" && stat != "con" && stat != "int" && stat != "wis") {
                cout << "Enter stat:" << endl;
                cin >> stat;
                if (stat == "str" && s != stat) { //s is used to keep user from adding both bonuses to same stat
                    character.AddStr();
                    s = stat;
                }
                else if (stat == "dex" && s != stat) {
                    character.AddDex();
                    s = stat;
                }
                else if (stat == "con" && s != stat) {
                    character.AddCon();
                    s = stat;
                }
                else if (stat == "int" && s != stat) {
                    character.AddInt();
                    s = stat;
                }
                else if (stat == "wis" && s != stat) {
                    character.AddWis();
                    s = stat;
                }
                else {
                    cout << "Invalid. Stats are str, dex, con, int, wis. Do not input same stat twice. ";
                    stat = "N/A";
                }
            }
        }
    }
    
    cout << "Str: " << character.GetStr() << "  Str modifier: " << character.StrMod() << "  Str saving throw: " << character.StrSave() << endl;
    cout << "Dex: " << character.GetDex() << "  Dex modifier: " << character.DexMod() << "  Dex saving throw: " << character.DexSave() << endl;
    cout << "Con: " << character.GetCon() << "  Con modifier: " << character.ConMod() << "  Con saving throw: " << character.ConSave() << endl;
    cout << "Int: " << character.GetInt() << "  Int modifier: " << character.IntMod() << "  Int saving throw: " << character.IntSave() << endl;
    cout << "Wis: " << character.GetWis() << "  Wis modifier: " << character.WisMod() << "  Wis saving throw: " << character.WisSave() << endl;
    cout << "Cha: " << character.GetCha() << "  Cha modifier: " << character.ChaMod() << "  Cha saving throw: " << character.ChaSave() << endl << endl;
    command = "/null";
    
    //Step 9: Functions for saving throws. User will enter skills.
    //Select skills (function in class determining number and variety of skills)
    //Saves called up above
    while (command != "/go" && command != "/skip") {
        cout << "It's time to select skills. Enter '/go' to proceed, '/info' for more information, or '/skip' to skip this step." << endl;
        cout << "IMPORTANT: If you don't know the skills, '/info' brings up the list." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("SKILLS", "info_text.txt");
        }
        else if (command != "/go" && command != "/skip") {
            cout << "Invalid. ";
        }
    }
    
    if (command != "/skip") {
        cout << "You have access to " << character.DetermineNumSkills() << " skills. ";
        cin.ignore();
        for (int i = 0; i < character.DetermineNumSkills(); i++) {
            cout << "Skill " << i + 1 << ":" << endl;
            getline(cin, skills);
            if (i == 0) {
                skillsTotal = skills;
            }
            else {
                skillsTotal = skillsTotal + ", " + skills;
            }
        }
        character.SetSkills(skillsTotal);
        cout << "Your skills are: " << character.GetSkills() << endl;
    }
    else {
        step5 = false;
    }
    cout << endl;
    
    //Step 10: Set Initiative and Passive Perception
    cout << "Setting Initiative and Passive Perception..." << endl;
    cout << "Initiative is " << character.GetInitiative() << endl;
    cout << "Passive Perception is " << character.GetPassivePerception() << endl << endl;
    
    //Step 11: Set hit points - hit die plus constitution modifier
    cout << "Setting Hit Point Maximum..." << endl;
    cout << "Max HP is " << character.GetHP() << endl << endl;
    command = "/null";
    
    //Step 12: Set languages.
    //Select languages (function in class determining number and variety of languages)
    while (command != "/go" && command != "/skip") {
        cout << "It's time to set languages. Enter '/go' to proceed, '/info' for more information, or '/skip' to skip this step." << endl;
        cout << "IMPORTANT: If you don't know the languages, '/info' brings up the list (not all races/classes will need to select anything though)." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("LANGUAGES", "info_text.txt");
        }
        else if (command != "/go" && command != "/skip") {
            cout << "Invalid. ";
        }
    }
    
    if (command != "/skip") {
        character.SetLanguages();
        if (character.GetRace() == "High Elf" || character.GetRace() == "Human" || character.GetRace() == "Half-Elf") {
            cout << "Due to your race, select a bonus language that isn't one of these: " << character.GetLanguages() << endl;
            cin >> bonusLanguage;
            character.AddLanguage(bonusLanguage);
        }
        if (character.GetClass() == "Ranger") {
            cout << "Due to your class, select a bonus language that isn't one of these: " << character.GetLanguages() << endl;
            cin >> bonusLanguage;
            character.AddLanguage(bonusLanguage);
        }
        else if (character.GetClass() == "Knowledge Cleric") {
            cout << "Due to your class, select a bonus language that isn't one of these: " << character.GetLanguages() << endl;
            cin >> bonusLanguage;
            character.AddLanguage(bonusLanguage);
            cout << "Select another one (You get 2): " << character.GetLanguages() << "." << endl;
            cin >> bonusLanguage;
            character.AddLanguage(bonusLanguage);
        }
        cout << "Your languages are: " << character.GetLanguages() << endl;
    }
    else {
        step6 = false;
    }
    cout << endl;
    
    //Step 13: Set Equipment (Output options as listed in class sheet)
    //Choose equipment (& determine AC) & weapons
    cout << "Setting initial wealth (Used for buying weapons/equipment)" << endl;
    character.SetWealth();
    cout << "Your starting wealth is " << character.GetWealth() << " gp." << endl;
    command = "/null";
    
    //Step 14: Determine Armor Class.
    while (command != "/go" && command != "/skip") {
        cout << "It's time to select armor. Enter '/go' to proceed, '/info' for more information, or '/skip' to skip this step." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("ARMOR", "info_text.txt");
        }
        else if (command != "/go" && command != "/skip") {
            cout << "Invalid. ";
        }
    }
    
    if (command != "/skip") {
        cout << "Welcome to the armor shop. Select your choice:" << endl;
        cout << "              Armor           - Cost   - Armor Class (AC)" << endl;
        cout << "              ____________________________________________" << endl;
        cout << "              None            - 0 gp   - 10 + Dex modifier" << endl;
        cout << "Light Armor:  Padded          - 5 gp   - 11 + Dex modifier            (Disadvantage on Stealth)" << endl;
        cout << "              Leather         - 10 gp  - 11 + Dex modifier" << endl;
        cout << "              Studded Leather - 45 gp  - 12 + Dex modifier" << endl;
        cout << "Medium Armor: Hide            - 10 gp  - 12 + Adjusted Dex modifier" << endl;
        cout << "              Chain Shirt     - 50 gp  - 13 + Adjusted Dex modifier" << endl;
        cout << "              Scale Mail      - 50 gp  - 14 + Adjusted Dex modifier   (Disadvantage on Stealth)" << endl;
        cout << "Heavy Armor:  Ring Mail       - 30 gp  - 14                           (Disadvantage on Stealth)" << endl;
        cout << "              Chain Mail      - 75 gp  - 16                           (Disadvantage on Stealth)" << endl; //Str 13
        cout << "              Splint          - 200 gp - 17                           (Disadvantage on Stealth)" << endl; //Str 15
        cout << "Shield:       Shield          - 10 gp  - +2" << endl;
        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "Funds: " << character.GetWealth() << " gp" << endl;
        cout << "IMPORTANT: Also, please input Armor in the proper case." << endl;
        cout << "Enter desired armor: " << endl;
        cin.ignore();
        while (command != "good") {
            getline(cin, armor);
            if (armor == "Padded" && character.GetWealth() < 5) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Leather" && character.GetWealth() < 10) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Studded Leather" && character.GetWealth() < 45) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Hide" && character.GetWealth() < 10) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Chain Shirt" && character.GetWealth() < 50) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Scale Mail" && character.GetWealth() < 50) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Ring Mail" && character.GetWealth() < 30) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Chain Mail" && character.GetWealth() < 75) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Splint" && character.GetWealth() < 200) {
                cout << "Insufficient Funds. Try Again:" << endl;
            }
            else if (armor == "Shield") {
                cout << "Don't you want to buy actual armor first?" << endl;
            }
            else if (armor == "Chain Mail" && character.GetStr() < 13) {
                cout << "Chain mail requires 13 strength. Try Again:" << endl;
            }
            else if (armor == "Splint" && character.GetStr() < 15) {
                cout << "Splint requires 15 strength. Try Again:" << endl;
            }
            else {
                command = "good";
            }
        }
        while (command != "Yes" && command != "No") {
            cout << "Add a shield? (Yes or No)" << endl;
            cin >> command;
            if (command != "No" && command != "Yes") {
                cout << "Wrong. ";
            }
            else if (command == "Yes" && character.GetWealth() < 10) {
                cout << "Insufficient Funds. ";
                command = "/null";
            }
            else if (command == "Yes" && character.GetWealth() >= 10) {
                character.AddShield();
            }
        }
        character.SetArmor(armor);
        if (character.GetAC() == 0) {
            cout << "Something went wrong (You probably bought something that doesn't exist). Using Armor = 0" << endl;
            character.SetArmor("N/A");
        }
        cout << "Armor: " << character.GetArmor() << endl;
        cout << "AC: " << character.GetAC() << endl;
    }
    else {
        step7 = false;
    }
    cout << endl;
    command = "/null";
    
    //Step 15: Set/Choose Weapons
    while (command != "/go" && command != "/skip") {
        cout << "It's time to select weapons. Enter '/go' to proceed, '/info' for more information, or '/skip' to skip this step." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("WEAPONS", "info_text.txt");
        }
        else if (command != "/go" && command != "/skip") {
            cout << "Invalid. ";
        }
    }
    
    if (command != "/skip") { //I'm dead inside
        cout << "                        Name            - Cost  - Damage            - Properties" << endl;
        cout << "                        ________________________________________________________" << endl;
        cout << "Simple Melee Weapons:   Club            - 1 sp  - 1d4 bludgeoning - Light" << endl;
        cout << "                        Dagger          - 2 gp  - 1d4 piercing    - Finesse, light, thrown (range 20/60)" << endl;
        cout << "                        Greatclub       - 2 sp  - 1d8 bludgeoning - Two-handed" << endl;
        cout << "                        Handaxe         - 5 gp  - 1d6 slashing    - Light, thrown (range 20/60)" << endl;
        cout << "                        Javelin         - 5 sp  - 1d6 piercing    - Thrown (range 30/120)" << endl;
        cout << "                        Light Hammer    - 2 gp  - 1d4 bludgeoning - Light, thrown (range 20/60)" << endl;
        cout << "                        Mace            - 5 gp  - 1d6 bludgeoning" << endl;
        cout << "                        Quarterstaff    - 2 sp  - 1d6 bludgeoning - Versatile (1d8)" << endl;
        cout << "                        Sickle          - 1 gp  - 1d4 slashing    - Light" << endl;
        cout << "                        Spear           - 1 gp  - 1d6 piercing    - Thrown (range 20/60), versatile (ld8)" << endl;
        cout << "                        Unarmed Strike  - 0 gp  - 1 bludgeoning   - Simple" << endl;
        cout << "Ranged Weapons:         Crossbow, Light - 25 gp - ld8 piercing    - Ammunition (range 80/320), loading, two-handed" << endl;
        cout << "                        Dart            - 5 cp  - 1d4 piercing    - Finesse, thrown (range 20/60)" << endl;
        cout << "                        Shortbow        - 25 gp - 1d6 piercing    - Ammunition (range 80/320), two-handed" << endl;
        cout << "                        Sling           - 1 sp  - 1d4 bludgeoning - Ammunition (range 30/120)" << endl;
        cout << "Martial Melee Weapons:  Battleaxe       - 10 gp - 1d8slashing     - Versatile (ld10)" << endl;
        cout << "                        Flail           - 10 gp - 1d8 bludgeoning" << endl;
        cout << "                        Glaive          - 20 gp - 1dlO slashing   - Heavy, reach, two-handed" << endl;
        cout << "                        Greataxe        - 30 gp - 1d12 slashing   - Heavy, two-handed" << endl;
        cout << "                        Greatsword      - 50 gp - 2d6slashing     - Heavy, two-handed" << endl;
        cout << "                        Halberd         - 20 gp - 1d10 slashing   - Heavy, reach, two-handed" << endl;
        cout << "                        Lance           - 10 gp - 1d12 piercing   - Reach, special" << endl;
        cout << "                        Longsword       - 15 gp - 1d8 slashing    - Versatile (ldl0)" << endl;
        cout << "                        Maul            - 10 gp - 2d6 bludgeoning - Heavy, two-handed" << endl;
        cout << "                        Morningstar     - 15 gp - 1d8 piercing" << endl;
        cout << "                        Pike            - 5 gp  - 1d10 piercing   - Heavy, reach, two-handed" << endl;
        cout << "                        Rapier          - 25 gp - 1d8 piercing    - Finesse" << endl;
        cout << "                        Scimitar        - 25 gp - 1d6slashing     - Finesse, light" << endl;
        cout << "                        Shortsword      - 10 gp - 1d6 piercing    - Finesse, light" << endl;
        cout << "                        Trident         - 5 gp  - ld6 piercing    - Thrown (range 20/60), versatile (ld8)" << endl;
        cout << "                        War Pick        - 5 gp  - ld8 piercing" << endl;
        cout << "                        Warhammer       - 15 gp - 1d8 bludgeoning - Versatile (ld10)" << endl;
        cout << "                        Whip            - 2 gp  - 1d4slashing     - Finesse, reach" << endl;
        cout << "Martial Ranged Weapons: Blowgun         - 10 gp - 1 piercing      - Ammunition (range 25/100), loading" << endl;
        cout << "                        Crossbow, Hand  - 75 gp - 1d6 piercing    - Ammunition (range 30/120), light, loading" << endl;
        cout << "                        Crossbow, Heavy - 50 gp - 1dlO piercing   - Ammunition (range 100/400), heavy, loading, two-handed" << endl;
        cout << "                        Longbow         - 50 gp - 1d8 piercing    - Ammunition (range 150/600), heavy, two-handed" << endl;
        cout << "                        Net             - 1 gp  - N/A             - Special, thrown (range 5/15)" << endl;
        cout << "Funds: " << character.GetWealth() << " gp" << endl;
        cout << "IMPORTANT: Also, please input Armor in the proper case." << endl;
        cin.ignore();
        while (command != "good") {
            cout << "Select a weapon of choice (Monks should choose Unarmed Strike):" << endl;
            getline(cin, weapon);
            if (weapon == "Dart" && character.GetWealth() < 0.05) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Club" || weapon == "Sling") && character.GetWealth() < 0.1) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Greatclub" || weapon == "Quarterstaff") && character.GetWealth() < 0.2) {
                cout << "Insufficient Funds. ";
            }
            else if (weapon == "Javelin" && character.GetWealth() < 0.5) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Sickle" || weapon == "Spear" || weapon == "Net") && character.GetWealth() < 1) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Dagger" || weapon == "Light hammer" || weapon == "Whip") && character.GetWealth() < 2) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Handaxe" || weapon == "Mace" || weapon == "Pike" || weapon == "Trident" || weapon == "War pick") && character.GetWealth() < 5) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Battleaxe" || weapon == "Flail" || weapon == "Lance" || weapon == "Shortsword" || weapon == "Blowgun") && character.GetWealth() < 10) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Morningstar" || weapon == "Warhammer") && character.GetWealth() < 15) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Glaive" || weapon == "Halberd") && character.GetWealth() < 20) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Crossbow, light" || weapon == "Shortbow" || weapon == "Rapier" || weapon == "Scimitar") && character.GetWealth() < 25) {
                cout << "Insufficient Funds. ";
            }
            else if (weapon == "Greataxe" && character.GetWealth() < 30) {
                cout << "Insufficient Funds. ";
            }
            else if ((weapon == "Greatsword" || weapon == "Crossbow, heavy" || weapon == "Longbow") && character.GetWealth() < 50) {
                cout << "Insufficient Funds. ";
            }
            else if (weapon == "Crossbow, Hand" && character.GetWealth() < 75) {
                cout << "Insufficient Funds. ";
            }
            else {
                command = "good";
            }
        }
        character.SetWeapon(weapon);
        cout << "Weapon: " << character.GetWeapon() << endl;
        cout << "Attack: 1d20+" << character.GetAttackBonus() << endl;
        cout << "Damage: ";
        if (character.GetDamageDie() == 206) { //Check class
            cout << "2d6";
        }
        else {
            cout << "1d" << character.GetDamageDie();
        }
        cout << "+" << character.GetAttackBonus() - character.GetProficiency() << endl;
    }
    else {
        step8 = false;
    }
    cout << endl;
    
    //Other equipment
    while (command != "/go" && command != "/skip") {
        cout << "Selecting bonus equipment (don't worry, you won't have to spend money). Enter '/go' to proceed, '/info' for more information, or '/skip' to skip this step." << endl;
        cin >> command;
        if (command == "/info") {
            PrintInfo("EQUIPMENT", "info_text.txt");
        }
        else if (command != "/go" && command != "/skip") {
            cout << "Invalid. ";
        }
    }
    
    if (command != "/skip") {
        cin.ignore();
        if (character.GetClass() == "Barbarian") {
            equipment = "explorer's pack";
            character.SetEquipment(equipment);
        }
        else if (character.GetClass() == "Bard") {
            cout << "Select: diplomat's pack or explorer's pack." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
            cout << "Select: lute, or some other musical instrument." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
        }
        else if (character.GetClass().find("Cleric") != string::npos || character.GetClass() == "Paladin") {
            cout << "Select: priest's pack or explorer's pack." << endl;
            getline(cin, equipment);
            equipment = equipment + ", holy symbol";
            character.SetEquipment(equipment);
        }
        else if (character.GetClass() == "Druid") {
            equipment = "explorer's pack and druidic focus";
            character.SetEquipment(equipment);
        }
        else if (character.GetClass() == "Fighter" || character.GetClass() == "Monk" || character.GetClass() == "Ranger") {
            cout << "Select: dungeoneer's pack or explorer's pack." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
        }
        else if (character.GetClass() == "Rogue") {
            cout << "Select: burglar's pack, dungeoneer's pack, or explorer's pack." << endl;
            getline(cin, equipment);
            equipment = equipment + ", thieve's tools";
            character.SetEquipment(equipment);
        }
        else if (character.GetClass().find("Sorcerer") != string::npos) {
            cout << "Select: component pouch or arcane focus." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
            cout << "Select: dungeoneer's pack or explorer's pack." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
        }
        else if (character.GetClass().find("Warlock") != string::npos) {
            cout << "Select: component pouch or arcane focus." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
            cout << "Select: scholar's pack or explorer's pack." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
        }
        else if (character.GetClass() == "Wizard") {
            cout << "Select: component pouch or arcane focus." << endl;
            getline(cin, equipment);
            character.SetEquipment(equipment);
            cout << "Select: scholar's pack or explorer's pack." << endl;
            getline(cin, equipment);
            equipment = equipment + ", spellbook";
            character.SetEquipment(equipment);
        }
        cout << "Equipment: " << character.GetEquipment() << endl;
    }
    else {
        step9 = false;
    }
    cout << endl;
    command = "/null";
    
    //Spells
    //If user is a spellcaster select skills (from external file)
    if (character.GetClass() == "Bard" || character.GetClass().find("Cleric") != string::npos || character.GetClass() == "Druid" || character.GetClass().find("Sorcerer") != string::npos || character.GetClass().find("Warlock") != string::npos || character.GetClass() == "Wizard") {
        while (command != "/go" && command != "/skip") {
            cout << "Your character has access to spellcasting. Enter '/go' to select spells, '/info' for more information, or '/skip' to skip this step." << endl;
            cin >> command;
            if (command == "/info") {
                PrintInfo("SPELLS", "info_text.txt");
            }
            else if (command != "/go" && command != "/skip") {
                cout << "Invalid. ";
            }
        }
        
        if (command != "/skip") {
            cout << "Here is your spell list:" << endl;
            cin.ignore();
            if (character.GetClass() == "Bard") {
                PrintInfo("Bard", "spell_list.txt");
                cout << "Select 1st cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 2nd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 1st spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 2nd spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 3rd spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 4th spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
            }
            else if (character.GetClass().find("Cleric") != string::npos) {
                PrintInfo("Cleric", "spell_list.txt");
                cout << "Select 1st cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 2nd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 3rd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 1st spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                if (character.WisMod() >= 1) {
                    cout << "Select 2nd spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
                if (character.WisMod() >= 2) {
                    cout << "Select 3rd spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
                if (character.WisMod() >= 3) {
                    cout << "Select 4th spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
                if (character.WisMod() >= 4) {
                    cout << "Select 5th spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
            }
            else if (character.GetClass() == "Druid") {
                PrintInfo("Druid", "spell_list.txt");
                cout << "Select 1st cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 2nd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 1st spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                if (character.WisMod() >= 1) {
                    cout << "Select 2nd spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
                if (character.WisMod() >= 2) {
                    cout << "Select 3rd spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
                if (character.WisMod() >= 3) {
                    cout << "Select 4th spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
                if (character.WisMod() >= 4) {
                    cout << "Select 5th spell: " << endl;
                    getline(cin, spell);
                    character.SetSpell(spell);
                }
            }
            else if (character.GetClass().find("Sorcerer") != string::npos) {
                PrintInfo("Sorcerer", "spell_list.txt");
                cout << "Select 1st cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 2nd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 3rd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 4th cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 1st spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 2nd spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                
            }
            else if (character.GetClass().find("Warlock") != string::npos) {
                PrintInfo("Warlock", "spell_list.txt");
                cout << "Select 1st cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 2nd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 1st spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 2nd spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
            }
            else if (character.GetClass() == "Wizard") {
                PrintInfo("Wizard", "spell_list.txt");
                cout << "Select 1st cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 2nd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 3rd cantrip: " << endl;
                getline(cin, cantrip);
                character.SetCantrip(cantrip);
                cout << "Select 1st spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 2nd spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 3rd spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 4th spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 5th spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
                cout << "Select 6th spell: " << endl;
                getline(cin, spell);
                character.SetSpell(spell);
            }
            cout << "Cantrips: " << character.GetCantrips() << endl;
            cout << "Spells: " << character.GetSpells() << endl;
            cout << "Spellcasting Ability: " << character.GetSpellcastingAbility() << endl;
            cout << "You have " << character.GetSpellSlots() << " spells slots." << endl;
            cout << "Your spell save DC is " << 8 + character.GetSpellAttackModifier() << endl;
            cout << "Your spell ability modifier is " << character.GetSpellAttackModifier() << endl;
        }
        else {
            step10 = false;
        }
    }
    
    //Output All
    //Output to character sheet
    cout << endl << "You are all finished. Outputting to character sheet..." << endl;
    character.OutputToCharacterSheet();
    cout << "Done." << endl << endl;
    if (step1 == false || step2 == false || step3 == false || step4 == false || step5 == false || step6 == false || step7 == false || step8 == false || step9 == false || step10 == false) {
        cout << "You have skipped the following steps, be sure to address them in your character sheet:" << endl;
        if (step1 == false) {
            cout << "Rolling stats" << endl;
        }
        if (step2 == false) {
            cout << "Name" << endl;
        }
        if (step3 == false) {
            cout << "Alignment" << endl;
        }
        if (step4 == false) {
            cout << "Background" << endl;
        }
        if (step5 == false) {
            cout << "Skills" << endl;
        }
        if (step6 == false) {
            cout << "Languages" << endl;
        }
        if (step7 == false) {
            cout << "Armor" << endl;
        }
        if (step8 == false) {
            cout << "Weapon" << endl;
        }
        if (step9 == false) {
            cout << "Equipment" << endl;
        }
        if (step10 == false) {
            cout << "Spells" << endl;
        }
    }
    
    return 0;
}