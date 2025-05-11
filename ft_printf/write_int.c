/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:28:24 by linliu            #+#    #+#             */
/*   Updated: 2025/05/11 23:16:35 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_int(long n)
{
	int		count;
	int		check;

	count = 0;
	if (n < 0)
	{
		check = write_char('-');
		if (check == -1)
			return (-1);
		count += check;
		n = -n;
	}
	if (n >= 10)
	{
		check = write_int(n / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = write_char(n % 10 + '0');
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
