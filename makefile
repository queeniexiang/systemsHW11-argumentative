all: parse_args.o 
	gcc -o test parse_args.o

parse_args.o: parse_args.c
	gcc -c parse_args.c 

run: all 
	./test

