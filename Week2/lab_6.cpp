/*
 * Name        : lab_6.cpp
 * Author      : Kelsey Dimmick
 * Description : Working with Arrays
 */

#include "lab_6.h"

// CODE HERE (FUNCTION DEFINITIONS)
/*
 * Name        : lab_6.cpp
 * Author      : Luke Sathrum
 * Description : Header File for Lab #6. DO NOT ALTER!
 */


/*
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3".
 * @uses stringstream
 * @param int values[] - An array of integers
 * @param int size - The size of the integer array
 * @param char separator - The separator character to use in the returned
 *                         string.
  *                        Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
string PrepareForDisplay(int values[], int size, char separator = ','){
    
    stringstream ssin;
    
    for (int i = 0; i < (size - 1); ++i){
        ssin << values[i] << separator;
    }
    ssin << values[size - 1];
    
    return ssin.str();
};

/*
 * Test to see if an array contains a specified value.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int value - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
bool HasValue(int values[], int size, int value){
    bool question;
    
    for (int i = 0; i < size; ++i){
        if (values[i] == value){
            question = true;
            return question;
        } else {
            question = false;
        }
    }
    
    return question;
    
};

/*
 * Return the value from an array at a specified index.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int index - The position in the array from which to return a value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                      the array, else it will be set to false
 * @return int - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns 0 and sets error to true
 */
int ValueAt(int values[], int size, int index, bool &error){
    
    if (index < size){
    
        if (values[index] != true){
            error = false;
        
            return values[index];
        
        } else if (values[index] == false){
            error = true;
        
        }
    }
    return 0;
};

/*
 * Return the sum of the values in an integer array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @return int - The sum of the values in the array
 */
int Sum(int values[], int size){
    int sum = 0;
    
    for (int i = 0; i < size; ++i){
        sum = sum + values[i];    
    }
    
    return sum;
};

/*
 * Swap the positions of two values in an integer array. The two
 * index values must be valid for the array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @param int index1 - The position of the first value to be swapped
 * @param int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
bool SwapValues(int values[], int size, int index1, int index2){

    int x;
    int y;
   
   if ((index1 < size) && (index2 < size)){
       if ((index1 >= 0) && (index2 >= 0)){
            x = values[index1];
            y = values[index2];
    
            values[index2] = x;
            values[index1] = y;
    
            if ((values[index2] == x) && (values[index1] == y)){
                return true;
            }else{
                return false;
            }
        }
   }
   return false;
};