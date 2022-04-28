default: dist/main 

dist/main: dist build/main.o build/Source.o build/Parser.o
	gcc -o dist/main build/main.o build/Source.o build/Parser.o

build/main.o: build src/main.c
	gcc -o build/main.o -c src/main.c

build/Source.o: build src/Source.c
	gcc -o build/Source.o -c src/Source.c

build/Parser.o: build src/Parser.c
	gcc -o build/Parser.o -c src/Parser.c

build:
	mkdir build 

dist:
	mkdir dist