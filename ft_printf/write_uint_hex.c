/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:19:18 by linliu            #+#    #+#             */
/*   Updated: 2025/05/09 17:05:13 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	 write_uint_hex(unsigned long n, const char* hex, unsigned long base)
{
	int	count;

	count = 0;
	if (n >= base)
	{
		count += write_uint_hex(n / base, hex, base);
	}
	count += write_char(hex[n % base]);
	return (count);
}
