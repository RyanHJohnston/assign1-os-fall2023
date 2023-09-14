/*
 * File: multiple_wordcount.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/unistd.h>
#include <sys/types.h>


char **get_argv(int argc, char **argv);

void print_new_argv(int argc, char **new_argv);

char *get_element_from_new_argv(int argc, char **new_argv, int index);

int count_words_in_file(char *filename); 

void free_new_argv(int argc, char **new_argv);

pid_t r_wait(int *stat_loc);

int main(int argc, char *argv[]) {

    int i;
    int n;
    int exit_code;
    int status;
    int successful_files;
    int unsuccessful_files;
    char **new_argv;
    pid_t cpid;
    char *filename;
    FILE *fp;

    n = argc - 1;
    new_argv = get_argv(argc, argv);

    /* create n = argc - 1 child processes */
    for (i = 1; i < argc; ++i) {
        cpid = fork();

        if (cpid == -1) {
            fprintf(stderr, "ERROR: Failed to fork child process\n");
            exit(-1);
        }

        if (cpid == 0) {
            system("cc wordcount.c -o wordcount.o");

            if (execl("./wordcount.o", "wordcount.c", new_argv[i], (char *)NULL) == -1) {
                perror("execl");
                exit(2);
            }
        
        }
        
        successful_files = 0;
        unsuccessful_files = 0;
        cpid = wait(&status);
        if (WIFEXITED(status)) {
            exit_code = WEXITSTATUS(status);
            if (exit_code == 0) {
                successful_files += 1;
            } else {
                unsuccessful_files += 1;
            }
        }
    }
    
        fprintf(stdout, "\n");
        fprintf(stdout, "Parent process created %i child processes to count words in %i files\n",
                n, successful_files + unsuccessful_files);
        fprintf(stdout, "%i Have been counted successfully!\n", 
                successful_files);
        fprintf(stdout, "%i Files did not exist\n",
                unsuccessful_files);
    

    free_new_argv(argc, new_argv);

    return 0;
}

char ** get_argv(int argc, char **argv) {
    static int i;
    char **new_argv = malloc((argc + 1) * sizeof(*new_argv));
    for (i = 0; i < argc; ++i) {
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
    static int i;

    for (i = 0; i < argc; ++i) {
        fprintf(stdout, "%s\n", new_argv[i]);
    }
}

void free_new_argv(int argc, char **argv) {
    static int i;
    for (i = 0; i < argc; ++i) {
        free(argv[i]);
    }
    free(argv);
}

pid_t r_wait(int *stat_loc) {
    int reval;
    while (((reval == (wait(stat_loc) == -1) && errno == EINTR)));
    return reval;
}


