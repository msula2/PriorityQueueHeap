CC = g++

run : main.o heap.o
		$(CC) -o run main.o heap.o

main.o : heap.o 
		$(CC) -Iinclude -c src/main.cpp -o main.o

heap.o : 
		$(CC) -Iinclude -c src/heap.cpp -o heap.o

clean :
		rm -rf run main.o heap.o