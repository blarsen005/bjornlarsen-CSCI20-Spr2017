// Bjorn Larsen
// 2/26/2017

/*
Problem Statement:
    Write a program that will read a student’s grades and output an HTML page (Links to an external site.) to output a student’s transcript including
    semester GPA and overall GPA. The program should ask for an input file which includes the student’s name, semester (as a number), and list of grades
    (A, B, C, D, F) and class hours. It reads the data and calculates the semester GPA and overall GPA.
    
    NOTE: An HTML page is required but it doesn't have to be fancy.  If this is a challenge/problem please come see me ASAP.
    
Program Description:
    
    
Pseudocode:
    Main:
        string line
        Create fin/fout objects
        Open files to input
        Read name from file (to name variable)
        Read semester from file (to semester variable)
        Read units from file (to a units variable)
        For loop (condition: while class units is one digit)
            Read units from file (to units array)
            Read grade from file (to grades array)
        Read total units from file (to total units variable)
        Read Current GPA from file (to total GPA variable)
        Grades from letters to numbers
        Semester GPA = (Each grade * each unit) / sum of units
        Total GPA = ((Each grade * each unit) + Prior grade * Prior GPA) / sum of current & prior units
        Output name, semester, semester gpa, and total gpa in HTML format
        Close file
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    
    //string line
    string line;
    string name;
    int semester = 0;
    
    //Create fin/fout objects
    ifstream fin;
    ofstream fout;
    
    //Open files to input
    fin.open("input.txt");
    fout.open("output.html");
    
    //Read name from file (to name variable)
    getline(fin, name);
    
    //Read semester from file (to semester variable)
    fin >> semester;
    
    
    
    cout << name << endl;
    cout << semester << endl;
    
    
    fin.close();
    fout.close();
    
    return 0;
}