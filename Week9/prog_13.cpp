/**********************************************/
/***** Programming Challenge 13      SPEC *****/
/**********************************************/

#include "prog_13.h"

/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value the value for which the factorial will be computed
 * @return the computed factorial of the value
 */
uint32_t factorial (uint32_t value){
    if (value == 0){
        return 1;
    }
    if (value > 0){
        value = value * factorial(value - 1);
    }
    return value;
};

/*
 * Return a specified value in a Fibonacci sequence, using a recursive algorithm. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue specifies which value in the Fibonacci sequence to return
 * @return the requested value in the Fibonacci sequence
 */
uint32_t fibonacci(uint32_t fibValue){
    if (fibValue == 1){
        return 1;
    } else {
        return fibonacci(fibValue - 1) + fibonacci(fibValue - 2);
    }
};

/*
 * Test a single word to see if it is a palindrome, using a recursive algorithm. The word must be all in the same case 
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool wordIsPalindrome (string word){
    if (word.at(0) == word.at(word.size())){
        word.erase(0);
        word.erase(word.size());
        wordIsPalindrome(word);        
    } else {
        return false;
    }
    return true;
    
};

/*
 * Produce a string containing the contents of a vector<int32_t>, separated by single spaces, 
 * starting at a specified index and going forward to the end of the vector, using a recursive algorithm. The returned 
 * string will contain an extra space character after the last value added.
 * @param v a vector containing the values to be added to the string
 * @param startIndex the index of the first value in the vector to be added
 *        to the output string
 * @return a string containing the contents of the vector, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the vector
 */
string vectorForwardsAsString (const vector<uint32_t>& v, uint32_t startIndex){
    if (startIndex >= v.size()){
        return "";
    } else {
        
        return vectorForwardsAsString(&v, v.at((v.begin()++))) + " ";
    }
};

/*
 * Produce a string containing the contents of a vector<int32_t>, separated by single spaces, 
 * starting at a specified index and going backward to the start of the vector, using a recursive algorithm. The returned 
 * string will contain an extra space character after the last value added.
 * @param v a vector containing the values to be added to the string
 * @param startIndex the index of the first value in the vector to be added
 *        to the output string
 * @return a string containing the contents of the vector, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the vector
 */
string vectorBackwardsAsString (const vector<uint32_t>& v, uint32_t startIndex){
  if (startIndex >= v.size()){
      return "";
  }  else {
      return vectorBackwardsAsString(&v, v.at((v.end()--))) + " ";
  }
};