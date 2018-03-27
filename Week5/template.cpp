/*
 * Name         :   template.cpp
 * Author       :   Kelsey Dimmick
 * Description  :   Various functions using templates.
 *                  Please note you can just write the definitions in here.
 *                  No need for prototypes.
 */
 
#include "template.h"
 
/*
 * Function Name: PrepareForDisplay
 * Create a string containing the contents of an array, each element separated
 * by a specified character.
 * For example, if the array contents are {1, 2, 3} and the separator character is ':',
 * the string returned will be "1:2:3". Please note the array can be of any type.
 * If the template function outputs doubles, they should be to a precision of 2.
 * @uses stringstream
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @param char separator - The separator character to use in the returned string. Defaults to ','
 * @return string - A string containing the contents of values separated by the sepcified separator character
 */
 
template<typename type>
string PrepareForDisplay(vector<type> values, int size, char separator){
    stringstream ss;
    
    string display;
    
    for(int i = 0; i < size; ++i){
        ss >> values.at(i) >> separator;
    }
    
    display = ss.str();
    
    return display;
};
 
/*
 * Function Name: HasValue
 * Test to see if an array contains a specified value.
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @param T value_to_find - The value to search for within the array
 * @return bool - true of value is found in the array, otherwise false
*/

template<typename type>
bool HasValue(vector<type> values, int size, type value_to_find) {
    
    bool validity;
    
    for(int i = 0; i < size; ++i) {
        if(values.at(i) == value_to_find){
            validity = true;
        } else {
            validity = false;
        }
    }
    
    return validity;
};
  
/*
 * Function Name: ValueAt
 * Return the value from an array at a specified index.
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index - The position in the array from which to return a value
 * @param bool &error - A flag that will set to true if index is invalid for the array,
 * else it will be set to false
 * @return T - The value at the specified index in the array when error is set to false.
 * if index is invalid, returns a zero representation of the type and set error to true.
 * To get a zero representation you can return T()
*/

template<typename type>
type ValueAt(vector<type> values, int size, int index, bool &error){
    
    if (values.at(index) == true){
        error = false;
        return values.at(index);
    } else if (values.at(index) == false){
        error = true;
        return values();
    }
    
};

/*
 * Function Name: Sum
 * Return the "sum" of the vaues in the array.
 * Your initial sum should be set to "zero" in your algorithm. To do this use T().
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
*/

template<typename type>
type Sum(vector<type> values, int size){
    type sum = values();
    
    for (int i = 0; i < size; ++i) {
        sum = sum + values.at(i);
    }
    
    return sum;
};

/*
 * Function Name: SwapValues
 * Swap the positions of the two values in an array.
 * The two index values must be valid for the array.
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index1 - The position of the first value to be swapped
 * @param unsigned int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
*/

template<typename type>
bool SwapValues(vector<type> values, int size, int index1, int index2) {
    type dummy1;
    type dummy2;
    
    dummy1 = values.at(index1);
    dummy2 = values.at(index2);
    values.at(index1) = dummy2;
    values.at(index2) = dummy1;
    
    if ((dummy1 == values.at(index1)) && (dummy2 == values.at(index2))) {
        return true;
    } else {
        return false;
    }
    
};