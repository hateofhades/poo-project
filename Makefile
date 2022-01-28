all:
	build, clean

clean:
	rm -f *.o main

build:
	g++ -c main.cpp ./Classes/QuestionPopup.cpp ./Classes/Button.cpp ./Classes/Maze.cpp ./Classes/QuestionMultipleAnswers.cpp ./Classes/QuestionCards.cpp ./Classes/QuestionWordSearch.cpp ./Classes/QuestionCards2.cpp
	g++ -o main main.o QuestionPopup.o Button.o Maze.o QuestionMultipleAnswers.o QuestionCards.o QuestionWordSearch.o QuestionCards2.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run: build
	./main
