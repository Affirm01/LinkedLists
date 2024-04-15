#	Makefile that compiles and runs LinkedList program
#  	Author: Ethan Smith
# 	CPSC 1070 - Spring 2024
#	Lab 06 Phase C

compile:
	g++ List.cpp -Wall -c
	g++ List.o main.cpp -Wall -o LinkedList.exe

run:
	./LinkedList.exe

clean:
	rm ./LinkedList.exe
	rm ./List.o
	rm ./*~