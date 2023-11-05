CC = g++
CFLAGS = -Wall -O3 --std=c++11

main.exe : mainlor.o random.o 
	$(CC) random.o mainlor.o -o main.exe
mainlor.o : mainlor.cpp
	$(CC) -c mainlor.cpp -o mainlor.o $(CFLAGS)
random.o : random.cpp random.h
	$(CC) -c random.cpp -o random.o $(CFLAGS)
clean :
	rm *.o main.exe seed.out