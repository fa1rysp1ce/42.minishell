/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:58:54 by junruh            #+#    #+#             */
/*   Updated: 2024/05/16 17:03:58 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int num, int count)
{
	char	c;

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
