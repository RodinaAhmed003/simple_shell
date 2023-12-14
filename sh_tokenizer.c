#include "shell.h"
/**
 *sh_tokenizer - converts strings into tokens
 *
 * @myLine: char pointer to the line cmd
 *
 * Return: cmd
 */
char **sh_tokenizer(char *myLine)
{
	char *myToken = NULL, *lineDuplicate = NULL;
	char **cmd = NULL;
	int counter = 0, i = 0;

	if (!myLine)
		return (NULL);
	lineDuplicate = str_duplicate(myLine);

	myToken = strtok(lineDuplicate, delimeter);
	/*if entered spaces and enter*/
	if (myToken == NULL)
	{
		free(myLine), myLine = NULL;
		free(lineDuplicate), lineDuplicate = NULL;
		return (NULL);
	}
	while (myToken != NULL)
	{
		counter++;
		myToken = strtok(NULL, delimeter);
	}
	free(lineDuplicate), lineDuplicate = NULL;
	cmd = malloc(sizeof(char *) * (counter + 1));
	if (!cmd)
	{
		free(myLine), myLine = NULL;
		return (NULL);
	}
	myToken = strtok(myLine, delimeter);
	while (myToken != NULL)
	{
		cmd[i] = str_duplicate(myToken);
		myToken = strtok(NULL, delimeter);
		i++;
	}
	free(myLine), myLine = NULL;
	cmd[i] = NULL;
	return (cmd);
}
