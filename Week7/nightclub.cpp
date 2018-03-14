#include "nightclub.h"


		/*
		 * Add a customer to the waiting line/queue.
		 * @param customerName the name of the customer to add to the line/queue
		 */
		void NightClubLine::addCustomer (string customerName){
		    
		    //Pushes the customer name to the end of the queue to populate it with customer names.
		    waitingLine.push(customerName);
		    
		    return;
		};

		/*
		 * Get the name of the first customer (do not remove from the line).
		 * @return the name of the first customer in line
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string NightClubLine::getFirstCustomer () throw(logic_error){
		    
		    //Returns but does not remove the head item.
		    return (waitingLine.front());
		};

		/*
		 * Get the name of the last customer.
		 * @return the name of the last customer in line
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string NightClubLine::getLastCustomer () throw(logic_error){
		    
		    //Retunrs but does not remove the tail item.
		    return (waitingLine.back());
		};

		/*
		 * Remove the first customer in line.
		 * @return the name of the removed customer
		 * @throw std::logic_error("EMPTY QUEUE") if line is empty
		 */
		string NightClubLine::removeFirstCustomer () throw(logic_error){
		    //Dummy variable to hold the customer's name to be removed.
		    string customer;
		    
		    //Holds the name of the head item in customer.
		    customer = waitingLine.front();
		    
		    //Removes the head item.
		    waitingLine.pop();
		    
		    //Returns the name of the removed customer from the queue head.
		    return customer;
		};

		/* 
		 * Remove all customers from the line.
		 */
		void NightClubLine::clearLine (){
		    
		    //A loop for while the queue is not empty to remove each head element until the queue is empty.
		    while(!waitingLine.empty()){
		        waitingLine.pop();
		    }
		    
		    return;
		};

		/*
		 * Get the number of customer currently in line.
		 * @return the number of customers currently in line
		 */
		//uint32_t (error?)
		int NightClubLine::getNumCustomers (){
		    
		    //Returns the current size of the queue.
		    return waitingLine.size();
		};

		/*
		 * Check if the line is empty.
		 * @return true if the line is empty, else false
		 */
		bool NightClubLine::isEmpty (){
		    
		    //Checks if the queue is empty.
		    if (!waitingLine.empty()){
		        //If not empty.
		        return false;
		    } else {
		        //If empty.
		        return true;
		    }
		    
		};

		/*
		 * Load the contents of a file into the list. Assumes that the file 
		 * has one word per line. Will NOT clear the current contents of the 
		 * list.
		 * @param filename the name of the file to load
		 * @return true if the file is successfully processed, else false
		 */
		bool NightClubLine::processFile (string filename){
		    //Opens the file stream
		    ifstream fin;
		    
		    //Opens the file.
		    fin.open(filename.c_str());
		    
		    //A check to make sure that the desired file opened.
            if(!fin.is_open()){
                //If unable to open file.
                return false;
            }
            
            //A dummy variable to hold the file input string to store into the queue
            string word;
            
            //While it is not the end of the file.
            while (!fin.eof()){;
                //To get the whole line.
                getline(fin, word);
                //To add elements to the queue.
                waitingLine.push(word);
            }
            
            //After the file is successfully processed into the queue.
            return true;
		    
		};

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
		bool NightClubLine::processCommand (string cmd){
		    
		    //If the string is empty return false.
		    if (cmd.length() == 0){
		        return false;
		    }
            
            stringstream ssin;
            
            //Creates variables to hold the string streams sorted information.
    		char letter;
    		string word;
    		
    		ssin.str(cmd);
    		
    		//Sorts the string streams information into the appropriate variables.
    		ssin >> letter >>  word;

			if (((letter == 'A') || (letter == 'a')) && (word.length() > 2)){
				addCustomer(word);
			}
			else if ((letter == 'C') || (letter == 'c')){
				clearLine();
			}
			else if ((letter == 'R') || (letter == 'r')){
				removeFirstCustomer();
			}
			else {
				return false;
			}
            
            return true;
		    
		};