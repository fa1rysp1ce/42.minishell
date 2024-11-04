#include "minishell.h"

void	free_split(char **arr, int last, char *s)
{
	int	i;

	i = 0;
	free(s);
	while (i < last)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_input(char *s, char *statement)
{
	printf("Error\nWrong input: %s\n", statement);
	free(s);
}