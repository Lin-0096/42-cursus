/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:28:24 by linliu            #+#    #+#             */
/*   Updated: 2025/05/07 12:03:24 by linliu           ###   ########.fr       */
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
	if (number > 9)
	{
		count += write_int(number / 10);
	}
	return (count += write_char(number % 10 + '0'));
}

