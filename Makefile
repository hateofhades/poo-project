all:
	build, clean

clean:
	rm -f *.o main

build:
	g++ -c main.cpp ./Classes/QuestionPopup.cpp ./Classes/Button.cpp ./Classes/Maze.cpp
	g++ -o main main.o QuestionPopup.o Button.o Maze.o -lsfml-graphics -lsfml-window -lsfml-system

run: build
	./main
