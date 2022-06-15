#include "main.h"
/**
 * ctrlchandler - handles ctrl in prompt
 * @signum: signal handler
 */
void ctrlchandler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n$ ", 3);
}
