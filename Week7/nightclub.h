#include <fstream>
#include <queue>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
using namespace std;

#ifndef NIGHT_CLUB_H
#define NIGHT_CLUB_H

class NightClubLine {
	public:

		/*
		 * Add a customer to the waiting line/queue.
		 * @param customerName the name of the customer to add to the line/queue
		 */
		void addCustomer (string customerName);

		/*
		 * Get the name of the first customer (do not remove from the line).
		 * @return the name of the first customer in line
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string getFirstCustomer () throw(logic_error);

		/*
		 * Get the name of the last customer.
		 * @return the name of the last customer in line
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string getLastCustomer () throw(logic_error);

		/*
		 * Remove the first customer in line.
		 * @return the name of the removed customer
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string removeFirstCustomer () throw(logic_error);

		/* 
		 * Remove all customers from the line.
		 */
		void clearLine ();

		/*
		 * Get the number of customer currently in line.
		 * @return the number of customers currently in line
		 */
		//uint32_t (error?)
		int getNumCustomers ();

		/*
		 * Check if the line is empty.
		 * @return true if the line is empty, else false
		 */
		bool isEmpty ();

		/*
		 * Load the contents of a file into the list. Assumes that the file 
		 * has one word per line. Will NOT clear the current contents of the 
		 * list.
		 * @param filename the name of the file to load
		 * @return true if the file is successfully processed, else false
		 */
		bool processFile (string filename);

		/*
		 * NOTE: This function would normally be private but is left public
		         to expose it for unit testing.
		 *
         * Process a single command and perform the appropriate operation on 
         * the line. If command string is empty, returns false, otherwise execute 
         * the operation.
         *
         * COMMAND      :: COMMAND REQUIREMENT	 :: EXPLANATION
         *
         * A apple		:: minimum 3 characters	 :: addCustomer named "apple" to the line
         * a apple      :: SAME
         * C            :: exactly one character :: clearLine
         * c            :: SAME
         * R            :: exactly one character :: removeFirstCustomer (ignore return value)
         * r            :: SAME
         *
         * @return true if command is recognized and format is valid, else false
		 */
		bool processCommand (string cmd);

	private:
		queue<string> waitingLine;
};

#endif