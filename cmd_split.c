#include "minishell.h"
/*
static int	ft_ccount(char const *s)
{
	int		i;
	int		ccount;
	char	c;

	i = 0;
	ccount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>')
		{
			c = s[i];
			while (s[i] == c)
				i++;
		}
		if (s[i] != '\0')
		{
			ccount++;
			printf("%c\n", s[i]);
		}
		if (s[i - 1] == '|' || s[i - 1] == '<' || s[i - 1] == '>')
		{
			//ccount++;
			printf("%c\n", s[i]);
		}
		while (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>'
			&& s[i] != '\0')
			i++;
	}
	printf("%d\n", ccount);
	return (ccount);
}*/

static int count_sym(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '<' || s[i] == '>' || s[i] == '=')
		{
			if (i > 0 && s[i] != s[i - 1])
				count++;
		}
		i++;
	}
	return (count);
}

static int	ft_ccount(char const *s)
{
	int		i;
	int		ccount;

	i = 0;
	ccount = count_sym(s);
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>'
			|| s[i] == '=')
			i++;
		if (s[i] != '\0')
			ccount++;
		while (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>'
			&& s[i] != '=' && s[i] != '\0')
			i++;
	}
	printf("%d\n", ccount);
	return (ccount);
}

static int	handle_rds(char const *s, int start)
{
	int	len;

	len = 0;
	if (s[len + start] == s[len + start + 1])
		len++;
	else if (s[len + start + 1] == '<' || s[len + start + 1] == '>')
	{
		printf("parse error with redirections\n");
		return (-1);
	}
	if (s[len + start] == s[len + start + 1])
	{
		printf("parse error with redirections\n");
		return (-1);
	}
	return (len);
}

static int	getslen(char const *s, int start)
{
	int	len;

	len = 0;
	if (s[len + start] == '<' || s[len + start] == '>')
		return (1 + handle_rds(s, start));
	else if (s[len + start] == '|' || s[len + start] == '=')
		return (1);
	while (s[len + start] != '\0' && s[len + start] != ' ' && s[len + start]
		!= '<' && s[len + start] != '>' && s[len + start] != '|'
		&& s[len + start] != '=')
	{
		if (s[len + start] == '"')
		{
			while (s[len + start] != '\0' && s[len + start] != '"')
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
	char	*str;

	len = getslen(s, start);
	i = 0;
	if (len == 0)
		return ("");
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**cmd_split(char const *s)
{
	int		i;
	int		j;
	int		ccount;
	int		start;
	char	**result;

	ccount = ft_ccount(s);
	result = malloc(sizeof(char *) * (ccount + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ccount)
	{
		while (s[j] == ' ')
			j++;
		start = j;
		j += getslen(s, start);
		result[i] = ft_createsubstr(s, start);
		//if (result[i] == NULL)
			//exit_split(result, i, s);
		i++;
	}
	result[i] = NULL;
	return (result);
}

/*
int	main(void)
{
	int i = 0;
	char	**result = ft_split("sort =input.txt | uniq>>laaa");
	while (i < 7)
	{
		printf("%s\n", result[i]);
		i++;
	}
	free(result);
	return (0);
}*/