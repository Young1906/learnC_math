all: src/mat.h src/test.c
	g++ -o ./bin/main src/test.c src/mat.h

test:
	./bin/main
