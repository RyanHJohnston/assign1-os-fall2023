#include "wordcountlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **
get_argv(int argc, char **argv)
{
    char **new_argv = malloc((argc + 1) * sizeof(*new_argv));
    for (int i = 0; i < argc; ++i) {
        size_t length = strlen(argv[i]) + 1;
        new_argv[i] = malloc(length);
        memcpy(new_argv[i], argv[i], length);
    }
    new_argv[argc] = NULL;
    return new_argv;
}

void
print_argv(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i) {
        fprintf(stdout, "%s\n", argv[i]);
    }
}

void
free_argv(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i) {
        free(argv[i]);
    }
    free(argv);
}



