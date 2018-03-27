 #include <string>
 #include <sstream>
 #include <vector>
 using namespace std;
 
  
template<typename type>
string PrepareForDisplay(vector<type> values, int size, char separator);
 
/*
 * Function Name: HasValue
 * Test to see if an array contains a specified value.
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @param T value_to_find - The value to search for within the array
 * @return bool - true of value is found in the array, otherwise false
*/

template<typename type>
bool HasValue(vector<type> values, int size, type value_to_find);
  
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
type ValueAt(vector<type> values, int size, int index, bool &error);

/*
 * Function Name: Sum
 * Return the "sum" of the vaues in the array.
 * Your initial sum should be set to "zero" in your algorithm. To do this use T().
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
*/

template<typename type>
type Sum(vector<type> values, int size);

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
bool SwapValues(vector<type> values, int size, int index1, int index2);