#include "main.h"

/**
 * get_sigint - it handles crtl + c cals in prmpt
 * @sig: the handler of the signal
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n:)", 3);
}
