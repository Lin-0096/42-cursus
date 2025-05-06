/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:42:25 by linliu            #+#    #+#             */
/*   Updated: 2025/05/06 11:50:10 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static void	write_char(char c)
{
	write (1, &c, 1);
	return ;
}

static void	write_str(const char *s)
{
	int	len;
	
	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write (1, s, len);
	return ;
}

/*static void	write_nbr(int n)
{
	long	number;

	number = (long)n;
	if (number < 0)
	{
		write_char('-');
		number = -number;
	}
	if (number > 9)
	{
		write_nbr(number / 10);
	}
	write_char(number % 10 + '0');
}*/

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int 	count;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				return (write_char(va_arg(args, char)));
		}
		else
			count++;
	}
	va_end(args);
	return count;
}
