CC=g++ -std=c++17

Release/main: main.o MyLibrary/MyLibrary.o
	${CC} -o"Release/main" main.o MyLibrary/MyLibrary.o

main.o: main.cc MyLibrary/MyLibrary.h
	${CC} -c -o"main.o" main.cc

MyLibrary/MyLibrary.o: MyLibrary/MyLibrary.cc MyLibrary/MyLibrary.h
	${CC} -c -o"MyLibrary/MyLibrary.o" MyLibrary/MyLibrary.cc

