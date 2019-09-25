all : compile
compile: test.cpp
	g++ -ldl test.cpp
clean:
	-rm ./a.out

help:
	# make: compile all c and cpp files
	# make example: compile example.c*
	# you can modify this makefile
