/**********************************************/
/***** Programming Challenge 16      SPEC *****/
/**********************************************/

#include "prog_16.h"

		/*
		 * Default constructor.
		 * Initializes count to 0.
		 */
Word::Word (){
	count = 0;
	return;
};

		/*
		 * Overloaded constructor.
		 * Initializes word to newWord and count to 1. Uses upper to ensure 
		 * words is all uppercase.
		 */
Word::Word(string newWord){
	count = 1;
	word = neWord;
	word = upper(word);
	return;
};

		/*
		 * Destructor.
		 * Included for completeness. Does nothing.
		 */
//virtual Word::~Word ();
		
		/*
		 * Set this Word object's word.
		 * @param newWord a new value for this Word object's word. Uses upper 
		 * to ensure words is all uppercase.
		 */
void Word::setWord (string newWord){
	word = upper(newWord);
	return;
};
		
		/*
		 * Get this Word object's word.
		 * @return the value of this Word object's word.
		 */
string Word::getWord () const{
	return word;	
};
		
		/*
		 * Get this Word object's count.
		 * @return this Word object's count.
		 */
uint32_t Word::getCount () const{
	return count;
};
		
		/*
		 * Increment this Word object's count (i.e., increase count by 1).
		 */
void Word::incrementCount (){
	count = count + 1;
	return;
};
		
		/*
		 * Compare this Word object with another Word object to see if their word values 
		 * are equivalent.
		 * @return true if the (case-insensitive) word values of both Word objects 
		 *         are equivalent; else return false.
		 */
bool Word::operator== (const Word& target){
	if (word == target){
		return true;
	} else {
		return false;
	}
};

		/*
		 * Compare this Word object with another Word object to see if this Word object's 
		 * word value comes (lexicographically) after the other Word object's word value.
		 * @return true if the (case-insensitive) word value of this Word object 
		 *         comes (lexicographically) after the word value of the other Word object.
		 */
bool Word::operator> (const Word& target){
	int pos = 0;
	if (word.at(pos) > target.at(pos)){
		return false;
	} else if (word.at(pos) < target.at(pos)){
		return true;
	} else if (word.at(pos) == target.at(pos)){
		++pos;
	}
};

		/*
		 * Compare this Word object with another Word object to see if this Word object's 
		 * word value comes (lexicographically) before the other Word object's word value.
		 * @return true if the (case-insensitive) word value of this Word object 
		 *         comes (lexicographically) before the word value of the other Word object.
		 */
bool Word::operator< (const Word& target){
	int pos = 0;
	if (word.at(pos) > target.at(pos)){
		return true;
	} else if (word.at(pos) < target.at(pos)){
		return false;
	} else if (word.at(pos) == target.at(pos)){
		++pos;
	}
};
		
		/*
		 * Print this Word object on an output stream.
		 * Displays the word value, followed by a space, followed by the count..
 		 *
 		 * EXAMPLE: "APPLE 2"
 		 *
		 * @return the output stream with this Word object's data inserted
		 */
friend ostream& Word::operator<< (ostream& outs, const Word& src){
	return cout << outs << " " << src;
};