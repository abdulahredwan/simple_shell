#include "main.h"
/**
 * free_environ - frees environ data
 * @data: struct store
 */
void free_environ(store *data)
{
	unsigned int i;

	for (i = 0; data->_environ[i]; i++)
	{
		free(data->_environ[i]);
	}
	free(data->_environ);
}
