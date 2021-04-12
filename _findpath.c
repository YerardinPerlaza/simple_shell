#include "headers.h"
/**
 * findpath - find the directory of a command
 *@command: string with the command
 * Return: the directory of the command
 */
char *findpath(char *command)
{
	char *path;
	struct stat stats;
	char *current_source;
	char *tok;

	if (stat(command, &stats) == 0)
		return (command);

	path = getenv("PATH");
	tok = strtok(path, ":");
	command = str_concat("/", command);

/*stat() returns 0 on successful operation,*/
/* otherwise returns -1 if unable to get file properties.*/
	while (tok != NULL)
	{
		current_source = str_concat(tok, command);
		if (stat(current_source, &stats) == 0)
		{
			free(command);
			return (current_source);
		}
		free(current_source);
		tok = strtok(NULL, ":");
	}
	error_printing(path, find_length(command), command);
	print_str(": not found", 0);
	free(command);
	return (NULL);
}
