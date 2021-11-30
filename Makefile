all:
	build, clean

clean:
	rm -f *.o

build:
	g++ -c main.cpp
	g++ -o main main.o -lsfml-graphics -lsfml-window -lsfml-system
