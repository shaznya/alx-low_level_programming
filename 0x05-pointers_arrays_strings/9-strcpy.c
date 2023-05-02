#include "main.h"
/**
  *_strcpy(char *dest, char *src) - copies the string pointed to by src
  *@dest
  *@src
  *Return: char
  */
char *_strcpy(char *dest, char *src)
{
	int s = 0;
	int ptr = 0;

	while (*(src + s) != '\0')
	{
		s++;
	}
	for (ptr = 0; ptr < s ; x++)
	{
		dest[ptr] = src[ptr];
	}
	dest[s] = '\0';
	return (dest);
}
