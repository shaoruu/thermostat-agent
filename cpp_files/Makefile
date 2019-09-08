CC=g++
CFLAGS=
LDFLAGS=-lSDL2 -lSDL2_image

main: agent.o texture.o environment.o thermo.o timer.o main.o
	$(CC) $(CFLAGS) -g *.o -o main $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -g $< $(LDFLAGS)