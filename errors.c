#include "main.h"
/**
 * _strcat_cd - strcat for cd error
 * @data: data struct
 * @command: command passed
 * @ms: message to print
 * @error: error message
 * @ver: counter lines
 * Return: error message
 */
char *_strcat_cd(store *data, char **command, char *ms, char *error, char *ver)
{
	char *flag;

	_strcpy(error, data->callmemaybe);
	_strcat(error, ": ");
	_strcat(error, ver);
	_strcat(error, ": ");
	_strcat(error, command[0]);
	_strcat(error, ms);
	if (command[1][0] == '-')
	{
		flag = malloc(sizeof(char) * 3);
		flag[0] = '-';
		flag[1] = command[1][1];
		flag[2] = '\0';
		_strcat(error, flag);
		free(flag);
	}
	else
	{
		_strcat(error, command[1]);
	}
	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}
/**
 * error_get_cd - error mesage for cd
 * @command: command passed
 * @data: struct store
 * Return: message
 */
char *error_get_cd(char **command, store *data)
{
	int len, id;
	char *error, *ver, *msg;

	ver = _itoa(data->counter);
	if (command[1][0] == '-')
	{
		msg = ": Illegal option ";
		id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		id = _strlen(command[1]);
	}

	len = _strlen(data->callmemaybe) + _strlen(command[0]);
	len += _strlen(ver) + _strlen(msg) + id + 5;
	error = malloc(sizeof(char) * (len + 1));

	if (!error)
	{
		free(ver);
		return (NULL);
	}
	error = _strcat_cd(data, command, msg, error, ver);

	free(ver);
	return (error);
}
/**
 * error_exit_shell - error message for exit
 * @data: data struct
 * @command: command passed
 * Return: error message
 */
char *error_exit_shell(char **command, store *data)
{
	int len;
	char *error;
	char *ver;

	ver = _itoa(data->counter);
	len = _strlen(data->callmemaybe) + _strlen(ver);
	len += _strlen(command[0]) + _strlen(command[1]) + 23;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(ver);
		return (NULL);
	}
	_strcpy(error, data->callmemaybe);
	_strcat(error, ": ");
	_strcat(error, ver);
	_strcat(error, ": ");
	_strcat(error, command[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, command[1]);
	_strcat(error, "\n\0");

	free(ver);
	return (error);
}
/**
 * error_env - error message for env
 * @command: commad passed
 * @data: data sstruct
 * Return: error message
 */
char *error_env(char **command, store *data)
{
	int len;
	char *error;
	char *msg;
	char *ver;

	ver = _itoa(data->counter);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(data->callmemaybe) + _strlen(ver);
	len += _strlen(command[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(error);
		free(ver);
		return (NULL);
	}
	_strcpy(error, data->callmemaybe);
	_strcat(error, ": ");
	_strcat(error, ver);
	_strcat(error, ": ");
	_strcat(error, command[0]);
	_strcat(error, msg);
	_strcat(error, "\0");

	free(ver);
	return (error);
}
/**
 * error_not_found - error message when command is not found
 * @command: command passed
 * @data: struct data
 * Return: error message
 */
char *error_not_found(char **command, store *data)
{
	int len;
	char *error;
	char *ver;

	ver = _itoa(data->counter);
	len = _strlen(data->callmemaybe) + _strlen(ver);
	len += _strlen(command[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(error);
		free(ver);
		return (NULL);
	}
	_strcpy(error, data->callmemaybe);
	_strcat(error, ": ");
	_strcat(error, ver);
	_strcat(error, ": ");
	_strcat(error, command[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver);
	return (error);
}
