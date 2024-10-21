/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:06:39 by junruh            #+#    #+#             */
/*   Updated: 2024/05/16 14:45:44 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c, int count)
{
	char	*hexa;

	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (n > 15)
	{
		count = ft_puthex((n / 16), c, count);
		count = ft_puthex((n % 16), c, count);
	}
	else
	{
		write(1, &hexa[n], 1);
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int i = ft_puthex(-2, 'x', 0);
	printf("\n%d", i);
	return (0);
}*/
