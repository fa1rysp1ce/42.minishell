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

# define PIPE 1
# define CMD 2

typedef struct s_token
{
	char	**args;
	int		type;
	char	*input;      // Name of input file for <
    char 	*output;     // Name of output file for > or >>
    int 	is_append;         // Flag for >> (1) vs > (0)
    int		heredoc;       // Flag for << (1) or not (0)
	void	*next;
} t_token;

//parsing:

//parse.c:
int		parse(t_token **start, char **line);
int		check_input(char *s);

//chck_input.c
int	is_op(char c);

//variables.c
void	check_vars(char **line);
void	handle_vars(char **line, int i, int len);
char	*replace_var(char **line, int start, int len, char *substr);

//cmd_split.c
int		cmd_split(char const *s, char ***result);

//exit_funcs.c
void	free_split(char **arr, int last, char *s);
void	free_input(char *s,  char *statement);


//execution:

#endif