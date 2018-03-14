stackexe: stack.o
	g++ -Wall -std=c++11 -g -o stackexe stack.o
	
stack: stack.cpp 
	g++ -Wall -std=c++11 -g -c stack.cpp
	
queueexe: queue.o
	g++ -Wall -std=c++11 -g -o queueexe queue.o 

queue: queue.cpp 
	g++ -Wall -std=c++11 -g -c queue.cpp 
	
nightclubexe: nightclub.o nightclub_unit_test.o
	g++ -Wall -std=c++11 -g -o nightclubexe nightclub.o nightclub_unit_test.o
	
nightclub: nightclub.cpp
	g++ -Wall -std=c++11 -g -c nightclub.cpp
	
nightclubunittest: nightclub_unit_test.cpp
	g++ -Wall -std=c++11 -g -c nightclub_unit_test.cpp
	
clean:
	rm *.o *test