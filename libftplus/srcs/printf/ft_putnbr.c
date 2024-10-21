/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:31:47 by junruh            #+#    #+#             */
/*   Updated: 2024/05/16 14:40:00 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int count)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num > 9)
	{
		count = ft_putnbr((num / 10), count);
		count = ft_putnbr(num % 10, count);
	}
	else
	{
		c = num + '0';
		write(1, &c, 1);
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int i = ft_putnbr(67898989, 0);
	printf("\n%d", i);
	return (0);
}*/
