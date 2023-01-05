all: pastel/pastel discolored/discolored colorstr/colorstr

pastel/pastel: pastel/pastel.cpp
	g++ -Wall -std=c++11 -o pastel/pastel pastel/pastel.cpp

discolored/discolored: discolored/discolored.cpp
	g++ -Wall -std=c++11 -o discolored/discolored discolored/discolored.cpp

colorstr/colorstr: colorstr/colorstr.cpp
	g++ -Wall -std=c++11 -o colorstr/colorstr colorstr/colorstr.cpp

.PHONY: clean
clean:
	rm pastel/pastel discolored/discolored colorstr/colorstr

