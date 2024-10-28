#include "minishell.h"

static int	ft_ccount(char const *s, char c)
{
	int	i;
	int	ccount;

	i = 0;
	ccount = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			ccount++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (ccount);
}

static int	handle_rds(char const *s, int start)
{
 //handle this
}

static int	getslen(char const *s, int start)
{
	int	len;

	len = 0;
	if (s[len + start] == "<" || s[len + start] == ">")
		return (handle_rds(s, start));
	if (s[len + start] == "|")
		return (1);
	while (s[len + start] != '\0' && s[len + start] != c && s[len + start]
		!= "<" && s[len + start] != ">" && s[len + start] != "|")
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
		len++;
	}
	return (len);
}

static char	*ft_createsubstr(char const *s, char c, int start)
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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		ccount;
	int		start;
	char	**result;

	ccount = ft_ccount(s, c);
	result = malloc(sizeof(char *) * (ccount + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ccount)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		result[i] = ft_createsubstr(s, c, start);
		i++;
	}
	result[i] = NULL;
	return (result);
}
/*
int	main(void)
{
	int i = 0;
	char	**result = ft_split("tripouille", ' ');
	while (i < 4)
	{
		printf("%s\n", result[i]);
		i++;
	}
	free(result);
	return (0);
}*/