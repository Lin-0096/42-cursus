/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:01:44 by linliu            #+#    #+#             */
/*   Updated: 2025/05/11 23:06:19 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_uint_base(unsigned long n, const char *hex, unsigned long base)
{
	int	count;
	int check;

	count = 0;
	if (n >= base)
	{
		check = write_uint_base(n / base, hex, base);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = write_char(hex[n % base]);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
