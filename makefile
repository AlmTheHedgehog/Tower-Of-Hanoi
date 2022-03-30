all: lab2

lab2: lab2.o primlib.o controller.o graphics.o 
	gcc -fsanitize=undefined -g $^ -o $@  -lSDL2_gfx `sdl2-config --libs` -lm

.c.o: 
	gcc -fsanitize=undefined -g -Wall -pedantic `sdl2-config --cflags` -c  $<

primlib.o: primlib.c primlib.h

testlib.o: lab2.c primlib.h

controller.o: controller.c controller.h

graphics.o: graphics.c graphics.h

clean:
	-rm primlib.o testlib.o controller.o graphics.o testlib