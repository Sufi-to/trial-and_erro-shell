# include "simpleshellmain.h"

int	count_strings(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

int	_strsize(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*_word(const char *str, char c)
{
	int		size;
	int		i;
	char	*word;

	i = 0;
	size = _strsize(str, c);
	word = (char *) malloc(sizeof(char) * (size + 1));
	if (!word)
		return (0);
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*jump_chars(char *str, int c, int code)
{
	if (code == 1)
	{
		while (*str != '\0' && *str == c)
			str++;
	}
	else if (code == 2)
	{
		while (*str && *str != c)
			str++;
	}
	return (str);
}

char	**_split(char *str, char c)
{
	char	**strings;
	int		i;

	if (!str || *str == 0)
		return (0);
	i = 0;
	if (count_strings(str, c) == 0)
		return (0);
	strings = (char **) malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (0);
	while (*str != '\0')
	{
		str = jump_chars(str, c, 1);
		if (*str != '\0')
		{
			strings[i] = _word(str, c);
			if (strings[i] == NULL)
				return (arr_clean(strings), NULL);
			i++;
		}
		str = jump_chars(str, c, 2);
	}
	strings[i] = 0;
	return (strings);
}