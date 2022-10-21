all: compile run

compile: src/main.cpp
	echo "compiling..."
	gcc src/main.cpp -o bin/bgsh

run: bin/bgsh
	echo "running..."
	bin/bgsh
