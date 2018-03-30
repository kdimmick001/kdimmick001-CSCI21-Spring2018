#creates the executable from both the object files
nodeclassexe: test.o node_class.o 
	g++ -Wall -g -o nodeclassexe test.o node_class.o

#creates the lab2 object file
nodeclass: node_class.cpp  
	g++ -Wall -g -c node_class.cpp

# creates the unit test object file
unittest: test.cpp 
	g++ -Wall -g -c test.cpp	

#cleans up old .o files	
clean:
	rm *.o *test 
