#include "minishell.h"


int	is_op(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '=')
		return (1);
	return (0);
}

static int	check_ops(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '=')
		{
			if (i > 0 && (is_op(s[i - 1])))
			{
				free_input(s, "mixed/double operators");
				return (1);
			}
		}
		if (s[i] == '<' || s[i] == '>')
		{
			if ((i > 1 && (s[i] == s[i - 1] && s[i] == s[i - 2])) || (i > 0 && (s[i - 1] !=
				s[i] && is_op(s[i - 1]))))
			{
				free_input(s, "mixed/triple operators");
				return (2);
			}
		}
		i++;
	}
	return (0);
}

static int	count_c(char *s, char c)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_input(char *s)
{
	if (count_c(s, '"') % 2 != 0 || count_c(s, 39) % 2 != 0)
	{
		free_input(s, "unclosed quotes");
		return (1);
	}
	if (check_ops(s) != 0)
		return (2);
	return (0);
}