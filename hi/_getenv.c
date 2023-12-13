#include "simpleshellmain.h"
/**
 * _getenv - This function searches the environment list envp_arr
 * for a variable named var_name and returns its value, if found.
 * @var_name: A pointer to a null-terminated string representing the
 * environment variable name to search for.
 * @envp_arr: An optional pointer to an array of null-terminated strings
 * representing the environment list (optional, can be NULL).
 * Return: A pointer to a null-terminated string containing the value
 * of the environment variable name, or NULL if the variable is not found.
*/
char *_getenv(char *var_name, char **envp_arr)
{
int i = 0;
char *envvalue;
while (envp_arr && envp_arr[i] != NULL)
{
if (strncmp(envp_arr[i], var_name, strlen(var_name)) == 0)
{
/** char *envvalue = malloc(strlen(envp[i])+1 - strlen(name)); */
/** envvalue = substring(*envp, strlen(name)+1, strlen(*envp)); */
envvalue = duplicateString(envp_arr[i] + 5);
return (envvalue);
}
i++;
}
return (NULL);
}
