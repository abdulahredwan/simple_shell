#include "main.h"
/**
 * exit_num - returns status
 * @command: command passed
 * @data: struct store
 * Return: status
 */
int exit_num(char **command, store *data)
{
	unsigned int n = 0;
	int i, j, k;

	if (command[1])
	{
		n = _atoi(command[1]);
		i = _isdigit(command[1]);
		j = _strlen(command[1]);
		k = n > (unsigned int)INT_MAX;
		if (!i || j > 10 || k)
		{
			_perror(command, 2, data);
			n = 2;
			data->_return = 2;
			return (n);
		}
	}
	data->_return = (n % 256);

	return (n);
}
