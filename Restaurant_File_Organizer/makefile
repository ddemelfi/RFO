CC=gcc
OBJ = main.o arrayList.o bt.o restaurant.o readIn.o linkedList.o 

all: $(OBJ)
	$(CC) *.o -o ./p2

linkedList.o: linkedList.c linkedList.h 
	$(CC) -c -g linkedList.c

restaurant.o: restaurant.c restaurant.h linkedList.h
	$(CC) -c -g restaurant.c

arrayList.o: arrayList.c arrayList.h restaurant.h linkedList.h
	$(CC) -c -g arrayList.c

bt.o: bt.c bt.h restaurant.h arrayList.h
	$(CC) -c -g bt.c

readIn.o: readIn.c readIn.h arrayList.h bt.h restaurant.h linkedList.h 
	$(CC) -c -g readIn.c

main.o: main.c main.h readIn.h arrayList.h bt.h restaurant.h
	$(CC) -c -g main.c

.PHONY: clean

clean:
	rm *.o
	rm ./p2
