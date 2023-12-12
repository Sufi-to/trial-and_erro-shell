# include "simpleshellmain.h"

size_t  arrlen(char **arr) 
{
    int i;

    i = 0;
    while (arr && arr[i])
        i++;
    return (i);
}

void    void_free(char *str)
{
    if (str != NULL) {
        free(str);
        str = NULL;
    }
    return ;
}

void    print_arr(char **arr) {
    int i = 0;
    printf("printing Arr\n");
    while (arr && arr[i])
	{
		printStringToFD(arr[i], 2);
		printStringToFD(" ", 2);
		i++;
	}
    return ;
}

void	arr_clean(char **av)
{
	int	i;

	i = 0;
    if (av == NULL)
    {
        return ;
    }
	while (av && av[i])
	{
		free(av[i]);
        av[i] = NULL;
		i++;
	}
    if (av != NULL)
        free(av);
}


char **dup_arr(char **arr) 
{
    char **res;
    int     i;

    i = 0;
    if (!arr || !*arr) {
        return (NULL);
    }
    res = malloc(sizeof(char *) * (arrlen(arr)));
    if (!res)
        return NULL;
    while (arr && arr[i])
    {
        res[i] = duplicateString(arr[i]);
        i++;
    }
    return (res);
}

void tokenize(char *input, t_token *tokens) {
    tokens->tokens = _split(input, ' ');
}