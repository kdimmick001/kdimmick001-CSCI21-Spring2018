moneyexe: lab_11_unit_test.o money.o
	g++ -Wall -g -o moneyexe money.o lab_11_unit_test.o
	
itemexe: lab_12_unit_test.o item.o
	g++ -Wall -g -o itemexe item.o lab_12_unit_test.o
	
fooditemexe: lab_12_unit_test.o food_item.o
	g++ -Wall -g -o fooditemexe food_item.o lab_12_unit_test.o
	
magicitemexe: lab_12_unit_test.o magic_item.o
	g++ -Wall -g -o magicitemexe magic_item.o lab_11_unit_test.o

money: money.cpp money.h
	g++ -Wall -g -c money.cpp money.h
	
item: item.cpp item.h
	g++ -Wall -g -c item.cpp item.h
	
fooditem: food_item.cpp food_item.h
	g++ -Wall -g -c food_item.cpp food_item.h

magicitem: magic_item.cpp magic_item.h
	g++ -Wall -g -c magic_item.cpp magic_item.h

unittest11: lab_11_unit_test.cpp 
	g++ -Wall -g -c lab_11_unit_test.cpp
	
unittest12: lab_12_unit_test.cpp
	g++ -Wall -g -c lab_12_unit_test.cpp

clean:
	rm *.o *test