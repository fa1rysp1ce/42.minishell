#include "minishell.h"

int	main(void)
{
	t_token *ls_ptr;
	char	*line;

	while (1)
	{
		line = readline(GREEN BOLD"minishell:"DEFAULT" ");
		add_history(line);
		rl_replace_line((const char *)line, 0);
		printf("%s (main)\n", line);
		rl_redisplay();
		parse(&ls_ptr, &line);
		free(line);
	}
	rl_clear_history();
	return (0);
}