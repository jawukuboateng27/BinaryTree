FLAGS = -g -Wall -O0 -pedantic-errors

compile: main

main: BinaryTree.h BinaryTree.cpp main.cpp
	g++ $(FLAGS) -o main BinaryTree.h BinaryTree.cpp main.cpp

run:
	./main int-input1.txt

clean:
	rm main
