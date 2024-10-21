#ifndef MINISHELL_H
# define MINISHELL_H 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libftplus/includes/libft.h"

# define GREEN "\033[32m"
# define BOLD "\033[1m"
# define DEFAULT "\033[0m"

typedef struct s_token
{
	char	*value;
	char	**args;
	int		type;
	void	*next;
} t_token;

//parsing:

//parse.c:
int	parse(t_token **start, char *line);


//execution:

#endif