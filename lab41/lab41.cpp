// Bjorn Larsen
// 4/11/2017

/*
Program Description:
    This function has a user enter 10 values into an array, and then uses a class to perform a variety of tests on the array. Program first prints array values, then
    tests for minimums from 0-4, tests for maximums from 5-10, finds the sum of the array, counts number of odd and even numbers respectively, search for a specific value
    of 10 within the array, and checks to see if the array values are sorted in ascending order.
    
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
            Constructor
*/

#include <iostream>
using namespace std;

//Create Class ArrayTools
class ArrayTools {
    
    //In private: array
    private:
        
        int array_[10]; //SIZE = 10 therefore array_[10]
    
    public:
        
        //Print – print the array values on the screen in order
        void Print() {
            
            cout << "Array Values: ";
            
            for (int i = 0; i < 10; i++) { //For each array value incrementing up
                cout << array_[i] << " "; //The value is output
            }
        
        cout << endl; //Separates function
        }
        
        //Find_min – search the array between two sizes to return the location of the minimum value in that part of the array
        int Find_min(int j, int k) { //j = 0, k = 4
            
            int minVal = array_[0]; //minVal stores first value of array by default
            
            for (int i = j; i <= k; i++) { //Incrementing through 0 - 4
                if (array_[i] <= minVal) { //When array is less than previous minVal
                    minVal = array_[i]; //New minVal is stored
                }
            }
            return minVal; //Final value is output
        }
        
        //Find_max – search the array between two sizes to return the location of the maximum value in that part of the array
        int Find_max(int j, int k) { //j = 5, k = 10
            
            int maxVal = array_[0]; //maxVal stores first value of array by default
            
            for (int i = j; i < k; i++) { //Incrementing up each array
                if (array_[i] >= maxVal) { //When array is greater than previous maxVal
                    maxVal = array_[i]; //New maxVal is stored
                }
            }
            return maxVal; //Final value
        }
        
        //Find_sum – return the sum of all values in the array
        int Find_sum() {
            
            int sum = 0;
            
            for (int i = 0; i < 10; i++) { //For each array value incrementing up
                sum = sum + array_[i]; //Array value is added to total sum
            }
            
            return sum; //Final value
        }
        
        //Num_even/odd – count the number of even and odd numbers in the array
        void Num_even_odd() {
            
            int numEven = 0;
            int numOdd = 0;
            
            for (int i = 0; i < 10; i++) { //For each array value incrementing up
                
                if (array_[i] % 2 == 0) { //Tests if array value is divisible by 2
                    numEven++; //If so numEven is increased
                }
                
                else {
                    numOdd++; //If not numOdd is increased
                }
            }
            
            cout << "Number of even values: " << numEven << endl;
            cout << "Number of odd values: " << numOdd << endl;
            
            return;
        }
        
        //Search – search the array for a specified value and return the location if the value is found and -1 otherwise
        int Search(int searchVal) { //searchVal = 10
            
            for (int i = 0; i < 10; i++) { //For each array value incrementing up
                if (array_[i] == searchVal) { //Once the specified value is found
                    return i; //The value is output
                }
            }
            
            return -1; //-1 signifies value was not found in the array
        }
        
        //Is_sorted – check to see of the array is sorted in ascending order
        char Is_sorted() {
            
            bool arrayInOrder = true;
            
            for (int i = 0; i < 9; i++) { //Final array value isn't tested
                
                if (array_[i] > array_[i+1]) { //Each array value is being compared to the one after it
                    arrayInOrder = false;
                }
            }
            
            if (arrayInOrder == true) {
                return 'Y';
            }
            
            else {
                return 'N';
            }
        }
        
        //Constructor
        ArrayTools(int myArray[]) { //Initialize as myArray[] no braces would cast as type int*
            
            for (int i = 0; i < 10; i++) {
                array_[i] = myArray[i]; //Each main array value being transfered to class array value part by part
            }
            
            return;
        }
};

int main()
{
    const int SIZE = 10;
    int myArray[SIZE];
    
    for(int i = 0; i<SIZE;i++){
        cin>>myArray[i];
    }
    
    ArrayTools a(myArray);
    
    a.Print();
    cout<<"Min: "<<a.Find_min(0, 4)<<endl;
    cout<<"Max: "<<a.Find_max(5, 10)<<endl;
    cout<<"Sum = "<<a.Find_sum()<<endl;
    a.Num_even_odd(); //Added manually to main
    cout<<"Search 10: "<<a.Search(10)<<endl;
    cout<<"Sorted? "<<a.Is_sorted()<<endl;
    
    return 0;
}