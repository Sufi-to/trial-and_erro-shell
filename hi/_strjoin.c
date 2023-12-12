#include "simpleshellmain.h"

char	*_strjoin(char *s1, char *s2)
{
	char	*str_j;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (!s1)
		s1 = _calloc(1, 1);
	if (!s1 && !s2)
		return (s1);
	str_j = (char *)_calloc((sizeof(char) * (len1 + len2 + 1)), 1);
	if (!str_j)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		str_j[i] = s1[i];
	while (s2[++j])
		str_j[i++] = s2[j];
	str_j[i] = '\0';
	free(s1);
	return (str_j);
}