/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:09:16 by linliu            #+#    #+#             */
/*   Updated: 2025/05/08 15:23:53 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	 write_hex(unsigned int n, const char* hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += write_hex(n / 16, hex);
	}
	count += write_char(hex[n % 16]);
	return (count);
}
