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
	char	**args;
	int		type;
	void	*next;
} t_token;

//parsing:

//parse.c:
int		parse(t_token **start, char **line);
int		check_input(char *s);

//variables.c
void	check_vars(char **line);
void	handle_vars(char **line, int i, int len);
char	*replace_var(char **line, int start, int len, char *substr);

//cmd_split.c
char	**cmd_split(char const *s);

//exit_funcs.c
void	free_split(char **arr, int last, char *s);
void	free_input(char *s,  char *statement);


//execution:

#endif