// Bjorn Larsen
// 2/26/2017

/*
Problem Statement:
    Write a program that will read a student’s grades and output an HTML page (Links to an external site.) to output a student’s transcript including
    semester GPA and overall GPA. The program should ask for an input file which includes the student’s name, semester (as a number), and list of grades
    (A, B, C, D, F) and class hours. It reads the data and calculates the semester GPA and overall GPA.
    
    NOTE: An HTML page is required but it doesn't have to be fancy.  If this is a challenge/problem please come see me ASAP.
    
Program Description:
    This program reads a student's grades from a txt file and outputs them into an html file. txt file formatted as seen below.
    
Pseudocode:
    Main:
        string line
        Create fin/fout objects
        Open files to input
        Read name from file (to name variable)
        Read semester from file (to semester variable)
        For loop
            Read units from file (to units array)
            Read grade from file (to grades array)
            grades from letters to numbers
        Read total units from file (to total units variable)
        Read Current GPA from file (to total GPA variable)
        Semester GPA = (Each grade * each unit) / sum of units
        Total GPA = ((Each grade * each unit) + Prior grade * Prior GPA) / sum of current & prior units
        Output name, semester, semester gpa, and total gpa in HTML format
        Close file
*/

//The format of the input file:

/*
John Bron Lawn

3

3 A

3 A

3 A

3 B

24 3.5
*/

#include <string>
#include <fstream> //1st step of using file i/o: using fstream library
using namespace std;

const int SIZE = 4; //File contain 4 lines wirth of courses

int main() {
    
    string name; //Output to html
    int semester; //Output to html
    int units[SIZE];
    char letterGrades[SIZE];
    double grades[SIZE];
    int priorUnits;
    double priorGPA;
    double semesterGPA; //Output to html
    double overallGPA; //Output to html
    
    //Create fin/fout objects (2nd step of file i/o)
    ifstream fin; //Both ifstream and ofstream are classes in library <fstream>
    ofstream fout; //Initializing fin and fout objects allows class functions their class functions to be used
    
    //Open files to input (3rd step of file i/o)
    fin.open("input.txt");
    fout.open("output.html");
    
    //4th step of file i/o: Using the files
    
    //Read name from file (to name variable)
    getline(fin, name);
    
    //Read semester from file (to semester variable)
    fin >> semester;
    
    //For loop
    for (int i = 0; i < SIZE; i++) {
        
        //Read units from file (to units array)
        fin >> units[i];
        
        //Read grade from file (to grades array)
        fin >> letterGrades[i];
        
        //Grades from letters to numbers
        switch (letterGrades[i]) { //A-D associated with 4.0-1.0 GPA
            
            case 'A':
                grades[i] = 4.0;
                break;
                
            case 'B':
                grades[i] = 3.0;
                break;
                
            case 'C':
                grades[i] = 2.0;
                break;
                
            case 'D':
                grades[i] = 1.0;
                break;
                
            default:
                grades[i] = 0.0;
                break;
        }
    }
    
    //Read total units from file (to total units variable)
    fin >> priorUnits;
    
    //Read Current GPA from file (to total GPA variable)
    fin >> priorGPA;
    
    //Semester GPA = (Each grade * each unit) / sum of units
    double topHalf; //top half of semesterGPA fraction
    double bottomHalf; //bottom half of semesterGPA function
    for (int i = 0; i < SIZE; i++) {
        topHalf = topHalf + (units[i] * grades[i]);
        bottomHalf = bottomHalf + units[i];
    }
    
    semesterGPA = topHalf / bottomHalf;
    
    //Total GPA = ((Each grade * each unit) + Prior grade * Prior GPA) / sum of current & prior units
    overallGPA = (topHalf + (priorUnits * priorGPA)) / (bottomHalf + priorUnits);
    
    //Output name, semester, semester gpa, and total gpa in HTML format
    fout << "<!DOCTYPE html>" << endl;
    fout << "<html>" << endl;
    fout << "<head>" << endl;
    fout << "<title>Transcript</title>" << endl;
    fout << "</head>" << endl;
    fout << "<body>" << endl;
    fout << endl;
    fout << "<h1>Transcript</h1>" << endl;
    fout << "<p>" << endl;
    fout << "Name: " << name << endl;
    fout << "Semester: " << semester << endl;
    fout << "Semester GPA: " << semesterGPA << endl;
    fout << "Overall GPA: " << overallGPA << endl;
    fout << "</p>" << endl;
    fout << endl;
    fout << "</body>" << endl;
    fout << "</html>" << endl;
    
    //Close file (5th step of file i/o)
    fin.close();
    fout.close();
    
    return 0;
}