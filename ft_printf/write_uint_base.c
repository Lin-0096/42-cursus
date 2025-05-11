/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:01:44 by linliu            #+#    #+#             */
/*   Updated: 2025/05/11 11:01:47 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_uint_base(unsigned long n, const char *hex, unsigned long base)
{
	int	count;

	count = 0;
	if (n >= base)
	{
		count += write_uint_base(n / base, hex, base);
	}
	count += write_char(hex[n % base]);
	return (count);
}
