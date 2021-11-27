all:
	build, clean

build:
	gcc main.cpp -o main $(pkg-config allegro-5 allegro_font-5 --libs --cflags)

clean:
	rm *.o main
