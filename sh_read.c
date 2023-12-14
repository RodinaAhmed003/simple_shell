#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * sh_read - read sh
 *
 * Return: myBuffer
 */
char *sh_read(void)
{
	char *myBuffer = NULL;
	size_t bufferLength = 0;
	ssize_t result;

	if (isatty(STDIN_FILENO))
		Manar_print("$Rodina_ ");
	result = getline(&myBuffer, &bufferLength, stdin);

	if (result == -1)
	{
		free(myBuffer);
		return (NULL);
	}
	return (myBuffer);
}
