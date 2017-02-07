
/*
This program creates a prediction for the US Census after a given
number of years, based on number of births, deaths, and
immigrants per second (which comes out to about 1 person per
15 seconds).

Pseudocode:
    1) Initialize variables for the initial year, initial population, final year,
       total population increase every year, number of years since 2017, and the final
       population. Also initialize variables for births per second, deaths per second,
       and international migrants per second in order to calculate a coefficient that can be used
       to represent population increase per second.
    2) Output a prompt to input number of years.
    3) User inputs number of years after 2017.
    4) Calculate population increase per year based on the increase per second.
    5) Calculate the final population from the input number of years, population increase per year,
       and initial population.
    6) Find final year from 2017 and the input number of years.
    7) Output how many people there will be in the given year.
*/

 #include <iostream>
 using namespace std;
 
 int main() {
     int initialYear = 2017;
     int initialPop = 324473427; // Initial population of US as of 2/2/2017, 4:16 pm.
     int finalYear = 0;
     int peoplePerYear = 0;
     int numYears = 0;
     int numPeople = 0;
     int birthsPerSec = 1/8; // These 3 variables are here for reference; not used in official calculations as variables would be assigned as zero.
     int deathsPerSec = 1/11; // See birthsPerSec comment.
     int migrantsPerSec = 1/29; // See birthsPerSec comment.
     // birthsPerYear - deathsPerYear + migrantsPerSec is equivalent to 175/2552. The reciprocal of this to the nearest integer is 15.
     int peoplePerSecCoefficient = 15;
     
     cout << "Enter number of years after " << initialYear << "." << endl;
     cin >> numYears;
     
       peoplePerYear = 60 * 60 * 24 * 365 / peoplePerSecCoefficient; // Conversion: From seconds to minutes to hours to days to years.
       numPeople = numYears * peoplePerYear + initialPop;
       finalYear = 2017 + numYears; 
     
     cout << "In the year " << finalYear << ", the population will be " << numPeople << " in the United States." << endl;
     
     return 0;
     
 }