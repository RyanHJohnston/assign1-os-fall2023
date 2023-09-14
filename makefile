CC = gcc
CFLAGS = -Wall -g

all: multiple_wordcount wordcount 

clean:
	rm -f *.o wordcount

wordcount:
	$(CC) $(CFLAGS) wordcount.c -o wordcount.o

multiple_wordcount:
	$(CC) $(CFLAGS) multiple_wordcount.c -o multiple_wordcount.o

run:
	./wordcount.o input_file_1.txt
	./wordcount.o input_file_2.txt
	./multiple_wordcount.o input_file_1.txt input_file_2.txt

valgrind_run:
	valgrind ./wordcount.o input_file_1.txt
	valgrind ./wordcount.o input_file_2.txt
	valgrind ./multiple_wordcount.o input_file_1.txt input_file_2.txt

run_wordcount:
	./wordcount.o input_file_1.txt
	./wordcount.o input_file_2.txt

run_multiple_wordcount:
	./multiple_wordcount.o input_file_1.txt input_file_2.txt

valgrind_run_wordcount:
	valgrind ./wordcount.o input_file_1.txt

valgrind_run_multiple_wordcount:
	valgrind ./multiple_wordcount.o input_file_1.txt input_file_2.txt



