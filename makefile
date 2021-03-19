output: main.o linklist.o
        g++ main.o linklist.o -o output -std=c++11

main.o: main.cpp
        g++ -c -std=c++11 main.cpp

shape.o: linklist.cpp
        g++ -c -std=c++11 linklist.cpp
        g++ -c linklist.h