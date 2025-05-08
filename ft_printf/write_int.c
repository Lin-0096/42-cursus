/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:28:24 by linliu            #+#    #+#             */
/*   Updated: 2025/05/08 14:17:14 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_int(int n)
{
	long	number;
	int		count;

	count = 0;
	number = (long)n;
	if (number < 0)
	{
		count += write_char('-');
		number = -number;
	}
	if (number >= 10)
	{
		count += write_int(number / 10);
	}
	count += write_char(number % 10 + '0');
	return (count);
}
