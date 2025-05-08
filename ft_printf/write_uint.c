/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:04:45 by lin               #+#    #+#             */
/*   Updated: 2025/05/08 14:17:25 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_uint(unsigned int n)
{
	int		count;

	count = 0;
	if (n >=10)
	{
		count += write_int(n / 10);
	}
	count += write_char(n % 10 + '0');
	return (count);
}
