start : a.out
	./a.out



a.out: main.o kolejka.o kolejka.h
	g++ main.o 

main.o: main.cpp
	g++ -c -Wall -pedantic main.cpp

kolejka.o: kolejka.cpp
	g++ -c -Wall -pedantic kolejka.cpp

clean:
	rm -f *.o
	rm -f *.out
