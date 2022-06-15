#include "main.h"
/**
 * set_data - sets environ data
 */
void set_data(char *name)
{
	int i;

	for (i = 0; environ[i]; i++)
		;
	_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
		_environ[i] = _strdup(environ[i]);
	_environ[i] = NULL;

	callmemaybe = name;
}
