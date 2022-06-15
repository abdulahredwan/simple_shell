#include "main.h"
/**
 * _perror - prints error line
 * @command: command passed
 * @value: error value
 * @data: struct store
 * Return: error value
 */
int _perror(char **command, int value, store *data)
{
	char *error;

	switch (value)
	{
	case -1:
		error = error_env(command, data);
		break;
	case 2:
		if (_strcmp("exit", command[0]) == 0)
			error = error_exit_shell(command, data);
		else if (_strcmp("cd", command[0]) == 0)
			error = error_get_cd(command, data);
		break;
	case 127:
		error = error_not_found(command, data);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	data->_return = value;
	return (value);
}
