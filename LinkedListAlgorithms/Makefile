all: linkedlist

linkedlist: linkedlist.o llappln.o
	g++ linkedlist.o llappln.o -o linkedlist

linkedlist.o: linkedlist.cpp
	g++ -c linkedlist.cpp

llappln.o: llappln.cpp
	g++ -c llappln.cpp

clean:
	rm -rf *o linkedlist

