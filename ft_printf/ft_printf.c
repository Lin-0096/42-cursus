/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:42:25 by linliu            #+#    #+#             */
/*   Updated: 2025/05/09 17:17:27 by linliu           ###   ########.fr       */
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
		return (write_uint_hex(va_arg(*args, unsigned int), "0123456789", 10));
	if (format == 'x')
		return (write_uint_hex(va_arg(*args, unsigned int), "0123456789abcdef", 16));
	if (format == 'X')
		return (write_uint_hex(va_arg(*args, unsigned int), "0123456789ABCDEF", 16));
	if (format == 'p')
		return (write_pointer(va_arg(*args, unsigned long), "0123456789abcdef"));
	if (format == '%')
		return (write (1, "%", 1));
	if (format == 0)
		return (-1)
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		type;

	if (!format || write(1, "", 0) < 0)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			type = check_type(*++format, &args);
			if (type == -1)
				return (-1);
			count += type;
		}
		else
		{
			write (1, format, 1);
			count++;
		}
		format++;
	}
	return (va_end(args), count);
}
