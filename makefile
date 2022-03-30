all: lab2

lab2: lab2.o primlib.o
	gcc -g $^ -o $@  -lSDL2_gfx -lm `sdl2-config --libs`

.c.o: 
	gcc -g -Wall -pedantic `sdl2-config --cflags` -c  $<

primlib.o: primlib.c primlib.h

testlib.o: lab2.c primlib.h

clean:
	-rm primlib.o testlib.o testlib
