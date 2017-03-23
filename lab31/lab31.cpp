// Bjorn Larsen
// 3/23/2017

/*
Program Description:
    This program determines the best data plan for a user based on a variety of possible conditions. The user inputs number of dumb phones,
    smart phones, tablets, how much data they plan to use, and if they have corporate discount. The program then determines whether it would be
    cheapest to use a flat monthly plan with no data, an unlimited data plan, or a pay per data plan. Corporate discount, as well as a family plan
    discount, are each then applied if conditions are met, and the price of the selected plan is output.

Pseudocode:
    1. Declare variables, including bool variables for the discounts.
    2. User inputs number/types of devices, data, and discounts.
    3. Equation for device charge based on number on devices.
    4. Monthly charge equation: condition 0 gb data.
    5. Unlimited data equation INCLUDES condition for going past 10 gb data.
    6. Pay per data equation INCLUDES conditions for going past 1, 5, and 15 gb data.
    7. Determine if family plan discount is true based on num of devices.
    8. Conditions based on if discounts are true.
    9. Condition for each data plan being cheapest, output based on condition.
*/

#include <iostream>
using namespace std;

int main() {
    
    //Declare variables, including bool variables for the discounts.
    int numDumbPhones = 0; //Note this is a large mass of variables, and organizing the data into a class would seriouly improve the cleanliness of the program.
    int numSmartPhones = 0;
    int numTablets = 0;
    int deviceCharge = 0;
    double data = 0.00;
    int monthlyCharge = 30.00;
    double unlimitedCharge = 0.00;
    double payPerDataCharge = 0.00;
    char corporateDiscount = 'n';
    double corporateCoeff = 0.00;
    double familyPlanCoeff = 0.00;
    double totalCharge = 0.00;
    
    //User inputs number/types of devices, data, and discounts.
    cout << "Enter number of dumb phones: " << endl;
    cin >> numDumbPhones;
    
    cout << "Enter number of smart phones: " << endl;
    cin >> numSmartPhones;
    
    cout << "Enter number of tablets: " << endl;
    cin >> numTablets;
    
    cout << "Enter GB of data: " << endl;
    cin >> data;
    
    cout << "Have corporate discount? (enter 'y' if yes)" << endl;
    cin >> corporateDiscount;
    
    //Equation for device charge based on number on devices.
    deviceCharge = (5 * numSmartPhones) + (10 * numTablets);
    
    //Unlimited data equation INCLUDES condition for going past 10 gb data.
    unlimitedCharge = 75;
    if (data > 10) { //no else statement necessary because unlimited charge has been already given an appropriate value.
        unlimitedCharge = unlimitedCharge + (1.5 * (data - 10));
    }
    
    //Pay per data equation INCLUDES conditions for going past 1, 5, and 15 gb data.
    payPerDataCharge = 5;
    if (data > 1) { //3 if statements here each build off of each other
        payPerDataCharge = payPerDataCharge + (0.75 * (data - 1));
    }
    if (data > 5) {
        payPerDataCharge = payPerDataCharge + (1.5 * (data - 5));
    }
    if (data > 15) {
        payPerDataCharge = payPerDataCharge + (3.0 * (data - 15));
    }
    
    //Conditions based on if discounts are true.
    if (corporateDiscount == 'y') {
        corporateCoeff = 0.9; //discounts by taking 90%
    }
    else {
        corporateCoeff = 1; //does not discount by taking 100%
    }
    
    if (numDumbPhones + numSmartPhones + numTablets >= 3) {
        familyPlanCoeff = 3 * (numDumbPhones + numSmartPhones + numTablets); //discounts by subtracting value
    }
    else {
        familyPlanCoeff = 0; //does not discount by subtracting nothing
    }
    
    //Condition for each data plan being cheapest, output based on condition.
    if (data == 0) {
        totalCharge = (deviceCharge + monthlyCharge) * corporateCoeff - familyPlanCoeff;
        cout << "Cheapest data plan: Monthly" << endl;
        cout << "Total charge: " << totalCharge << endl;
    }
    
    else if (unlimitedCharge <= (payPerDataCharge + monthlyCharge)) {
        totalCharge = (deviceCharge + unlimitedCharge) * corporateCoeff - familyPlanCoeff;
        cout << "Cheapest data plan: Unlimited" << endl;
        cout << "Total charge: " << totalCharge << endl;
    }
    
    else if ((payPerDataCharge + monthlyCharge) < unlimitedCharge) {
        totalCharge = (deviceCharge + payPerDataCharge + monthlyCharge) * corporateCoeff - familyPlanCoeff;
        cout << "Cheapest data plan: Pay per data" << endl;
        cout << "Total charge: " << totalCharge << endl;
    }
    
    else { //in case of program error and/or conditions not encompassing all possible inputs
        cout << "error" << endl;
    }
    
    return 0;
}