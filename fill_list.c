#include "minishell.h"

int	eval_str(char **strarr, t_token **list)
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
	{
		//printf("iteration index: %d\n", i);
		if (strarr[i][0] == '|')
			i += pipe_token(strarr, i, list);
		else if (strarr[i][0] == '<' || strarr[i][0] == '>')
		{
			if (strarr[i][0] == '<')
				i += handle_input(strarr[i], strarr, i, list);
			else if (strarr[i][0] == '>')
				i += handle_output(strarr[i], strarr, i, list);
		}
		else
			i += handle_commands(strarr, i, list);
	}
	return (i);
}

int	handle_commands(char **strarr, int pos, t_token **list)
{
	t_token	*token;
	int		i;
	int		count;

	count = 0;
	i = 0;
	token = find_last(list);
	while (strarr[count + pos] != NULL && strarr[count + pos][0] != '|' 
		&& strarr[count + pos][0] != '<' && strarr[count + pos][0] != '>')
		count++;
	token->args = malloc(sizeof(char *) * (count + 1));
	if (!token->args)
		exit_fill_list(strarr, pos, list);
	while (i < count)
	{
		token->args[i] = strarr[pos + i];
		i++;
	}
	token->args[i] = NULL;
	token->type = CMD;
	return (count);
}
/*
char *	handle_heredoc(t_token **list)
{
	int	fd;

	fd = 0;
	fd = open("heredoc.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
}*/

int	handle_input(char *str, char **strarr, int pos, t_token **list)
{
	t_token *token;

	token = find_last(list);
	token->input = strarr[pos + 1];
	if (str[1] == '<')
		token->heredoc = 1;
	else
		token->heredoc = 0;
	free(str);
	return (2);
}

int	handle_output(char *str, char **strarr, int pos, t_token **list)
{
	t_token *token;
	int		fd;

	token = find_last(list);
	if (token->output != NULL)
		free(token->output);
	token->output = strarr[pos + 1];
	if (str[1] == '>')
	{
		token->is_append = 1;
		fd = open(strarr[pos + 1], O_RDWR | O_CREAT, 0666);
	}	
	else
	{
		token->is_append = 0;
		fd = open(strarr[pos + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	}
	close(fd);
	free(str);
	return (2);
}

int	pipe_token(char **strarr, int pos, t_token **list)
{
	t_token *token;

	token = add_node(list);
	//printf("pipe 1\n");
	//token->args = malloc(sizeof(void *) * 2);
	//if (!token->args)
	//	exit(1);
		//return (1); exit from here actually
	//printf("pipe 2\n");
	//token->args[0] = str;
	//token->args[1] = NULL;
	//printf("pipe 3\n");
	free(strarr[pos]);
	token->type = PIPE;
	add_node(list);
	return (1);
}