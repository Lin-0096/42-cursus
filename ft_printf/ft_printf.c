/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:42:25 by linliu            #+#    #+#             */
/*   Updated: 2025/05/06 16:47:54 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static size_t	write_char(char c)
{
	return (write (1, &c, 1));
}

static size_t	write_str(const char *s)
{
	int	len;
	
	if (!s)
		return (-1);
	len = 0;
	while (s[len])
		len++;
	return (write (1, s, len));
}

static size_t	check_type(const char format, va_list *args)
{
	if (format == 's')
		return (write_str(va_arg(*args, const char *)));
	if (format == 'c')
		return (write_char(va_arg(*args, int)));
	if (format == '%')
		return (write (1, "%", 1));
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int 	count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += check_type(*format, &args);
		}
		else
		{
			count++;
			write (1, format, 1);
		}
		format++;
	}
	va_end(args);
	return count;
}

#include <stdio.h>

int	main(void)
{ 
	ssize_t i = ft_printf("hello %s","linliu");
	printf("%i",i);
}
