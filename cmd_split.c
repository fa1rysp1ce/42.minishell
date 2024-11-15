#include "minishell.h"


static int count_sym(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '<' || s[i] == '>' )
		{
			if ((i > 0 && s[i] != s[i - 1]) || i == 0)
				count++;
		}
		i++;
	}
	return (count);
}

int	ft_ccount(char const *s)
{
	int		i;
	int		ccount;

	i = 0;
	ccount = count_sym(s);
	while (s[i] != '\0')
	{
		if (s[i + 1] == '"')
			while (s[i] != '\0' && s[i + 1] != '"')
				i++;
		while (s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>')
			i++;
		if (s[i] != '\0')
			ccount++;
		while (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>'
			&& s[i] != '\0')
			i++;
	}
	//printf("%d\n", ccount);
	return (ccount);
}
/*
static int	handle_rds(char const *s, int start)
{
	int	len;

	len = 0;
	if (s[len + start] == s[len + start + 1])
		len++;
	return (len);
}*/

static int	getslen(char const *s, int start)
{
	int	len;

	len = 0;
	if ((s[len + start] == '<' || s[len + start] == '>') 
		&& (s[len + start] == s[len + start + 1]))
		return (2);
	else if (s[len + start] == '|' || s[len + start] == '<' || s[len + start] == '>')
		return (1);
	while (s[len + start] != '\0' && s[len + start] != ' ' && s[len + start]
		!= '<' && s[len + start] != '>' && s[len + start] != '|')
	{
		//printf("%c\n", s[len + start]);
		if (s[len + start] == '"')
		{
			while (s[len + start] != '\0' && s[len + start + 1] != '"')
				len++;
		}
		if (s[len + start] == 39)
		{
			while (s[len + start] != '\0' && s[len + start] != 39)
				len++;
		}
		if (s[len + start] != 0)
			len++;
	}
	return (len);
}

static char	*ft_createsubstr(char const *s, int start)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	len = getslen(s, start);
	i = 0;
	j = 0;
	if (len == 0)
		return ("");
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len)
	{
		if (s[j + start] != '"' && s[j + start] != 39)
		{
			str[i] = s[j + start];
			i++;
		}
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	fill_arr(char const *s, char ***strarr, int ccount)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < ccount)
	{
		while (s[j] == ' ')
			j++;
		start = j;
		j += getslen(s, start);
		strarr[0][i] = ft_createsubstr(s, start);
		if (strarr[0][i] == NULL)
		{
			free_split(*strarr, i, (char *)s);
			return (-1);
		}
		i++;
	}
	strarr[0][i] = NULL;
	return (0);
}
