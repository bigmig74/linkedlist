all: mchava1P14

mchava1P14: LinkedList.o mchava1P14.o
	gcc LinkedList.o mchava1P14.o -g -o mchava1P14

LinkedList.o: LinkedList.c
	gcc -c LinkedList.c

mchava1P14.o: mchava1P14.c
	gcc -c mchava1P14.c

clean:
	rm -rf *o mchava1P14