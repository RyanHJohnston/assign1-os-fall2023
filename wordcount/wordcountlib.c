#include "wordcountlib.h"
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


char ** get_argv(int argc, char **argv) {
    char **new_argv = malloc((argc + 1) * sizeof(*new_argv));
    for (int i = 0; i < argc; ++i) {
        size_t length = strlen(argv[i]) + 1;
        new_argv[i] = malloc(length);
        memcpy(new_argv[i], argv[i], length);
    }
    new_argv[argc] = NULL;
    return new_argv;
}

char *get_element_from_new_argv(int argc, char **new_argv, int element_index) {
    static int i;
    char *result_str;
    
    if (element_index >= argc || element_index < 0) {
        fprintf(stderr, "ERROR: Fetching index out of bounds, returning -1\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < argc; ++i) {
        if (element_index == i) {
            size_t length = strlen(new_argv[i]) + 1;
            result_str = malloc(length);
            memcpy(result_str, new_argv[i], length);
            return result_str;
        }
    }

    fprintf(stderr, "ERROR: Condition should not have been reached, element not found in new_argv\n");
    exit(EXIT_FAILURE);
}

int count_words_in_file(char *filename) {
    FILE *fp;
    char ch;
    int count;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "ERROR: wordcount with process pid_1 cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    

    count = 0;
    while (ch != EOF) {
        ch = fgetc(fp);
        if (ch == ' ' || ch == '\n') {
            ++count;
        }
    }
    
    /* prints out the words in a file */
    # if 0
    while (ch != EOF) {
        ch = fgetc(fp);
        fprintf(stdout, "%c", ch);
    }
    #endif
    
    fclose(fp);
    fp = NULL;
    
    return count;
}

void print_new_argv(int argc, char **new_argv) {
    

    for (int i = 0; i < argc; ++i) {
        fprintf(stdout, "%s\n", new_argv[i]);
    }
}

void free_new_argv(int argc, char **argv) {
    for (int i = 0; i < argc; ++i) {
        free(argv[i]);
    }
    free(argv);
}

pid_t r_wait(int *stat_loc) {
    int reval;
    while (((reval == (wait(stat_loc) == -1) && errno == EINTR)));
    return reval;
}


