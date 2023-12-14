#include "shell.h"
/**
 * sh_getFull- print the full cmd path
 *
 * @FullCmd: char pointer parameter
 * @myCmd: char pointer parameter
 * @cmdDir: char pointer  parameter
 *
 * Return: void
 */
void sh_getFull(char *FullCmd, char *myCmd, char *cmdDir)
{

	str_copy(FullCmd, cmdDir);
	str_cat(FullCmd, "/");
	str_cat(FullCmd, myCmd);
}
