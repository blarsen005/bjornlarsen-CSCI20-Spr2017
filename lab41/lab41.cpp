// Bjorn Larsen
// 4/11/2017

/*
Problem Statement:
    Create a class called ArrayTools which will store a single integer array and each of the following functions.  Use my main function to run your class.

    Print – print the array values on the screen in order
    Find_min – search the array between two sizes to return the location of the minimum value in that part of the array
    Find_max –
    Find_sum – return the sum of all values in the array
    Num_even/odd – count the number of even and odd numbers in the array
    Search – search the array for a specified value and return the location if the value is found and -1 otherwise
    Is_sorted – check to see of the array is sorted in ascending order
    
Program Description:
    
    
Pseudocode:
    Create Class ArrayTools
        In private:
            array
        In public:
            Functions: 
            Print – print the array values on the screen in order
            Find_min – search the array between two sizes to return the location of the minimum value in that part of the array
            Find_max – search the array between two sizes to return the location of the maximum value in that part of the array
            Find_sum – return the sum of all values in the array
            Num_even/odd – count the number of even and odd numbers in the array
            Search – search the array for a specified value and return the location if the value is found and -1 otherwise
            Is_sorted – check to see of the array is sorted in ascending order
*/

#include <iostream>
using namespace std;

//Create Class ArrayTools
class ArrayTools {
    
    //In private: array
    private:
        
        int array_[10] = {0, 1, 2, 3, 4, 20, 0, -10}; //Number in brackets indicates number of array values. Using 20 for testing.
    
    public:
        
        //Print – print the array values on the screen in order
        void PrintFunct() {
            
            cout << "Array Values: ";
            
            for (int i = 0; i < 10; i++) { //Incrementing up each array. Note: i < 8 because the final array value is array_[7]
                cout << array_[i] << " ";
            }
        
        cout << endl; //Separates function
        }
        
        //Find_min – search the array between two sizes to return the location of the minimum value in that part of the array
        void Find_min() {
            
            int minVal = array_[0]; //minVal stores first value of array by default
            
            for (int i = 0; i < 10; i++) { //Incrementing up each array
                if (array_[i] <= minVal) { //Only stores new minVal when array is less
                    minVal = array_[i];
                }
            }
            cout << "Minimum: " << minVal << endl; //Final value
        }
        
        //Find_max – search the array between two sizes to return the location of the maximum value in that part of the array
        void Find_max() {
            
            int maxVal = array_[0]; //maxVal stores first value of array by default
            
            for (int i = 0; i < 10; i++) { //Incrementing up each array
                if (array_[i] >= maxVal) { //Only stores new maxVal when array is greater
                    maxVal = array_[i];
                }
            }
            cout << "Maximum: " << maxVal << endl; //Final value
        }
        
        //Find_sum – return the sum of all values in the array
        void SumFunct() {
            
            int sum = 0;
            
            for (int i = 0; i < 10; i++) { //Incrementing up each array
                sum = sum + array_[i]; 
            }
            
            cout << "Sum: " << sum << endl; //Final value
        }
        
        //Num_even/odd – count the number of even and odd numbers in the array
        void CountEvenOddFunct() {
            
            int numEven = 0;
            int numOdd = 0;
            
            for (int i = 0; i < 10; i++) {
                
                if (array_[i] % 2 == 0) {
                    numEven++;
                }
                
                else {
                    numOdd++;
                }
            }
            
            cout << "Number of even values: " << numEven << endl;
            cout << "Number of odd values: " << numOdd << endl;
        }
        
        //Search – search the array for a specified value and return the location if the value is found and -1 otherwise
        void SearchFunct() {
            
            int searchVal = 0;
            cout << "Input search value: ";
            cin >> searchVal;
            bool valFound = false;
            
            for (int i = 0; i < 10; i++) {
                
                if (array_[i] == searchVal) {
                    valFound = true;
                    cout << "Value located at: " << i << endl;
                }
            }
            
            if (valFound == false) {
                cout << -1 << endl;
            }
        }
        
        //Is_sorted – check to see of the array is sorted in ascending order
        void CheckSortingFunct() {
            
            bool arrayInOrder = true;
            
            for (int i = 0; i < 9; i++) {
                
                if (array_[i] > array_[i+1]) {
                    arrayInOrder = false;
                }
            }
            
            if (arrayInOrder == true) {
                cout << "Array is in ascending order." << endl;
            }
            
            else {
                cout << "Array is not in ascending order." << endl;
            }
        }
        
        ArrayTools();
};

ArrayTools::ArrayTools() {
    array_[10] = {0, 1, 2, 3, 4, 20, 0, -10};
    return;
}

int main()
{
    const int SIZE = 10;
    int myArray[SIZE];
    
    for(int i = 0; i<SIZE;i++){
        cin<<myArray[i];
    }
    ArrayTools a(myArray);
    
    a.Print();
    cout<<"Min: "<<a.Find_min(0, 4)<<endl;
    cout<<"Max: "<<a.Find_max(5, 10)<<endl;
    cout<<"Sum = "<<a.Find_sum()<<endl;
    cout<<"Search 10"<<a.Search(10)<<endl;
    cout<<"Sorted? "<<a.Is_sorted()<<endl;
    
    return 0;
}