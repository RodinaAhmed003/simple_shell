#include "shell.h"

int main(int argc, char *argv[], char *envp[]) {
    char *cmd = NULL;  // Declare cmd as a char *
    char *args[MAX_ARGS];
    int status;

    while (1) {
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "$ ", 2);
        }

        if (getline(&cmd, &(size_t){MAX_CMD_LEN}, stdin) == -1) {
            if (isatty(STDIN_FILENO)) {
                write(STDOUT_FILENO, "\n", 1);
            }
            free(cmd);  // Free cmd
            exit(EXIT_SUCCESS);
        }

        cmd[strlen(cmd) - 1] = '\0';  // Remove newline at the end

        if (strlen(cmd) == 0) {
            continue;
        }

        // Split the command into arguments
        args[0] = strtok(cmd, " ");
        for (int i = 1; i < MAX_ARGS; i++) {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL) {
                break;
            }
        }

        if (strcmp(args[0], "exit") == 0) {
            free(cmd);  // Free cmd
            exit(EXIT_SUCCESS);
        }

        if (strcmp(args[0], "env") == 0) {
            for (char **env = envp; *env != 0; env++) {
                char *thisEnv = *env;
                write(STDOUT_FILENO, thisEnv, strlen(thisEnv));
                write(STDOUT_FILENO, "\n", 1);
            }
            continue;
        }

        char *fullpath = search_path(args[0]);
        if (fullpath == NULL) {
            write(STDERR_FILENO, argv[0], strlen(argv[0]));
            write(STDERR_FILENO, ": 1: ", 5);
            write(STDERR_FILENO, args[0], strlen(args[0]));
            write(STDERR_FILENO, ": not found\n", 12);
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            free(cmd);  // Free cmd
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (execve(fullpath, args, NULL) == -1) {
                write(STDERR_FILENO, argv[0], strlen(argv[0]));
                write(STDERR_FILENO, ": 1: ", 5);
                write(STDERR_FILENO, args[0], strlen(args[0]));
                write(STDERR_FILENO, ": not found\n", 12);
                free(cmd);  // Free cmd
                exit(EXIT_FAILURE);
            }
        } else {
            if (wait(&status) == -1) {
                perror("Wait failed");
                free(cmd);  // Free cmd
                exit(EXIT_FAILURE);
            }
        }

        free(fullpath);
    }

    free(cmd);  // Free cmd
    return 0;
}
