// Bjorn Larsen
// 3/10/2017

/*
Program Description:
    Conversion program for distance. Converts pre-set values to miles, yards, feet, or inches. Uses and tests constructors
    and set/get functions in the main program.
    
Pseudocode:
    1) Create class "DistanceConverter".
    2) In private, store data in "feet_".
    3) In public, define converter functions:
        SetDistanceFromFeet - accepts a feet value and stores it.
        SetDistanceFromInches - accepts an inches value and converts it to feet.
        SetDistanceFromYards - accepts a yards value and converts it to feet.
        SetDistanceFromMiles - accepts a miles value and converts it to feet.
        GetDistanceAsFeet - returns the feet value.
        GetDistanceAsInches - returns an inches value based on feet.
        GetDistanceAsYards - returns a yards value based on feet.
        GetDistanceAsMiles - returns a miles value based on feet.
    4) Create a general print function that prints all data types for miles, yards, feet, and inches.
    5) Create 4 print functions; each of which outputs the input value in one of: miles, yards, feet, and inches.
    6) Call the constructor function and the overloaded constructor function (still in public).
    7) Create a constructor function that sets feet_ to 0.
    8) Create an overloaded constructor that includes a feet value as a parameter and sets it to feet_.
    9) In main, test constructors/create objects.
    10) Hard code, test, and print specific conversions:
        1. 1 mile to feet
        2. 1 mile to inches
        3. 1 mile to yards
        4. 1 foot to inches
        5. 16 feet to miles
        6. 20 yards to feet
        7. 100 inches to miles
        8. 1 yard to miles
*/

#include <iostream>
using namespace std;

//Create class "DistanceConverter".
class DistanceConverter { //This class is based on accepting various inputs distance values, converting to feet, and outputting as other distance values.
    
    //In private, store data in "feet_".
    private:
        double feet_;
        
    //In public, define converter functions
    public:
    /*
    These functions are the set/get functions. The set functions accept user input values and "output" them as feet in the private variable.
    The get functions accept the "input" from feet and output them as a conversion to whatever distance unit is desired.
    */
        //SetDistanceFromFeet - accepts a feet value and stores it. Input: feet Output: feet
        void SetDistanceFromFeet(double ft) {
            feet_ = ft;
            return;
        }
        
        //SetDistanceFromInches - accepts an inches value and converts it to feet. Input: inches Output: feet
        void SetDistanceFromInches(double in) {
            feet_ = in / 12;
            return;
        }
     
        //SetDistanceFromYards - accepts a yards value and converts it to feet. Input: yards Output: feet
        void SetDistanceFromYards(double yd) {
            feet_ = yd * 3;
            return;
        }
        
        //SetDistanceFromMiles - accepts a miles value and converts it to feet. Input: miles Output: feet
        void SetDistanceFromMiles(double mi) {
            feet_ = mi * 5280;
            return;
        }
        
        //GetDistanceAsFeet - returns the feet value. Input: feet Output: feet
        double GetDistanceAsFeet() {
            return feet_;
        }
        
        //GetDistanceAsInches - returns an inches value based on feet. Input: feet Output: inches
        double GetDistanceAsInches() {
            return feet_ * 12;
        }
        
        //GetDistanceAsYards - returns a yards value based on feet. Input: feet Output: yards
        double GetDistanceAsYards() {
            return feet_ / 3;
        }
        
        //GetDistanceAsMiles - returns a miles value based on feet. Input: feet Output: miles
        double GetDistanceAsMiles() {
            return feet_ / 5280;
        }
        
    //These functions call the get functions in order to output the data in an organized fashion when called in main.
        //Create a general print function that prints all data types for miles, yards, feet, and inches.
        void PrintDistances() {
            cout << "Inches: " << GetDistanceAsInches() << endl;
            cout << "Feet: " << GetDistanceAsFeet() << endl;
            cout << "Yards: " << GetDistanceAsYards() << endl;
            cout << "Miles: " << GetDistanceAsMiles() << endl;
            cout << "." << endl;
            return;
        }
        
        //Create 4 print functions; each of which outputs the input value in one of: miles, yards, feet, and inches.
        void PrintInches() {
            cout << "Inches: " << GetDistanceAsInches() << endl;
            return;
        }
        
        void PrintFeet() {
            cout << "Feet: " << GetDistanceAsFeet() << endl;
            return;
        }
        
        void PrintYards() {
            cout << "Yards: " << GetDistanceAsYards() << endl;
            return;
        }
        
        void PrintMiles() {
            cout << "Miles: " << GetDistanceAsMiles() << endl;
            return;
        }
        
    //The constructor functions here automatically set values to private data members (feet_)
        //Call the constructor function and the overloaded constructor function
        DistanceConverter();
        DistanceConverter(double ft);
};

//Create a constructor function that sets feet_ to 0.
DistanceConverter::DistanceConverter() : feet_(0) {
    return;
}

//Create an overloaded constructor that includes a feet value as a parameter and sets it to feet_.
DistanceConverter::DistanceConverter(double ft) : feet_(ft) {
    return;
}

int main() {
    
    //In main, test constructors/create objects.
    cout << "Testing Constructors:" << endl;
    
    DistanceConverter distance1; //Runs constructor
    DistanceConverter distance2(250); //Runs overloaded constructor
    
    distance1.PrintDistances();
    distance2.PrintDistances();
    
    //Hard code, test, and print specific conversions:
    //1 mile to feet
    cout << "Testing conversions: " << endl;
    
    distance1.SetDistanceFromMiles(1);
    cout << "Input: " << distance1.GetDistanceAsMiles() << endl;
    distance1.PrintFeet();
    
    //1 mile to inches
    distance1.SetDistanceFromMiles(1);
    cout << "Input: " << distance1.GetDistanceAsMiles() << endl;
    distance1.PrintInches();
    
    //1 mile to yards
    distance1.SetDistanceFromMiles(1);
    cout << "Input: " << distance1.GetDistanceAsMiles() << endl;
    distance1.PrintYards();
    
    //1 foot to inches
    distance1.SetDistanceFromFeet(1);
    cout << "Input: " << distance1.GetDistanceAsFeet() << endl;
    distance1.PrintInches();
    
    //16 feet to miles
    distance1.SetDistanceFromFeet(16);
    cout << "Input: " << distance1.GetDistanceAsFeet() << endl;
    distance1.PrintMiles();
    
    //20 yards to feet
    distance1.SetDistanceFromYards(20);
    cout << "Input: " << distance1.GetDistanceAsYards() << endl;
    distance1.PrintFeet();
    
    //100 inches to miles
    distance1.SetDistanceFromInches(100);
    cout << "Input: " << distance1.GetDistanceAsInches() << endl;
    distance1.PrintMiles();
    
    //1 yard to miles
    distance1.SetDistanceFromYards(1);
    cout << "Input: " << distance1.GetDistanceAsYards() << endl;
    distance1.PrintMiles();
    
    return 0;
}