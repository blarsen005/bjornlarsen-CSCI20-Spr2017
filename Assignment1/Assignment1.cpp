// Bjorn Larsen
// 2/16/2017

/*
Problem Description:
    Calculate a person’s current and end average for this class. A person will
    enter the current number of points and the total number of points for each
    category (in order from the syllabus) and how far through the semester
    they are (as a percentage).  The program will output a report card with
    name, average for each grading category, current grade, and final grade if
    they do not do anything else all semester.
    
Program Description:
    This program creates a report card for a student in CSCI 020. The report card
    includes the student's full name, their grade in each of the three grading
    categories, Their total grade at the time, and their total grade at the end of
    the semester, assuming they don't do any more work.

Pseudocode:
    1)  Create a struct for the report card with data members for current number of points and total number
        of points.
    2)  Create struct variables for Preparation & Participation, Projects and Labs, and Tests.
    3)  Initialize variable for semester progress and string variables for first and last name.
    4)  Prompt user to enter name.
    5)  Prompt user to input values for current and total number of points for each of the struct variables.
    6)  Prompt user to input value for semester progress.
    7)  Output name.
    8)  Calculate averages for each category: current points divided by total points.
    9)  Output averages for each grading category.
    10) Multiply each grading category value by it's percentage in total grade and add them together for
        current grade.
    11) Output current grade.
    12) Multiply current grade by semester progress percentage.
    13) Output Final Grade if user doesn't do anything else all semester.
*/

#include <iostream>
#include <string>
using namespace std;

 struct ReportCard {
     //Each grading category requires both current points and total points in the program.
     double currentPoints = 0;
     double totalPoints   = 100;
     double score         = 0; //Score represents currentPoints / totalPoints.
     
 };
 
 int main () {
     
     ReportCard prepPart;
     ReportCard projectLabs;
     ReportCard tests;
     double semesterProgress = 0;
     string firstName = "First";
     string lastName  = "Last";
     
     //Here the user is inputting all their information.
     cout << "Enter first name:" << endl;
     cin >> firstName;
     
     cout << "Enter last name:" << endl;
     cin >> lastName;
     
     cout << "Enter current number of points in the Preparation & Participation grading category:" << endl;
     cin >> prepPart.currentPoints;
     
     cout << "Enter total number of points in the Preparation & Participation grading category:" << endl;
     cin >> prepPart.totalPoints;
     
     cout << "Enter current number of points in the Projects & Labs grading category:" << endl;
     cin >> projectLabs.currentPoints;
     
     cout << "Enter total number of points in the Projects & Labs grading category:" << endl;
     cin >> projectLabs.totalPoints;
     
     cout << "Enter current number of points in the Tests grading category:" << endl;
     cin >> tests.currentPoints;
     
     cout << "Enter total number of points in the Tests grading category:" << endl;
     cin >> tests.totalPoints;
     
     cout << "Enter percent progress through semester (as an integer):" << endl; //User reminded to enter as an integer so they don't actually use a % symbol.
     cin >> semesterProgress;
     
     //Output name.
     cout << firstName << " " << lastName << endl;
     
     //Calculating average for each grading category.
     prepPart.score = prepPart.currentPoints / prepPart.totalPoints;
     projectLabs.score = projectLabs.currentPoints / projectLabs.totalPoints;
     tests.score = tests.currentPoints / tests.totalPoints;
     
     //Output of grade within each category.
     cout << "Preparation & Participation grade: " << prepPart.score << endl;
     cout << "Projects & Labs grade: " << projectLabs.score << endl;
     cout << "Tests grade: " << tests.score << endl;
     
     //Calculating current grade.
     double currentGrade;
     currentGrade = (0.3 * prepPart.score) + (0.5 * projectLabs.score) + (0.2 * tests.score); //decimal coefficients as according to April Browne CSCI 020 syllabus.
     
     //Output of current grade.
     cout << "Total grade: " << currentGrade << endl;
     
     //Calculating final grade.
     double finalGrade;
     finalGrade = (semesterProgress / 100) * currentGrade;
     
     //Output of final grade.
     cout << "Total grade at the end of the semester if you don't do any more work: " << finalGrade << endl;
     
     return 0;
     
 }