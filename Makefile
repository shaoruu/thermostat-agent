CC=g++
CFLAGS=
LDFLAGS=-lSDL2 -lSDL2_image

main: agent.o environment.o main.o
	$(CC) $(CFLAGS) -g *.o -o main $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -g $< $(LDFLAGS)