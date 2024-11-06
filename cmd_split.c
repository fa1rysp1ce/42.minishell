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
	int j;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '=')
		{
			j = i - 1;
			while (j >= 0 && s[j] != '|' && s[j] != '=')
				j--;
			if (s[j] != '=')
				count++;
		}
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')// || s[i] == '=')
		{
			if (i > 0 && s[i] != s[i - 1])
				count++;
		}
		i++;
	}
	printf("%d sym\n", count);
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
		if (s[i + 1] == '"')
			while (s[i] != '\0' && s[i + 1] != '"')
				i++;
		if (s[i + 1] == 39)
			while (s[i] != '\0' && s[i + 1] != 39)
				i++;
		while (s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>')
			//|| s[i] == '=')
			i++;
		if (s[i] != '\0')
			ccount++;
		while (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>'
			/*&& s[i] != '='*/ && s[i] != '\0')
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
	/*else if (s[len + start + 1] == '<' || s[len + start + 1] == '>')
	{
		printf("parse error with redirections\n");
		return (-1);
	}
	if (s[len + start] == s[len + start + 1])
	{
		printf("parse error with redirections\n");
		return (-1);
	}*/
	return (len);
}

static int	getslen2(char const *s, int start, int len, int call)
{
	while (s[len + start] != '\0' && s[len + start] != ' ' && s[len + start]
		!= '<' && s[len + start] != '>' && s[len + start] != '|')
		//&& s[len + start] != '=')
	{
		if (s[len + start] == '=' && s[len + start + 1] != '\0' && s[len + 
			start + 1] != ' ' && !is_op(s[len + start + 1]) && call == 1)
		{
			return (len);
		}
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

static int	getslen(char const *s, int start)
{
	int			len;
	static int	call = 1;

	len = 0;
	if (s[len + start] == '<' || s[len + start] == '>')
		return (1 + handle_rds(s, start));
	else if (s[len + start] == '|')//|| s[len + start] == '=')
	{
		call = 1;
		return (1);
	}	
	else if (s[len + start] == '=')
	{
		if (s[len + start + 1] != '\0' && s[len + 
			start + 1] != ' ' && !is_op(s[len + start + 1]) && s[len + start - 1] != '\0' && s[len + 
			start - 1] != ' ' && !is_op(s[len + start - 1]) && call != 1)
		{
			call = 2;
			return (1);
		}
	}
	len = getslen2(s, start, len, call);
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

int	cmd_split(char const *s, char ***result)
{
	int		i;
	int		j;
	int		ccount;
	int		start;
	//char	**result;

	ccount = ft_ccount(s);
	//result = *strarr;
	*result = malloc(sizeof(char *) * (ccount + 1));
	if (!result)
	{
		free((char *)s);
		//return (NULL);
	}
	i = 0;
	j = 0;
	while (i < ccount)
	{
		while (s[j] == ' ')
			j++;
		start = j;
		j += getslen(s, start);
		result[0][i] = ft_createsubstr(s, start);
		if (result[0][i] == NULL)
		{
			free_split(*result, i, (char *)s);
			//return (NULL);
		}
		i++;
	}
	result[0][i] = NULL;
	//return (result);
	return (ccount);
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