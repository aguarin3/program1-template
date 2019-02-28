P = program1
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(P)


Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o

Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o

Vector.o: Vector.cpp Vector.h
	g++ $(CFLAGS) -c Vector.cpp -o Vector.o

List.o: List.cpp List.h
	g++ $(CFLAGS) -c List.cpp -o List.o

$(P).o: $(P).cpp Star.cpp Planet.cpp Vector.cpp List.cpp Star.h Planet.h Vector.h List.h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(P): Star.o Planet.o Vector.o List.o $(P).o
	g++ $(CFLAGS) Star.o Planet.o Vector.o List.o $(P).o -o $(P)

clean:
	rm -rf $(P).o Star.o Planet.o List.o Vector.o $(P)
run: all
	./$(P)

memcheck: all
	valgrind ./$(P)
