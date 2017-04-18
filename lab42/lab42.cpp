// Bjorn Larsen
// 4/13/2017

/*
Problem Statement:
    This program mimics an online shopping cart. You are the proprietor of an online shop and have to keep track of inventory, price and the
    user’s shopping cart. Create a menu of at least 10 items for the user to choose from. Identify your starting inventory and price. As the user
    purchases an item, you should remove that item from inventory (subtract 1) and add the price to a total. When the user is done adding items
    to their cart, you should output a statement of what they have ordered and the total cost of their purchases.  Do not allow you inventory to
    go below 0.
    
Program Description:
    
    
Pseudo-code:
    Online Shopping Cart class:
        Initialize inventory array
        Initialize shopping cart array
        Initialize price array
        Add Item Function
            If inventory array value is zero, item out of stock
            Add one to shopping cart array value
            Subtract one from inventory array value
        Total Cost Function
            Sum values of the shopping cart array times the price array for final price
        Constructor
    In main:
        Initialize inventory array (10 items of specific prices and speicifc inventory values)
        Initialize shopping cart array (10 items of price 0 and amount 0)
        Add Item Function in while loop
        Run function
        
    Inventory and price:
    Potato:                                   P - $2   Q - 20
    Vegetable:                                P - $3   Q - 15
    Beef Jerky:                               P - $6   Q - 2
    Calorie Bar:                              P - $2   Q - 3
    Chair:                                    P - $30  Q - 1
    Computer:                                 P - $500 Q - 2
    Wacky Wavy Inflatable Pillsbury Doughboy: P - $200 Q - 1
    Dollar:                                   P - $2   Q - 100
    Cup Noodles:                              P - $1   Q - 12
    Rancid Beef:                              P - $0   Q - 3
*/

#include <iostream>
using namespace std;

const int SIZE = 10; //10 different store items

//Online Shopping Cart class
class OnlineShoppingCart {
    
    private: //The 3 parallel arrays:
        
        //Initialize inventory array
        int inventory_[SIZE];
        
        //Initialize shopping cart array
        int shopping_cart[SIZE];
        
        //Initialize price array
        int price_[SIZE];
    
    public: //2 functions and a constructor
    
        //Add Item Function
        void AddItem(int item) { //No for loop necessary because specific array value is being refernced
            
            //If inventory array value is zero, item out of stock
            if (inventory_[item] == 0) {
                cout << "Item out of stock." << endl;
            }
            
            else {
                //Add one to shopping cart array value
                shopping_cart[item]++;
                
                //Subtracts one from inventory array value
                inventory_[item]--;
            }
            
            return;
        }
        
        //Total Cost Function
        int TotalCost() {
            
            int totalCost = 0;
            
            for (int i = 0; i < SIZE; i++) {
                totalCost = totalCost + (shopping_cart[i] * price_[i]); //Quantity times price for each value added up.
            }
            
            return totalCost;
        }
        
        //Constructor
        OnlineShoppingCart(int price[], int inventory[], int shoppingCart[]) { //Initialize each parameter as array.
            
            for (int i = 0; i < SIZE; i++) {
                price_[i] = price[i];
                inventory_[i] = inventory[i]; //Each main array value being transfered to class array value part by part
                shopping_cart[i] = shoppingCart[i];
            }
            
            return;
        }
};

int main() {
    
    /*
    Potato:                                   P - $2   Q - 20
    Vegetable:                                P - $3   Q - 15
    Beef Jerky:                               P - $6   Q - 2
    Calorie Bar:                              P - $2   Q - 3
    Chair:                                    P - $30  Q - 1
    Computer:                                 P - $500 Q - 2
    Wacky Wavy Inflatable Pillsbury Doughboy: P - $200 Q - 1
    Dollar:                                   P - $2   Q - 100
    Cup Noodles:                              P - $1   Q - 12
    Rancid Beef:                              P - $0   Q - 3
    */
    
    //Initialize price array (10 items of specific prices)
    int price[SIZE] = {2, 3, 6, 2, 30, 500, 200, 2, 1, 1};
    
    //Initialize inventory array (10 items of specific inventory values)
    int inventory[SIZE] = {20, 15, 2, 3, 1, 2, 1, 100, 12, 3};
    
    //Initialize shopping cart array (10 items of amount 0)
    int shoppingCart[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    OnlineShoppingCart Cart(price, inventory, shoppingCart); //Constructor call parameter do not need []
    
    cout << "Welcome! Here are our items:" << endl;
    cout << "Item 1:  Potato:                                   P - $2   Q - 20" << endl;
    cout << "Item 2:  Vegetable:                                P - $3   Q - 15" << endl;
    cout << "Item 3:  Beef Jerky:                               P - $6   Q - 2" << endl;
    cout << "Item 4:  Calorie Bar:                              P - $2   Q - 3" << endl;
    cout << "Item 5:  Chair:                                    P - $30  Q - 1" << endl;
    cout << "Item 6:  Computer:                                 P - $500 Q - 2" << endl;
    cout << "Item 7:  Wacky Wavy Inflatable Pillsbury Doughboy: P - $200 Q - 1" << endl;
    cout << "Item 8:  Dollar:                                   P - $2   Q - 100" << endl;
    cout << "Item 9:  Cup Noodles:                              P - $1   Q - 12" << endl;
    cout << "Item 10: Rancid Beef:                              P - $1   Q - 3" << endl;
    cout << endl;
    
    int item = 0;
    
    cout << "Please enter an item number to add it to your cart (Press 0 to quit)." << endl;
    cin >> item;
    
    //Add Item Function in while loop
    while (item != 0) { //Zero quits loop
        
        item--; //This is necessary because array value locations are 0-9 not 1-10
        
        if (item > 9|| item < 0) {
            cout << "Invalid. ";
        }
        
        Cart.AddItem(item);
        
        cout << "Please enter an item number to add it to your cart (Press 0 to quit)." << endl;
        cin >> item;
    }
    
    //Run function
    cout << "Your final cost is $" << Cart.TotalCost() << ".";
    
    return 0;
}

//https://github.com/blarsen005/bjornlarsen-CSCI20-Spr2017/blob/d472c19dc1818301a59e18a637b9152f5ed08ac8/lab42/lab42.cpp