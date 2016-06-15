CC = g++
LINLIBS = -lm -lGL -lglut
MACLIBS = -framework OpenGL -framework GLUT

.PHONY: all apple linux
all: apple

apple:
	$(CC) -o main main.cpp $(MACLIBS) -Wno-deprecated-declarations
<<<<<<< Updated upstream

linux:
	$(CC) -o main main.cpp $(LINLIBS)
	./main
=======
	./main

linux:
	$(CC) -o main main.cpp $(LINLIBS)
>>>>>>> Stashed changes
