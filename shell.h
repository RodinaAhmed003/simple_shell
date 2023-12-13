#ifndef SHELL_H
#define SHELL_H

extern char **en;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
 
void execute(char *input);
void message(const char *msg);
void print_en(void); 
#endif
