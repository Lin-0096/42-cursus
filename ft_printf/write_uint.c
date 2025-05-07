/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:04:45 by lin               #+#    #+#             */
/*   Updated: 2025/05/07 23:23:01 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_uint(unsigned int n)
{
	int		count;

	count = 0;
	if (number > 9)
	{
		count += write_int(number / 10);
	}
	count += write_char(number % 10 + '0');
	return (count);
}
