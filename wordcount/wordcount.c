/*
 * File: wordcount.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordcountlib.h"

/* HOW TO COMPILE: gcc wordcount.c wordcountlib.c -o wordcount.o

/*
 * YOUR COMMENTS
 */



/* The first program wordcount.c will take the name of an input file as a command line argument and open file argv[1] to read. If the file does not exist or cannot be opened, print an error message and return/exit with an exit code of 1, indicating there was one error. If the file is opened successfully, count/print the number of words in file argv[1] and return/exit with an exit code of 0, indicating there was no error. The typical format to run the first program with input parameter is as follows: */

/* ./wordcount File_1 */
int 
main(int argc, char *argv[])
{
    // YOU NEED TO IMPLEMENT THIS + some other functions! 
    int i;
    
    fprintf(stdout, "Get argv\n");
    char **new_argv = get_argv(argc, argv);
    
    print_argv(argc, new_argv);

    fprintf(stdout, "Freeing new_argv\n");
    free_argv(argc, new_argv);

    
    exit(EXIT_SUCCESS);
}

