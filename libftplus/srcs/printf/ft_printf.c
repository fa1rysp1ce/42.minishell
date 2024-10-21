/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:02:27 by junruh            #+#    #+#             */
/*   Updated: 2024/05/16 19:26:46 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_printarg(char c, va_list args)
{
	int	charnum;

	charnum = 0;
	if (c == 'c')
	{
		ft_putchar((char)va_arg(args, unsigned int));
		charnum = 1;
	}
	else if (c == 's')
		charnum = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		charnum = ft_putptr(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		charnum = ft_putnbr(va_arg(args, int), 0);
	else if (c == 'u')
		charnum = ft_putunbr(va_arg(args, unsigned int), 0);
	else if (c == 'x' || c == 'X')
		charnum = ft_puthex(va_arg(args, int), c, 0);
	else if (c == '%')
	{
		write(1, "%", 1);
		charnum = 1;
	}
	return (charnum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_printarg(str[i], args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int i = 8;
	void *ptr = &i;
	ft_printf("a %c\n", 'u');
	ft_printf("b %s\n", "shrek");
	ft_printf("c %p\n", ptr);
	ft_printf("d %d\n", 9);
	ft_printf("e %i\n", -8);
	ft_printf("f %u\n", 3000000000);
	ft_printf("g %x\n", 89);
	ft_printf("h %X\n", 89);
	ft_printf("i %%");
	return (0);
}*/
