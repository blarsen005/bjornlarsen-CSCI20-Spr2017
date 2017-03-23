// Bjorn Larsen
// 3/23/2017

/*
Problem Statement:
    Create a program for a new cell phone company that uses complicated formulas to determine the charges for their service.   

    Device charge – free for dumb phone, $5 for smart phone, $10 tablet
    Monthly charge – $30 for unlimited talk and text
    Unlimited data – $75 for unlimited talk, text and data (up to 10 GB and $1.50 for each GB after that)
    Pay per data charge - $5 for the first GB of data and $0.75 for each GB or portion there of up to 5 GB. $1.50 for each GB or portion there of up to 15 GB.  $3 for each GB after that.
    Corporate Discount – 10% discount for corporate customers
    Family Plan Discount - $3 per phone line over 2.

    Determine the best plan for the user based on their needs.

Program Description:


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
    int numDumbPhones = 0;
    int numSmartPhones = 0;
    int numTablets = 0;
    int deviceCharge = 0;
    double data = 0.00;
    int monthlyCharge = 0.00;
    double unlimitedCharge = 0.00;
    double payPerDataCharge = 0.00;
    bool corporateDiscount = false;
    bool familyPlanDiscount = false;
    double corporateCoeff = 0.00;
    double familyPlanCoeff = 0.00;
    
    //User inputs number/types of devices, data, and discounts.
    cout << "Enter number of dumb phones: " << endl;
    cin >> numDumbPhones;
    
    cout << "Enter number of smart phones: " << endl;
    cin >> numSmartPhones;
    
    cout << "Enter number of tablets: " << endl;
    cin >> numTablets;
    
    cout << "Enter GB of data: " << endl;
    cin >> data;
    
    cout << "Have corporate discount? (enter 0 if no)" << endl;
    cin >> corporateDiscount;
    
    //Equation for device charge based on number on devices.
    deviceCharge = (5 * numSmartPhones) + (10 * numTablets);
    
    //Monthly charge equation: condition 0 gb data.
    if (data == 0) {
        monthlyCharge = 30;
    }
    
    //Unlimited data equation INCLUDES condition for going past 10 gb data.
    unlimitedCharge = 75;
    if (data > 10) {
        unlimitedCharge = unlimitedCharge + (1.5 * (data - 10));
    }
    
    //Pay per data equation INCLUDES conditions for going past 1, 5, and 15 gb data.
    payPerDataCharge = 5;
    if (data > 1) {
        payPerDataCharge = payPerDataCharge + (0.75 * (data - 1));
    }
    
    if (data > 5) {
        payPerDataCharge = payPerDataCharge + (1.5 * (data - 5));
    }
    
    if (data > 15) {
        payPerDataCharge = payPerDataCharge + (3.0 * (data - 15))
    }
    
    //Conditions based on if discounts are true.
    if (corporateDiscount == true) {
        corporateCoeff = 0.9;
    }
    else {
        corporateCoeff = 1;
    }
    
    if (familyPlanCoeff == true) {
        familyPlanCoeff = 
    }
    
    
    return 0;
}