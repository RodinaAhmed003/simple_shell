#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define delimeter " \t\n"
extern char **environ;

void manar_print(const char *myText);
int sh_execute(char **myCmd, char **argv, int index);

char *sh_read(void);
/*string functions*/
char *str_duplicate(const char *str);
int str_compare3(char *str1, char *str2);
int str_length(char *str);
char *str_cat(char *dest, char *src);
char *str_copy(char *dest, char *src);
void rev_string(char *s);
char **sh_tokenizer(char *myLine);
void sh_FreeArrOfstring(char **myArr);
char *sh_getpath(char *myCmd);
char *sh_getenv(char *envVariable);
char *sh_itoa(int num);
void sh_getFull(char *FullCmd, char *myCmd, char *cmdDir);
int is_postive(char *s);
int sh_atoi(char *s);
/*builtin*/
int sh_builtin_check(char *cmd);
void sh_builtin_handle(char **cmd, char **argv, int *status, int index);
void exit_my_shell(char **cmd, char **argv, int *status, int index);
void sh_print_env(char **cmd, int *status);
/*error*/
void sh_writeEr(char **argv, char *index_str, char *msg, char **cmd);
void sh_printerror(char *shellName, char *myCmd, int index);
#endif
