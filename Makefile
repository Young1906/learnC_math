det: src/mat.h src/det.c
	g++ -o lib/det.o src/det.c src/mat.h

prime_factor: src/primeFactor.c
	g++ -o bin/primefactor ./src/primeFactor.c

all: src/mat.h src/test.c src/det.c
	g++ -o ./bin/main src/test.c src/mat.h src/det.c

test:
	./bin/main
