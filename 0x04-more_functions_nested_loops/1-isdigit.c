#include "main.h"
/**
  *_isdigit - check digit 0 to 9
  *@c: char to be checked
  *Return:1 or 0
  */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
