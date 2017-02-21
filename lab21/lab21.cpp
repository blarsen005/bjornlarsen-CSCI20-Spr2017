// Bjorn Larsen
// 2/21/2017

/*
Program Description:
    This program outputs Wind Chill information based on user input values of temperature and wind speed.
    There are two formulas used to calculate wind chill: an older one and a newer one. This program outputs
    wind chill values calculated through both methods and also outputs the difference between both methods'
    values.
    
Pseudocode:
    0) Make sure to include <cmath>!
    1) Initialize variables: temperature, initial wind speed, old wind chill, new wind chill, wind chill difference.
    2) User inputs temperature and starting wind speed.
    3) Calculate old wind chill value; use sqrt function.
    4) Calculate new wind chill value; use pow function.
    5) Calculate wind chill difference; use abs function.
    6) Output Wind Speed, Old Formula, New Formula, and Difference.
*/

 #include <iostream>
 #include <cmath>
 using namespace std;
 
 int main () {
     //Initialize variables: temperature, initial wind speed, old wind chill, new wind chill, wind chill difference.
     double temperature  = 0.00; //Units in degrees Fahrenheit.
     double velocity     = 0.00;
     double oldWindChill = 0.00;
     double newWindChill = 0.00;
     double difference   = 0.00;
     
     //User inputs temperature and starting wind speed.
     cout << "Enter temperature (°F):" << endl;
     cin >> temperature;
     
     cout << "Enter wind speed (mph):" << endl;
     cin >> velocity;
     
     //Calculate old wind chill value; use sqrt function.
     oldWindChill = 0.081 * (3.71 * sqrt(velocity) + 5.81 - 0.25 * velocity) * (temperature - 91.4) + 91.4; //Using formula from prompt.
     
     //Calculate new wind chill value; use pow function.
     newWindChill = 35.74 + 0.6215 * temperature - 35.75 * pow(velocity, 0.16) + 0.4275 * temperature * pow(velocity, 0.16); //Using formula from prompt.
     
     //Calculate wind chill difference; use abs function.
     difference = abs(oldWindChill - newWindChill);
     
     //Output Wind Speed, Old Formula, New Formula, and Difference.
     cout << "Wind Speed: " << velocity << " mph" << endl;
     cout << "Old Formula: " << oldWindChill << " °F" << endl;
     cout << "New formula: " << newWindChill << " °F" << endl;
     cout << "Difference: " << difference << " °F" << endl;
     
     return 0;
     
 }