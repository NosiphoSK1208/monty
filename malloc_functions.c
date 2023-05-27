#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @sone: type str compared
 * @stwo: type str compared
 * Return: 0 if sone and stwo are equals.
 *         another value if they are different
 */
int _strcmp(char *sone, char *stwo)
{
	int i;

	for (i = 0; sone[i] == stwo[i] && sone[i]; i++)
		;
	if (sone[i] > stwo[i])
		return (1);
	if (sone[i] < stwo[i])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @strs: string to review
 * @ccf: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *strs, char ccf)
{
	int cont = 0;

	while (strs[cont] != '\0')
	{
		if (strs[cont] == ccf)
		{
			break;
		}
		cont++;
	}
	if (strs[cont] == ccf)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @strs: string to cut in parts
 * @dmt: delimiters
 * Return: first partition
 */
char *_strtoky(char *strs, char *dmt)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!strs)
		strs = ultimo;
	while (strs[i] != '\0')
	{
		if (_sch(dmt, strs[i]) == 0 && strs[i + 1] == '\0')
		{
			ultimo = strs + i + 1;
			*ultimo = '\0';
			strs = strs + j;
			return (strs);
		}
		else if (_sch(dmt, strs[i]) == 0 && _sch(dmt, strs[i + 1]) == 0)
			i++;
		else if (_sch(dmt, strs[i]) == 0 && _sch(dmt, strs[i + 1]) == 1)
		{
			ultimo = strs + i + 1;
			*ultimo = '\0';
			ultimo++;
			strs = strs + j;
			return (strs);
		}
		else if (_sch(dmt, strs[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
