#include "minishell.h"

void	exit_split(char **arr, int last, char *s)
{
	int	i;

	i = 0;
	rl_clear_history();
	free(s);
	while (i < last)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}