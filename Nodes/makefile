#creates the executable from both the object files
nodeclassexe: stack_test.o
	g++ -Wall -g -o nodeclassexe stack_test.o

#creates the lab2 object file
#nodeclass: node_class.cpp  
#	g++ -Wall -g -c node_class.cpp

# creates the unit test object file
unittest: stack_test.cpp
	g++ -Wall -g -c stack_test.cpp

#cleans up old .o files	
clean:
	rm *.o *test 
