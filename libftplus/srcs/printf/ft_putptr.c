/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:54:31 by junruh            #+#    #+#             */
/*   Updated: 2024/05/16 19:27:04 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexp(size_t n, int count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 15)
	{
		count = ft_puthexp((n / 16), count);
		count = ft_puthexp((n % 16), count);
	}
	else
	{
		write(1, &hexa[n], 1);
		count++;
	}
	return (count);
}

int	ft_putptr(size_t ptr)
{
	int	count;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = ft_puthexp(ptr, 0);
	return (count + 2);
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 8;
	void	*ptr = &a;
	a = ft_putptr(ptr);
	printf("\n%d", a);
	return (0);
}*/
