#ifndef WORDCOUNTLIB_H
#define WORDCOUNTLIB_H

#include <sys/types.h>

char **get_argv(int argc, char **argv);

void print_new_argv(int argc, char **new_argv);

char *get_element_from_new_argv(int argc, char **new_argv, int index);

int count_words_in_file(char *filename); 

void free_new_argv(int argc, char **new_argv);

pid_t r_wait(int *stat_loc);

#endif
