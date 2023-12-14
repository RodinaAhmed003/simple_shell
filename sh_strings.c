#include "shell.h"
/**
* str_duplicate - duplicate string
*
* @str: char parameter
*
* Return: pstr_duplicate
*/
char *str_duplicate(const char *str)
{
char *pstr_duplicate;
int i, str_len = 0;
if (str == NULL)
return (NULL);
/*count string length*/
while (*str != '\0')
{
str_len++;
str++;
}
/*return pointer to the start*/
str = str - str_len;
pstr_duplicate = malloc(sizeof(char) * (str_len + 1));
if (pstr_duplicate == NULL)
return (NULL);
for (i = 0; i <= str_len; i++)
pstr_duplicate[i] = str[i];
return (pstr_duplicate);
}
/**
* str_compare3 - return string length
*
* @str1: char pointer parameter
* @str2: char pointer parameter
* @str3: char pointer parameter
*
* Return: str compare result
*/
int str_compar3(char *str1, char *str2, char *str3)
{
while (*str1 && *str2 && (*str1 == *str2))
{
str1++;
str2++;
}
return ((int)(*str1) - (int)(*str2));
}
/**
* str_length - return string length
*
* @str: int parameter
*
* Return: length of string
*/
int str_length(char *str)
{
int len_counter;
for (len_counter = 0; *str != '\0'; str++)
len_counter++;
return (len_counter);
}
/**
* str_copy - print string and new line
*
* @src: int parameter
* @dest: int parameter
*
* Return: dest
*/
char *str_copy(char *dest, char *src)
{
int i;
for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
/**
* str_cat - concat char 2 in char 1
*
* @src: int parameter
* @dest: int parameter
*
* Return: dest
*/
char *str_cat(char *dest, char *src)
{
int destLength = 0;
int srcLength = 0;
int i;
for (i = 0; dest[i] != '\0'; i++)
destLength++;
for (i = 0; src[i] != '\0'; i++)
srcLength++;
for (i = 0; i <= srcLength; i++)
dest[destLength + i] = src[i];
return (dest);
}
