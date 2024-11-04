#include "minishell.h"


int	parse(t_token **list, char **line)
{
	char **strarr;

	(void)list;
	check_vars(line); 
	if (check_input(*line) != 0)
		return (1);
	strarr = cmd_split(*line);
	if (strarr == NULL)
		return (2);
	int i = 0;
	while (strarr[i] != NULL)
	{
		printf("%s\n", strarr[i]);
		i++;
	}

	return (0);
}
