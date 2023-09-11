/*
 * File: multiple_wordcount.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */

#include "multiple_wordcountlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <sys/wait.h>
// include other standard header files or your own user defined libraries needed 


/*
 * YOUR COMMENTS
 */

/* will take the names of multiple input files as command line arguments. For each file, it creates (forks) a child that can execute the above program wordcount for each file to count/print the number of words in that file. Specifically, the program multiple_wordcount.c will first determine the number of files to be processed. Then, the program will create that many child processes with each process being responsible for one file to count the words in it. */


int main(int argc, char *argv[]) {

    int i;
    int n;
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
            exit(EXIT_FAILURE);
        }

        if (cpid == 0) {
            // this part is for child process
            // exec(...) the wordcount program with argv[i] as a parameter
            // if exec() is successful, the child process will be replaced by wordcount
            // BUT, if exec() fails, the child will continue executing statements here!
            // So, print an error message here and
            // return/exit with an exit code of 2, indicating that exec failed.
            // Otherwise (if you don't exit), what will happen?

            system("cc wordcount.c -o wordcount.o");

            if (execl("./wordcount.o", "wordcount.c", new_argv[i], (char *)NULL) == -1) {
                perror("execl");
                exit(2);
            }
        
        }
        
        cpid = wait(NULL);
        fprintf(stdout, "Child processes are complete\n"); 
    }
    
    

    free_new_argv(argc, new_argv);

    return 0;
}

