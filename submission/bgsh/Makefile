all: compile link run

compile: main.cpp bgsh.cpp bgsh_history.cpp bgsh_history.h bgsh.h
	echo "compiling..."
	mkdir -p bin
	g++ -c -o bin/main.o main.cpp
	g++ -c -o bin/bgsh.o bgsh.cpp
	g++ -c -o bin/bgsh_history.o bgsh_history.cpp


link: bin/main.o bin/bgsh.o bin/bgsh_history.o
	echo "linking..."
	g++ bin/main.o bin/bgsh.o bin/bgsh_history.o -o bin/bgsh

run: bin/bgsh
	echo "running..."
	bin/bgsh
