#include "shell.h"
/**
 * sh_FreeArrOfstring - execute cmd
 *
 * @myArr: char ptr parameter
 *
 * Return: void
 */
void sh_FreeArrOfstring(char **myArr)
{
	int i;

	if (myArr == NULL)
		return;

	for (i = 0; myArr[i]; i++)
	{
		free(myArr[i]), myArr[i] = NULL;
	}
	free(myArr), myArr = NULL;
}
/**
 * rev_string - execute cmd
 *
 * @s: char ptr parameter
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0, i;
	char temp;

	while (s[length] != '\0')
	{
		length++;
	}
	for (i = 0; i < length / 2; i++)
	{
		temp = s[i];
		s[i] = s[length - 1 - i];
		s[length - 1 - i] = temp;
	}
}
/**
 * sh_itoa - integer to ascii
 *
 * @num: int parameter
 *
 * Return: ascii of number
 */
char *sh_itoa(int num)
{
	char myBuffer[20];
	int i = 0;

	if (num == 0)
		myBuffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			myBuffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	myBuffer[i] = '\0';
	rev_string(myBuffer);
	return (str_duplicate(myBuffer));
}
/**
 * is_postive - check if postive
 *
 * @s: int parameter
 *
 * Return: ascii of number
 */
int is_postive(char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * sh_atoi - ascii to integer
 *
 * @s: int parameter
 *
 * Return: number
 */
int sh_atoi(char *s)
{
	int i, n = 0;

	for (i = 0; s[i]; i++)
	{
		n *= 10;
		n += (s[i] - '0');
	}
	return (n);
}
