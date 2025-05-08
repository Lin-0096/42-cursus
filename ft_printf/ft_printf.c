/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:42:25 by linliu            #+#    #+#             */
/*   Updated: 2025/05/08 15:13:02 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	check_type(const char format, va_list *args)
{
	if (format == 's')
		return (write_str(va_arg(*args, const char *)));
	if (format == 'c')
		return (write_char(va_arg(*args, int)));
	if (format == 'i' || format == 'd')
		return (write_int(va_arg(*args, int)));
	if (format == 'u')
		return (write_uint(va_arg(*args, unsigned int)));
	if (format == 'x')
		return (write_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (write_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	/*if (format == 'p')
		return (write_pointer(va_arg(*args, int)));*/
	if (format == '%')
		return (write (1, "%", 1));
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (check_type(*format, &args) == -1)
			{
				break;
			}
			else
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
	return (count);
}
