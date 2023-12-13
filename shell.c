#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *search_path(char *cmd) {
    if (cmd[0] == '/') {
        return strdup(cmd);
    }

    char *path = getenv("PATH");
    char *p = strtok(path, ":");
    char *fullpath = malloc(MAX_CMD_LEN);

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
