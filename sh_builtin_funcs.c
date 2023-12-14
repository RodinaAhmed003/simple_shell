#include "shell.h"
/**
* sh_builtin_check - check if cmd is builtin cmd
*
* @cmd: int parameter
*
* Return: 1 if it is builin 0 if not
*/
int sh_builtin_check(char *cmd)
{
int index;
char *builtin_commands[] = {
"exit", "env", "setenv", "cd", NULL};
for (index = 0; builtin_commands[index]; index++)
if (str_compare3(cmd, builtin_commands[index]) == 0)
return (1);
return (0);
}
/**
* my_builtin_handle - handles builtin cmd
*
* @cmd: char ptr parameter
* @argv: char ptr parameter
* @status: int ptr parameter
* @index: int  parameter
*
* Return: void
*/
void sh_builtin_handle(char **cmd, char **argv, int *status, int index)
{
if (str_compare3(cmd[0], "exit") == 0)
{
exit_my_shell(cmd, argv, status, index);
}
else if (str_compare3(cmd[0], "env") == 0)
{
my_print_env(cmd, status);
}
}
/**
* exit_my_shell - exit shell
*
* @cmd: char ptr parameter
* @argv: char ptr parameter
* @status: int ptr parameter
* @index: int  parameter
*
* Return: void
*/
void exit_my_shell(char **cmd, char **argv, int *status, int index)
{
int my_exit_value = (*status);
char *index_s, my_msg[] = ": exit: Illegal number: ";
if (cmd[1])
{
if (is_postive(cmd[1]))
my_exit_value = sh_atoi(cmd[1]);
else
{
index_s = sh_itoa(index);
sh_writeErr(argv, index_s, my_msg, cmd);
free(index_s);
sh_FreeArrOfstring
(*status) = 2;
return;
}
}
sh_FreeArrOfstring
exit(my_exit_value);
}
/**
* my_print_env - prints env
*
* @cmd: char ptr parameter
* @status: char ptr parameter
*
* Return: void
*/
void my_print_env(char **cmd, int *status)
{
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], str_length(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
sh_FreeArrOfstring(cmd);
*status = 0;
}
