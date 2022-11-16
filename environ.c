#include "shell.h"

/**
 * print_env - function that prints the environment
 * Return: 0
 */

void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		i++;
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _getenv - function gets an environment variable
 * @name: variable to be compared with environ
 * Return: the value
 */

char *_getenv(const char *name)
{
	int i, j, length = 0;

	while (name[length] != '\0')
		length++;
	if (length == 0)
		return (NULL);
	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for (j = 0 ; name[j] != '\0' ; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (name[j] == '\0')
			return (environ[i] + j + 1);
	}
	return (NULL);
}

/**
 * _check - function checks whether a file exists in PATH
 * @file: The file to check
 * Return: On success, 0. Otherwise, -1.
 */

int _check(char *file)
{
	struct stat status;

	while (file)
	{
		if (stat(file, &status) == 0)
		{
			return (0);
		}
		break;
	}
	return (-1);
}
