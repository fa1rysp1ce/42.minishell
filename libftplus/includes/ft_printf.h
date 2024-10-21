/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:19:35 by junruh            #+#    #+#             */
/*   Updated: 2024/05/16 19:33:01 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putptr(size_t ptr);
int	ft_putnbr(int n, int count);
int	ft_putunbr(unsigned int n, int count);
int	ft_puthex(unsigned int n, char c, int count);

#endif
