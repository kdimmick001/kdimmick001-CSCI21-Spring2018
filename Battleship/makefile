battleshipexe: battleship.o gameboard_class.o player_class.o rowcol_function.o
	g++ -Wall -std=c++11 -g -o battleshipexe battleship.o gameboard_class.o player_class.o rowcol_function.o
	
battleship: battleship.cpp 
	g++ -Wall -std=c++11 -g -c battleship.cpp
	
gameboard_class: gameboard_class.cpp
	g++ -Wall -std=c++11 -g -c gameboard_class.cpp 

player_class: player_class.cpp 
	g++ -Wall -std=c++11 -g -c player_class.cpp 
	
rowcol_function: rowcol_function.cpp
	g++ -Wall -std=c++11 -g -c rowcol_function.cpp 
	
clean:
	rm *.o *test