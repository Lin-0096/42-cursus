/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:01:44 by linliu            #+#    #+#             */
/*   Updated: 2025/05/13 14:16:34 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_uint_base(uintptr_t n, const char *hex, uintptr_t base)
{
	int	count;
	int	check;

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
