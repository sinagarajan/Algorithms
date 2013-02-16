all: binarytree

binarytree: binarytree.o btappln.o
	g++ binarytree.o btappln.o -o binarytree

binarytree.o: binarytree.cpp
	g++ -c binarytree.cpp

btappln.o: btappln.cpp
	g++ -c btappln.cpp

clean:
	rm -rf *o binarytree

