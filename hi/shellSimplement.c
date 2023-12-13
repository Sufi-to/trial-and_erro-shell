 #include "simpleshellmain.h"


void	initcmd( t_cmd *cmd) {
	cmd->cmd = NULL;
	cmd->cmdpath = NULL;
	cmd->args = NULL;
}

void	inittoken( t_token *token) {
	token->tokens = NULL;
}



int main (int ac, char **av, char **envp)
{
	char *input = NULL;
	pid_t id;
	int reading = -1;
	bool pipped = false;
	t_token	token;
	t_cmd	cmd;
	initcmd(&cmd);
	inittoken(&token);

	(void) av;
	if (ac != 1)
	{
		printStringAndNewLineToFD("ERROR: Invalid number of Arguments", 2);
		printStringAndNewLineToFD("Usage: ./;)", 2);
		return (0);
	}
	/* We want the simple shell to be displayed
    each time a command has been executed. So an infinite loop
    it is. To infinity and beyond (I think that is a toy story reference) */
	while (1 && !pipped)
	{
		char *line = NULL;
		size_t bufsize = 0;

		if (isatty(STDIN_FILENO) == 0)
		{
			pipped = true;
		}
			

		printStringToFD(";) ", 2);

		reading = getline(&line, &bufsize, stdin);
	
		if (line == NULL || reading <= 0)
		{
			free(line);
			return (printStringAndNewLineToFD("exit", 2), 1);
		}
			
		if (line[0] == '\0')
			return (free(line), 1);
		input = trimString(line, "    \n");
		free(line);
		tokenize(input, &token);
		if (arrlen(token.tokens) <= 0)
			continue;
		else if (arrlen(token.tokens) == 1 &&  !compareStrings(token.tokens[0], "exit"))
		{
			free(input);
			arr_clean(token.tokens);
			printStringAndNewLineToFD("exit", 2);
			return (1);
		}
		else if (arrlen(token.tokens) == 1 && !compareStrings(token.tokens[0], "env"))
		{
			/** free(input); */
			printEnvironment(envp);
			arr_clean(token.tokens);
		}
		else
		{
			cmd.args = dup_arr(token.tokens);
			
			cmd.cmd = duplicateString(*(token.tokens));
			cmd.cmdpath = get_executable_path(cmd.cmd, envp);

			if (access(cmd.cmd, F_OK) == -1 && cmd.cmdpath == NULL)
			{
				printErrorMsg(cmd.cmd);
			}
			else 
			{
				id = fork();
				if (id == 0)
				{
					if (execve(cmd.cmdpath, cmd.args, envp) == -1)
					{
						printErrorMsg(cmd.cmd);
						/** freeDoublePointerArray(cmd.args); */
						/** free(input2) ; */
						free(input);
						free(cmd.cmd);
						free(cmd.cmdpath);
						arr_clean(cmd.args);
						arr_clean(token.tokens);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					int status;
					do {
						waitpid(id, &status, WUNTRACED);
					} while (!WIFEXITED(status) && !WIFSIGNALED(status));
				}
			}
			void_free(cmd.cmd);
			void_free(cmd.cmdpath);
			arr_clean(cmd.args);
			arr_clean(token.tokens);
		}
		/** free(input2); */
		free(input);
	}
	return (0);
}

