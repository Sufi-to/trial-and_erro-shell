#include "simpleshellmain.h"

char *_getenv(char *name, char **envp)
{   
    int i = 0;
    char * envvalue;
    while ( envp && envp[i] != NULL)
    {
        if (strncmp(envp[i], name, strlen(name)) == 0)
        {
            /** char *envvalue = malloc(strlen(envp[i])+1 - strlen(name)); */
            /** envvalue = substring(*envp, strlen(name)+1, strlen(*envp)); */
            envvalue = duplicateString(envp[i] + 5);
            return envvalue;
        }
        i++;
    }
    return NULL;
}
