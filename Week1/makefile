lab2exe: lab_2.o
	g++ -Wall -std=c++11 -g -o lab2exe lab_2.o
	
lab2: lab_2.cpp lab_2.h
	g++ -Wall -std=c++11 -g -c lab_2.cpp lab_2.h

lab3exe: lab_3.o
	g++ -Wall -std=c++11 -g -o lab3exe lab_3.o

lab3: lab_3.cpp lab_3.h
	g++ -Wall -std=c++11 -g -c lab_3.cpp lab3.h
	
lab4exe: lab_4.o lab_4_unit_test.o
	g++ -Wall -std=c++11 -g -o lab4exe lab_4.o lab_4_unit_test.o
	
lab4: lab_4.cpp lab_4.h
	g++ -Wall -std=c++11 -g -c lab_4.cpp lab_4.h
	
unittest4: lab_4_unit_test.cpp
	g++ -Wall -g -c lab_4_unit_test.cpp
	
clean:
	rm *.o *test