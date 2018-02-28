lab6exe: lab_6.o lab_6_unit_test.o
	g++ -Wall -std=c++11 -g -o lab6exe lab_6.o lab_6_unit_test.o
	
lab6: lab_6.cpp lab_6.h
	g++ -Wall -std=c++11 -g -c lab_6.cpp lab_6.h

unittest6: lab_6_unit_test.cpp
    g++ -Wall -std=c++11 -g -c lab_6_unit_test.cpp

lab10exe: lab_10.o lab_10_unit_test.o
	g++ -Wall -std=c++11 -g -o lab10exe lab_10.o lab_10_unit_test.o

lab10: lab_10.cpp lab_10.h
	g++ -Wall -std=c++11 -g -c lab_10.cpp lab10.h
	
unittest10: lab_10_unit_test.cpp
    g++ -Wall -std=c++11 -g -c lab_10_unit_test.cpp
	
clean:
	rm *.o *test