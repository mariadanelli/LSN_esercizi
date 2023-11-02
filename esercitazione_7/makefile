CC = g++
CFLAGS = -Wall -O3 --std=c++11

NVE_NVT.exe : MC_MD.o random.o
	$(CC) random.o MC_MD.o -o NVE_NVT.exe
MC_MD.o : MC_MD.cpp
	$(CC) -c MC_MD.cpp -o MC_MD.o $(CFLAGS)
random.o : random.cpp random.h
	$(CC) -c random.cpp -o random.o $(CFLAGS)
clean :
	rm *.o NVE_NVT.exe
