#ifndef SIMPLESHELLMAIN_H
#define SIMPLESHELLMAIN_H

 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

typedef struct s_token
{
    char    **tokens;
}       t_token;

typedef struct s_cmd
{
    char *cmd;
    char *cmdpath;
    char **args;
}       t_cmd;



void printEnvironment(char **envp);
void printStringToFD(char *s, int fdI);
void printStringAndNewLineToFD(char *s, int fdI);
void printErrorMsg(char *error);
void freeDoublePointerArray(char **array);
char *get_executable_path(char *filename, char **envp);
char *find_char_in_string(const char *str, int c);
void *find_byte_in_memory(const void *ptr, int c, size_t n);
size_t string_length(const char *str);
size_t limitedStringCopy(char *destBuffer, const char *sourceStr, size_t maxSize);
char *find_last_occurrence(const char *str, int c);
char *trimString(const char *str, const char *cs);
int compareStrings(char *str1, char *str2);
char *substring(char const *s, unsigned int begin, size_t l);
char *duplicateString(char *originalString);



char *_strwchr(char *s, char c);
char *_strtok(char *stringtobetokenized, char *delimiters);

char *_getenv(char *var_name, char **envp_arr);

char	**_split(char *str, char c);
void tokenize(char *input, t_token *tokens);
size_t  arrlen(char **arr);
void	arr_clean(char **av);
char    **dup_arr(char **arr);

char	*_strjoin(char *s1, char *s2);
void *_calloc(size_t num_elements, size_t byte_size);
void _bzero(void *memo_pointer, size_t n_bytes);
void	*_memset(void *s, int c, size_t n);
size_t	_strlen(const char *s);
void    void_free(char *str);
void    print_arr(char **arr);

#endif /* SIMPLESHELLMAIN_H */