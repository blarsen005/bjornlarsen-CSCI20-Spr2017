// Bjorn Larsen
// 3/28/2017

/*
Program Description:
    This program determines someone's total income tax based on wages, and also determined if the person still owes money or is due for a
    refund. Uses conditionals based on filing status as well as gross adjusted income to determine the total tax, and the difference between
    tax and amount withheld being positive or negative determines if the person owes or is owed money.
    
Pseudocode:
    1. User inputs name, filing status (single or married), gross wages, and the amount of tax withheld.
    2. In switch statement:
        3. If single: subtract 3900
        4. If result <= 0, 0 tax owed
           Else if result <= 8925, tax = 10% of the AGI
           Else if result <= 36250, tax = $892.50 plus 15% of the excess over $8,925
           Else if result <= 87850, tax = $4991.25 plus 25% of the excess over $36,250
           Else if result > 87850, tax = $17,891.25 plus 28% of the excess over $87,850
        5. If married: subtract 7800
        6. If result <= 0, 0 tax owed
           Else if result <= 17850, tax = 10% of the AGI
           Else if result <= 72500, tax = $1,785 plus 15% of the excess over $17,850
           Else if result > 72500, tax = $9,982.50 plus 28% of the excess over $72,500
    7. If tax > withheld amount, person owes tax
       If tax < withheld amount, person gets refund
       If tax == withheld amount, person has paid taxes
    8. Output name, gross wages, total tax, tax owed/refund to be given.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string name = "N/A";
    char status = 's';
    double wage = 0;
    double taxWithheld = 0;
    double tax = 0;
    double taxDiff = 0;
    
    //User inputs name, filing status (single or married), gross wages, and the amount of tax withheld.
    cout << "Enter name:" << endl;
    getline(cin, name); //getline to allow first & last name.
    cout << "Enter filing status (s if single, m if married):" << endl;
    cin >> status;
    cout << "Enter gross wage:" << endl;
    cin >> wage;
    cout << "Enter amount of tax withheld:" << endl;
    cin >> taxWithheld;
    cout << "" << endl; //blank line
    
    switch (status) { //Chooses an option from specific conditions.
        
        //If single: subtract 3900
        case 's':
        case 'S':
            
            wage = wage - 3900;
            //If result <= 0, 0 tax owed
            if (wage <= 0) {
                wage = 0;
                tax = 0;
            }
            //Else if result <= 8925, tax = 10% of the AGI
            else if (wage <= 8925) {
                tax = 0.10 * wage;
            }
            //Else if result <= 36250, tax = $892.50 plus 15% of the excess over $8,925
            else if (wage <= 36250) {
                tax = 892.50 + (0.15 * (wage - 8925));
            }
            //Else if result <= 87850, tax = $4991.25 plus 25% of the excess over $36,250
            else if (wage <= 87850) {
                tax = 4991.25 + (0.25 * (wage - 36250));
            }
            //Else if result > 87850, tax = $17,891.25 plus 28% of the excess over $87,850
            else { //Wage > 87850
                tax = 17891.25 + (0.28 * (wage - 87850));
            }
            break;
        
        //If married: subtract 7800
        case 'm':
        case 'M':
            
            wage = wage - 7800;
            //If result <= 0, 0 tax owed
            if (wage <= 0) {
                wage = 0;
                tax = 0;
            }
            //Else if result <= 17850, tax = 10% of the AGI
            else if (wage <= 17850) {
                tax = 0.10 * wage;
            }
            //Else if result <= 72500, tax = $1,785 plus 15% of the excess over $17,850
            else if (wage <= 72500) {
                tax = 1785 + (0.15 * (wage - 17850));
            }
            //Else if result > 72500, tax = $9,982.50 plus 28% of the excess over $72,500
            else { //Wage > 72500
                tax = 9982.50 + (0.28 * (wage - 72500));
            }
            break;
            
        default: //In case user did not input m or s.
            
            cout << "Invalid marital status (enter single or married)." << endl;
            return 1; //Program stops running; invalid input entered.
            break;
    }
    
    //Output name, gross wages, total tax, tax owed/refund to be given.
    cout << "Name: " << name << endl;
    cout << "Total Gross Adjusted Income: $" << wage << endl;
    cout << "Total Income Tax: $" << tax << endl;
    
    taxDiff = tax - taxWithheld;
    //If tax > withheld amount, person owes tax
    if (taxDiff > 0) {
        cout << "You still owe $" << taxDiff << endl;
    }
    //If tax < withheld amount, person gets refund
    else if (taxDiff < 0) {
        cout << "You are owed a refund of $" << taxDiff * -1 << endl;
    }
    //If tax == withheld amount, person has paid taxes
    else { //taxDiff <= 0.0001 && tax Diff >= 0.0001
        cout << "You owe no tax." << endl;
    }
    
    return 0;
}