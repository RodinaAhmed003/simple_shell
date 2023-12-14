#include "shell.h"
/**
* sh_getpath - get path cmd
*
* @myCmd: char ptr parameter
*
* Return: full cmd
*/
char *sh_getpath(char *myCmd)
{
char *env_PATH, *full_cmd, *command_directory;
struct stat state;
int i;
for (i = 0; myCmd[i]; i++)
{
if (myCmd[i] == '/')
{
if (stat(myCmd, &state) == 0)
return (str_duplicate(myCmd));
return (NULL);
}
}
env_PATH = sh_getenv("PATH");
if (!env_PATH)
return (NULL);
command_directory = strtok(env_PATH, ":");
while (command_directory)
{
full_cmd = malloc(str_length(command_directory) + str_length(myCmd) + 2);
if (full_cmd)
{
sh_getFull(full_cmd, myCmd, command_directory);
if (stat(full_cmd, &state) == 0)
{
free(env_PATH);
return (full_cmd);
}
}
free(full_cmd), full_cmd = NULL;
command_directory = strtok(NULL, ":");
}
free(env_PATH);
return (NULL);
}
