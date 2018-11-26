CC = clang++
CFLAG = -std=c++11 -Wall

main: ver1.cpp
	$(CC) -o main ver1.cpp $(CFLAG)

test: main in.txt
	./main < in.txt
