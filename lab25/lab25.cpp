// Bjorn larsen
// 3/7/2017

/*
Program Description:
    This program lists book data for five different books. It uses a class, set/get functions, and five objects to keep categorize this data, which
    includes title, author, and copyright year. The final program output lists the five books titles, authors, and copyright years
    in an organized fashion.
    
Pseudocode:
    1) Create class "book".
    2) Create private data members for title, author, and copyright year.
    3) In public, call a set function to alter the title data member.
    4) Call a get function to return the title data member.
    5) Repeat steps 3 and 4 for author and copyright year.
    6) Create print function to output title, author, and copyright year.
    7) Create 5 objects of class book.
    8) In main, create variables for user input title, author, and copyright year.
    9) Prompt user to input information for the first book, starting with title, and then running getTitle. Repeat for each variable and each book.
    10) Use print function for each book to output all data at once.
*/

#include <iostream>
#include <string>
using namespace std;

 //Create class "book".
 class Book {
     
     //Create private data members for title, author, and copyright year.
     private:
        string title; //Private variables can only be interacted with through get/set functions.
        string author;
        int year;
        
     //In public, call a set and a get function to alter the title data member. Repeat for author and copyright year.
     public:
        void SetTitle(string inputTitle);
        string GetTitle() const;
        void SetAuthor(string inputAuthor);
        string GetAuthor() const;
        void SetYear(int inputYear);
        int GetYear() const;
        void PrintBookInfo();
 };
 
 //Create set/get functions. Title
 void Book::SetTitle(string inputTitle) {
     title = inputTitle;
     return;
 }
 
 string Book::GetTitle() const {
     return title;
 }
 
 //Author
 void Book::SetAuthor(string inputAuthor) {
     author = inputAuthor;
     return;
 }
 
 string Book::GetAuthor() const {
     return author;
 }
 
 //Copyright Year
 void Book::SetYear(int inputYear) {
     year = inputYear;
     return;
 }
 
 int Book::GetYear() const {
     return year;
 }
 
 //Create print function to output title, author, and copyright year.
 void Book::PrintBookInfo() {
     cout << "Title: " << GetTitle() << ". Author: " << GetAuthor() << ". Copyright Year: " << GetYear() << "." << endl;
     return;
 }
 
 int main() {
     
     //Create 5 objects of class book.
     Book Book1;
     Book Book2;
     Book Book3;
     Book Book4;
     Book Book5;
     
     //In main, create variables for user input title, author, and copyright year.
     string inputTitle;
     string inputAuthor;
     int inputYear;
     
     //Prompt user to input information for the first book, starting with title, and then running getTitle. Repeat for each variable and each book.
     
     //Book 1.
     cout << "Enter first book title: " << endl;
     cin >> inputTitle;
     Book1.SetTitle(inputTitle);
     
     cout << "Enter first book author: " << endl;
     cin >> inputAuthor;
     Book1.SetAuthor(inputAuthor);
     
     cout << "Enter first book year: " << endl;
     cin >> inputYear;
     Book1.SetYear(inputYear);
     
     //Book 2.
     cout << "Enter second book title: " << endl;
     cin >> inputTitle;
     Book2.SetTitle(inputTitle);
     
     cout << "Enter second book author: " << endl;
     cin >> inputAuthor;
     Book2.SetAuthor(inputAuthor);
     
     cout << "Enter second book year: " << endl;
     cin >> inputYear;
     Book2.SetYear(inputYear);
     
     //Book 3.
     cout << "Enter third book title: " << endl;
     cin >> inputTitle;
     Book3.SetTitle(inputTitle);
     
     cout << "Enter third book author: " << endl;
     cin >> inputAuthor;
     Book3.SetAuthor(inputAuthor);
     
     cout << "Enter third book year: " << endl;
     cin >> inputYear;
     Book3.SetYear(inputYear);
     
     //Book 4.
     cout << "Enter fourth book title: " << endl;
     cin >> inputTitle;
     Book4.SetTitle(inputTitle);
     
     cout << "Enter fourth book author: " << endl;
     cin >> inputAuthor;
     Book4.SetAuthor(inputAuthor);
     
     cout << "Enter fourth book year: " << endl;
     cin >> inputYear;
     Book4.SetYear(inputYear);
     
     //Book 5.
     cout << "Enter fifth book title: " << endl;
     cin >> inputTitle;
     Book5.SetTitle(inputTitle);
     
     cout << "Enter fifth book author: " << endl;
     cin >> inputAuthor;
     Book5.SetAuthor(inputAuthor);
     
     cout << "Enter fifth book year: " << endl;
     cin >> inputYear;
     Book5.SetYear(inputYear);
     
     //Use print function for each book to output all data at once.
     cout << "_____________________________________________________" << endl;
     cout << "Book 1 Info: " << endl;
     Book1.PrintBookInfo();
     cout << "Book 2 Info: " << endl;
     Book2.PrintBookInfo();
     cout << "Book 3 Info: " << endl;
     Book3.PrintBookInfo();
     cout << "Book 4 Info: " << endl;
     Book4.PrintBookInfo();
     cout << "Book 5 Info: " << endl;
     Book5.PrintBookInfo();
     cout << "_____________________________________________________" << endl;
     
     return 0;
 }