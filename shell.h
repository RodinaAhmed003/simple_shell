#ifndef SHELL_H_
#define SHELL_H_

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *search_path(char *cmd) {
if (cmd[0] == '/') {
return strdup(cmd);
}

char *path = getenv("PATH");
char *p = strtok(path, ":");
char *fullpath = malloc(MAX_CMD_LEN);

void printmsg(const char *myText);
int execute.c(char **myCmd, char **argv, int index);
void exit_shell(char **cmd, char **argv, int *status, int index);
    
while (p != NULL) {
snprintf(fullpath, MAX_CMD_LEN, "%s/%s", p, cmd);
if (access(fullpath, X_OK) == 0) {
return fullpath;
}
p = strtok(NULL, ":");
}

free(fullpath);
return NULL;
}
