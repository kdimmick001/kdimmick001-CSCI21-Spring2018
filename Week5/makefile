templateexe: template.o lab_21_unit_test.o
	g++ -Wall -std=c++11 -g -o templateexe template.o lab_21_unit_test.o
	
template template.cpp template.h
	g++ -Wall -std=c++11 -g -c template.cpp template.h
	
lab21unittest: lab_21_unit_test.cpp
	g++ -Wall -std=c++11 -g -c lab_21_unit_test.cpp

boxexe: box.o challenge-21-unittest.o
	g++ -Wall -std=c++11 -g -o boxexe box.o challenge-21-unittest.o
	
box: box.cpp box.h
	g++ -Wall -std=c++11 -g -c box.cpp box.h
	
challenge21unittest: challenge-21-unittest.cpp
	g++ -Wall -std=c++11 -g -c challenge-21-unittest.cpp
	
clean:
	rm *.o *test