// Bjorn Larsen
// 4/18/2017

/*
Program Description:
    This program mimics an online shopping cart using an array of objects. Instead of using constructors to set the values of multiple arrays in one object,
    It create 10 separate objects with an array and uses Mutators to set the object variables. It is functionally very similar to lab 42, which outputted
    all store items and allowed users to choose different items on the list, adding them to their shopping cart, and then outputting the final price when done
    shopping. This program contains minor differences including final quantity purchased of each item is output at the end.
    
Pseudocode:
    SIZE Variable = 10
    Class Shopping Cart:
        4 Arrays:
            Object name
            Price
            Current Inventory
            Items purchased
        Function Set Object Name
        Function Set Price
        Function Set Inventory
        Function Set User Items
        Function Get Object Name
        Function Get Price
        Function Get User Items
        Function Purchase Item: Subtract 1 from inventory array, add 1 to items purchased array. Invalid if no more shop inventory
        Function Output Receipt: Return items purchased times price
        Default Constructor
        Overloaded Constructor
    Main:
        Create total price variable
        Create Arrays
            Names (10 names)
            Prices (10 prices)
            Inventory (10 values)
            User cart (10 values of 0)
        Create Array of objects/Test Constructor
        Set Array of objects in for loop
        Call objects function and price function in for loop
        User input item they want
        While loop calls purchase item function for the specific object. User ends when they input specific value
        In a for loop:
            Call object name function
            Call Items purchased 
            add receipt function to a total cost
        Output total price.

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
#include <string>
using namespace std;

//SIZE Variable = 10
const int SIZE = 10;

//Class Shopping Cart:
class ShoppingCart {
    
    //4 values
    private: //3 sotre values + user number of items in cart
        
        //Object name
        string name_;
        
        //Price
        int price_;
        
        //Current Inventory
        int current_inventory;
        
        //Items purchased
        int items_purchased;
        
    public: //4 Mutators, 4 Accessors, Purchase Item function, Price Calculator for the object, 2 constructors
        
        //Function Set Object Name
        void SetItemName(string name) { //input: name
            name_ = name;
            return;
        }
        
        //Function Set Price
        void SetItemPrice(int price) {  //input: price
            price_ = price;
            return;
        }
        
        //Function Set Inventory
        void SetInventory(int inventory) { //input: inventory
            current_inventory = inventory;
            return;
        }
        
        //Function Set User Items
        void SetItemQuantity(int quantity) { //input: quantity items purchased
            items_purchased = quantity;
            return;
        }
        
        //Function Get Object Name
        string GetItemName() { //output: name
            return name_;
        }
        
        //Function Get Price
        int GetItemPrice() { //output: price
            return price_;
        }
        
        //Function Get Inventory
        int GetInventory() { //output: price
            return current_inventory;
        }
        
        //Function Get User Items
        int GetItemQuantity() { //output: price
            return items_purchased;
        }
        
        //Function Purchase Item: Subtract 1 from inventory array, add 1 to items purchased array. Invalid if no more shop inventory
        void PurchaseItem() { //No input or output; just changes values of class variables
            if (current_inventory == 0) { //Store inventory can't go below zero
                cout << "Out of stock. ";
            }
            else {
                current_inventory--;
                items_purchased++;
            }
            return;
        }
        
        //Function Output Receipt: Return items purchased times price
        int FinalPrice() { //output: price times quantity
            return price_ * items_purchased;
        }
        
        //Default Constructor
        ShoppingCart() { //No input or output
            name_ = "Item";
            price_ = 0;
            current_inventory = 0;
            items_purchased = 0;
        }
        
        //Overloaded Constructor
        ShoppingCart(string i, int j, int k, int l) { //input: any inputs were present in main
            name_ = i;
            price_ = j;
            current_inventory = k;
            items_purchased = l;
        }
};

//Main:
int main() {
    
    //Create total price variable
    int totalPrice = 0;
    
    //Create arrays (values based on store items):
    //Names (10 names)
    string name[SIZE] = {"Potato", "Vegetable", "Beef Jerky", "Calorie Bar", "Chair", "Computer", "Wacky Wavy Inflatable Pillsbury Doughboy", "Dollar", "Cup Noodles", "Rancid Beef"};
    
    //Prices (10 prices)
    int price[SIZE] = {2, 3, 6, 2, 30, 500, 200, 2, 1, 1};
    
    //Inventory (10 values)
    int inventory[SIZE] = {20, 15, 2, 3, 1, 2, 1, 100, 12, 3};
    
    //User cart (10 values of 0)
    int shoppingCart[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    //Create Array of objects/Test Constructor
    ShoppingCart Item[SIZE]; //This creates 10 different objects
    
    //Set Array of objects in for loop
    for (int i = 0; i < SIZE; i++) { //The loop sets the variables for each object individually
        Item[i].SetItemName(name[i]);
        Item[i].SetItemPrice(price[i]);
        Item[i].SetInventory(inventory[i]);
        Item[i].SetItemQuantity(shoppingCart[i]);
    }
    
    cout << "Welcome! Here are our items:" << endl;
    
    //Call objects function and price function in for loop
    for (int i = 0; i < SIZE; i++) { //Outputs full list of items
        cout << "Item " << i + 1 << ": " << Item[i].GetItemName() << " - $" << Item[i].GetItemPrice() << endl;
    }
    
    cout << endl;
    
    //User input item they want
    int item = 0;
    cout << "Please enter an item number to add it to your cart (Press 0 to quit)." << endl;
    cin >> item;
    
    //While loop calls purchase item function for the specific object. User ends when they input specific value
    while (item != 0) { //Zero quits loop
        
        item--; //This is necessary because array value locations are 0-9 not 1-10
        
        if (item > 9 || item < 0) {
            cout << "Invalid. ";
        }
        else {
            Item[item].PurchaseItem();
        }
        
        cout << "Please enter another item number to add it to your cart (Press 0 to quit)." << endl;
        cin >> item;
    }
    
    
    cout << endl << "You purchased:" << endl;
    
    //In a for loop:
    for (int i = 0; i < SIZE; i++) {
        
        //Call object name function; Call Items purchased 
        if (Item[i].GetItemQuantity() != 0) {
            cout << Item[i].GetItemName() << " - " << Item[i].GetItemQuantity() << endl;
        
            //add receipt function to a total cost
            totalPrice = totalPrice + Item[i].FinalPrice();
        }
    }
    
    cout << endl << "Your Total Cost is $" << totalPrice;
    
    return 0;
}