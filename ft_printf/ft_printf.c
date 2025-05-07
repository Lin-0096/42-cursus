/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:42:25 by linliu            #+#    #+#             */
/*   Updated: 2025/05/07 17:04:59 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char format, va_list *args)
{
	if (format == 's')
		return (write_str(va_arg(*args, const char *)));
	if (format == 'c')
		return (write_char(va_arg(*args, int)));
	if (format == 'i' || format == 'd')
		return (write_int(va_arg(*args, int)));
	/*if (format == 'u')
		return (write_uint(va_arg(*args, int)));
	if (format == 'x')
		return (write_lowhex(va_arg(*args, int)));
	if (format == 'X')
		return (write_uphex(va_arg(*args, int)));*/
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
		if (*format == '%' /*&& *(++format)*/)
		{
			/*if (value == -1)
			{
				count += 2;
				write (1, "%", 1);
				write (1, format, 1);
			}
			else*/
			count += check_type(*++format, &args);
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
