/**********************************************/
/***** Programming Challenge 13      SPEC *****/
/**********************************************/

#include <cstdint>
#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

#ifndef PROG_13_H
#define PROG_13_H

/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value the value for which the factorial will be computed
 * @return the computed factorial of the value
 */
uint32_t factorial (uint32_t value);

/*
 * Return a specified value in a Fibonacci sequence, using a recursive algorithm. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue specifies which value in the Fibonacci sequence to return
 * @return the requested value in the Fibonacci sequence
 */
uint32_t fibonacci (uint32_t fibValue);

/*
 * Test a single word to see if it is a palindrome, using a recursive algorithm. The word must be all in the same case 
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool wordIsPalindrome (string word);

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
string vectorForwardsAsString (const vector<uint32_t>& v, uint32_t startIndex);

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
string vectorBackwardsAsString (const vector<uint32_t>& v, uint32_t startIndex);

#endif