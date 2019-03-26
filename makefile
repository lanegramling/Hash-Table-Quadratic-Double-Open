lab3: main.o
	g++ -std=c++11 -g -Wall main.o -o lab3
main.o: main.cpp HashDouble.h HashDouble.hpp HashQuadraticProbing.h HashQuadraticProbing.hpp Bucket.h Bucket.hpp
	g++ -std=c++11 -g -Wall -c main.cpp
clean:
	rm *.o lab3
