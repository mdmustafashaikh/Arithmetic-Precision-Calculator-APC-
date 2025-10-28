a.out: main.o addition.o subtraction.o multiplication.o division.o new.o
	gcc -o a.out main.o addition.o subtraction.o multiplication.o division.o new.o

main.o: main.c
	gcc -c main.c

addition.o: addition.c
	gcc -c addition.c

subtraction.o: subtraction.c
	gcc -c subtraction.c

multiplication.o: multiplication.c
	gcc -c multiplication.c

division.o: division.c
	gcc -c division.c

new.o: new.c
	gcc -c new.c

clean:
	rm -f *.o a.out