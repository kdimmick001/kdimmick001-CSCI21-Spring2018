/**********************************************/
/***** Programming Challenge 16 UNIT TEST *****/
/**********************************************/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <sstream>
using std::ostringstream;
using std::streambuf;

/*
 * Unit tests. Do not alter.
 */
TEST_CASE ("Word class") {

	ostringstream outs;

	SECTION("Default constructor") {
		Word word1;

		CHECK(word1.getWord() == "");
		CHECK(word1.getCount() == 0);

		outs << word1;
		CHECK(outs.str() == " 0");
		outs.str("");

		word1.setWord("apple");
		CHECK(word1.getWord() == "APPLE");

		word1.incrementCount();
		CHECK(word1.getCount() == 1);

		outs << word1;
		CHECK(outs.str() == "APPLE 1");
		outs.str("");
	}

	SECTION("Overloaded constructor") {
		Word word1("apple");

		CHECK(word1.getWord() == "APPLE");
		CHECK(word1.getCount() == 1);

		outs << word1;
		CHECK(outs.str() == "APPLE 1");
		outs.str("");
	}

	SECTION("Overloaded operators") {
		Word word1("apple");
		Word word2("banana");

		CHECK((word1 > word2) == false);
		CHECK((word1 < word2) == true);
		CHECK((word1 == word2) == false);

		word2.setWord("apple");

		CHECK((word1 == word2) == true);
	}
}