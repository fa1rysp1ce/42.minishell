#include "minishell.h"

int	fill_list(char **strarr, t_token **list, int arrsize)
{
	int	i;
	t_token	*token;

	i = 0;
	while (i < arrsize)
	{
		token = add_node(list);
		eval_str(strarr[i], strarr, i, token);
		i++;
	}
}

int	eval_str(char *str, char **strarr, int pos, t_token *token)
{
	if (is_op(str[0]))
	{
		handle_ops(str, strarr, pos, token);
	}
}

int	handle_ops(char *str, char **strarr, int pos, t_token *token)
{
	if (str[0] == '|')
		pipe_token(str, strarr, pos, token);
	else if (str[0] == '<')
		handle_input(str, strarr, pos, token);
	else if (str[0] == '>')
		handle_output(str, strarr, pos, token);
}

static void	handle_input(char *str, char **strarr, int pos, t_token *token)
{
	token->input = strarr[pos + 1];
	if (str[1] == '<')
		token->heredoc = 1;
	else
		token->heredoc = 0;
	free(str);
	strarr[pos] = NULL;
	strarr[pos + 1] = NULL;
}

static void	handle_output(char *str, char **strarr, int pos, t_token *token)
{
	token->output = strarr[pos + 1];
	if (str[1] == '>')
		token->is_append = 1;
	else
		token->is_append = 0;
	free(str);
	strarr[pos] = NULL;
	strarr[pos + 1] = NULL;
}

void	pipe_token(char *str, char **strarr, int pos, t_token *token)
{
	token->args = malloc(sizeof(void *) * 2);
	if (!token->args)
		//exit handle
	token->args[0] = str;
	token->args[1] = NULL;
	token->type = PIPE;
	strarr[pos] = NULL;
}