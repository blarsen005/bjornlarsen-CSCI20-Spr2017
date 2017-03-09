// Bjorn Larsen
// 3/9/2017

/*
Program Description:
    This program acts as a temperature converter between Kelvin, Celsius, and Fahrenheit. It comes with predifined inputs
    that test and make use of the constructor functions as well as each of the set/get converter functions. Final output
    displays the temperature conversions for several different values. All values are stored via use of private data member
    kelvin_.
    
Pseudocode:
    1) Create class "TemperatureConverter"
    2) In private, store kelvin_
    3) In public, define functions:
        SetTempFromKelvin – accepts a kelvin value an stores it
        GetTempFromKelvin – returns the kelvin value
        SetTempFromCelsius – accepts a Celsius value and converts it to kelvin Formula: k=c + 273.15
        SetTempFromFahrenheit – accepts a Fahrenheit value and converts it to kelvin Formula: k = (5 * (f -32)/9) + 273.15
        GetTempAsCelsius – returns the Celsius temperature. Formula: k – 273.15
        GetTempAsFahrenheit – returns the Fahrenheit temperature. Formula: ((c*9)/5 + 32)
        PrintTemperatures – prints the value as kelvin, Celsius and Fahrenheit by using the other functions available.
    4) Call constructor within public.
    5) Create constructor that sets kelvin_ to 0
    6) Create a second (overloaded) constructor that includes a kelvin value as a parameter and sets it to kelvin_
    7) Paste main from the lab page.
*/

#include <iostream>
#include <string>
using namespace std;
 
 //Create class "TemperatureConverter"
 class TemperatureConverter {
     
     //In private, store kelvin_
     private:
         double kelvin_;
     
     //In public, define functions
     public:
         //SetTempFromKelvin – accepts a kelvin value an stores it
         void SetTempFromKelvin(double k) {
             kelvin_ = k;
             return;
         }
         
         //GetTempFromKelvin – returns the kelvin value
         double GetTempFromKelvin(){
             return kelvin_;
         }
         
         //SetTempFromCelsius – accepts a Celsius value and converts it to kelvin Formula: k=c + 273.15
         void SetTempFromCelsius(double c) {
             kelvin_ = c + 273.15;
             return;
         }
         
         //SetTempFromFahrenheit – accepts a Fahrenheit value and converts it to kelvin Formula: k = (5 * (f -32)/9) + 273.15
         void SetTempFromFahrenheit(double f) {
             kelvin_ = (5 * (f - 32) / 9) + 273.15;
             return;
         }
         
         //GetTempAsCelsius – returns the Celsius temperature. Formula: k – 273.15
         double GetTempAsCelsius() {
             return kelvin_ - 273.15;
         }
         
         //GetTempAsFahrenheit – returns the Fahrenheit temperature. Formula: ((c*9)/5 + 32)
         double GetTempAsFahrenheit() {
             return (9 * (kelvin_ - 273.15) / 5) + 32;
         }
         
         //PrintTemperatures – prints the value as kelvin, Celsius and Fahrenheit by using the other functions available.
         void PrintTemperatures() {
             cout << "________________________________" << endl;
             cout << "Kelvin: " << GetTempFromKelvin() << endl;
             cout << "Celsius: " << GetTempAsCelsius() << endl;
             cout << "Fahrenheit: " << GetTempAsFahrenheit() << endl;
             cout << "________________________________" << endl;
         }
         
         //Call constructor within public.
         TemperatureConverter();
         TemperatureConverter(double k);
 };
 
 //Create constructor that sets kelvin_ to 0
 TemperatureConverter::TemperatureConverter() : kelvin_(0) {
     return;
 }
 
 //Create a second (overloaded) constructor that includes a kelvin value as a parameter and sets it to kelvin_
 TemperatureConverter::TemperatureConverter(double k) : kelvin_(k) {
     return;
 }
 
 //Paste main from the lab page.
 int main ()
 {
     TemperatureConverter temp1; //testing default constructor
     TemperatureConverter temp2(274); //testing overloaded constructor
     
     temp1.PrintTemperatures();
     temp2.PrintTemperatures();
     
     temp1.SetTempFromKelvin(400.15); //testing mutator function
     cout<<temp1.GetTempFromKelvin()<<endl;//testing accessor function
     temp1.PrintTemperatures();
     
     temp2.SetTempFromCelsius(32); //testing other functions
     cout<<temp2.GetTempAsCelsius()<<endl;
     temp2.PrintTemperatures();
     
     temp2.SetTempFromFahrenheit(32);
     cout<<temp2.GetTempAsFahrenheit()<<endl;
     temp2.PrintTemperatures();
     
     return 0;
 }