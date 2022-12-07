CC = gcc 
CFLAGS = -Wall -g 

all: connections libmy_mat.a

my_mat: libmy_mat.a

connections: main.o libmy_mat.a
	$(CC) $(CFLAGS) main.o libmy_mat.a -lm -o connections

clean:
	rm -f *.o *.a connections

libmy_mat.a: my_mat.o  
	ar rcs libmy_mat.a my_mat.o 

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c  my_mat.c

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c my_mat.h