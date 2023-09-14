CC = gcc
CFLAGS = -Wall -g

all: multiple_wordcount wordcount 

clean:
	rm -f *.o wordcount

wordcount:
	$(CC) $(CFLAGS) wordcount. -o wordcount.o

multiple_wordcount:
	$(CC) $(CFLAGS) multiple_wordcount.c -o multiple_wordcount.o

run wordcount:
	valgrind ./wordcount.o
