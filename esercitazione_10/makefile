CC = g++
CFLAGS = -Wall -O3 --std=c++11

main.exe : main.o random.o Posizione.o
	mpic++ Posizione.o random.o main.o -o main.exe
main.o : main.cpp main.h 
	mpic++ -c main.cpp -o main.o $(CFLAGS)
random.o : ../random.cpp ../random.h
	$(CC) -c ../random.cpp -o random.o $(CFLAGS)
Posizione.o: Posizione.cpp Posizione.h
	$(CC) -c Posizione.cpp -o Posizione.o

clean :
	rm *.o main.exe seed.out