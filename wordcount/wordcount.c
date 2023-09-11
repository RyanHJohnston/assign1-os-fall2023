/*
 * File: wordcount.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <threads.h>
#include <unistd.h>

#include "wordcountlib.h"

#define FILE_INDEX 1

/* HOW TO COMPILE: gcc wordcount.c wordcountlib.c -o wordcount.o

/* ./wordcount File_1 */
int main(int argc, char *argv[]) {
    
    char **new_argv;
    int i;
    char *result_str;
    int word_count;

    new_argv = get_argv(argc, argv);
    
    result_str = get_element_from_new_argv(argc, new_argv, FILE_INDEX);
  
    word_count = count_words_in_file(result_str);

    fprintf(stdout, "wordcount with process pid_1 counted words in %s: number of words is %i\n", 
            result_str, word_count);
    
    free(result_str);
    free_new_argv(argc, new_argv);


    exit(EXIT_SUCCESS);
}

