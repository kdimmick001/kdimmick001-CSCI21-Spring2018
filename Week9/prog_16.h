/**********************************************/
/***** Programming Challenge 16      SPEC *****/
/**********************************************/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef PROG_16_H
#define PROG_16_H


class Word
{
	public:
	
		/*
		 * Default constructor.
		 * Initializes count to 0.
		 */
		Word ();

		/*
		 * Overloaded constructor.
		 * Initializes word to newWord and count to 1. Uses upper to ensure 
		 * words is all uppercase.
		 */
		Word (string newWord);

		/*
		 * Destructor.
		 * Included for completeness. Does nothing.
		 */
		virtual ~Word ();
		
		/*
		 * Set this Word object's word.
		 * @param newWord a new value for this Word object's word. Uses upper 
		 * to ensure words is all uppercase.
		 */
		void setWord (string newWord);
		
		/*
		 * Get this Word object's word.
		 * @return the value of this Word object's word.
		 */
		string getWord () const;
		
		/*
		 * Get this Word object's count.
		 * @return this Word object's count.
		 */
		uint32_t getCount () const;
		
		/*
		 * Increment this Word object's count (i.e., increase count by 1).
		 */
		void incrementCount ();
		
		/*
		 * Compare this Word object with another Word object to see if their word values 
		 * are equivalent.
		 * @return true if the (case-insensitive) word values of both Word objects 
		 *         are equivalent; else return false.
		 */
		bool operator== (const Word& target);

		/*
		 * Compare this Word object with another Word object to see if this Word object's 
		 * word value comes (lexicographically) after the other Word object's word value.
		 * @return true if the (case-insensitive) word value of this Word object 
		 *         comes (lexicographically) after the word value of the other Word object.
		 */
		bool operator> (const Word& target);

		/*
		 * Compare this Word object with another Word object to see if this Word object's 
		 * word value comes (lexicographically) before the other Word object's word value.
		 * @return true if the (case-insensitive) word value of this Word object 
		 *         comes (lexicographically) before the word value of the other Word object.
		 */
		bool operator< (const Word& target);
		
		/*
		 * Print this Word object on an output stream.
		 * Displays the word value, followed by a space, followed by the count..
 		 *
 		 * EXAMPLE: "APPLE 2"
 		 *
		 * @return the output stream with this Word object's data inserted
		 */
		friend ostream& operator<< (ostream& outs, const Word& src);
		
	private:
	
		string word;
		uint32_t count;
		
		/*
		 * Return the uppercase version of a string.
		 * @param s the string to be converted to uppercase
		 * @return the uppercase version of the parameter
		 */
		string upper (string s);
};

#endif