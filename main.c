#include "minishell.h"

int	main(void)
{
	t_token *ls_ptr;
	char	*line;

	while (1)
	{
		line = readline(GREEN BOLD"minishell:"DEFAULT" ");
		printf("%s\n", line);
		parse(&ls_ptr, line);
		free(line);
	}
	return (0);
}