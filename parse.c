#include "minishell.h"


int	parse(t_token **list, char **line)
{
	char **strarr;
	int		arrsize;

	(void)list;
	strarr = NULL;
	check_vars(line); 
	if (check_input(*line) != 0)
		return (1);
	arrsize = cmd_split(*line, &strarr);
	printf("%d in parse\n", arrsize);
	if (strarr == NULL)
	{
		rl_clear_history();
		exit(2);
	}
	printf("lala\n");
	int i = 0;
	while (strarr[i] != NULL)
	{
		printf("%s\n", strarr[i]);
		i++;
	}
	//free_split(strarr, 2, *line);
	return (0);
}
