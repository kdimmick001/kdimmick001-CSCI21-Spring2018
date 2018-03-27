lab7exe: lab_7.o lab_7_unit_test.o lab_8_unit_test.o
	g++ -Wall -std=c++11 -g -o lab7exe lab_7.o lab_7_unit_test.o lab_8_unit_test.o
	
lab7: lab_7.cpp lab_7.h
	g++ -Wall -std=c++11 -g -c lab_7.cpp lab_7.h
	
lab7unittest: lab_7_unit_test.cpp
	g++ -Wall -std=c++11 -g -c lab_7_unit_test.cpp
	
lab8unittest: lab_8_unit_test.cpp
	g++ -Wall -std=c++11 -g -c lab_8_unit_test.cpp

musicalchairsxe: musical_chairs.o
	g++ -Wall -std=c++11 -g -o musicalchairsexe musical_chairs.o
	
musicalchairs: musical_chairs.cpp 
	g++ -Wall -std=c++11 -g -c musical_chairs.cpp
	
reverseargsexe: reverseArgs.o
	g++ -Wall -std=c++11 -g -o reverseargsexe reverseArgs.o
	
reverseargs: reverseArgs.cpp
	g++ -Wall -std=c++11 -g -c reverseArgs.cpp
	
studentlistexe: student_list.o
	g++ -Wall -std=c++11 -g -o studentlistexe student_list.o
	
studentlist: student_list.cpp
	g++ -Wall -std=c++11 -g -c student_list.cpp
	
clean:
	rm *.o *test