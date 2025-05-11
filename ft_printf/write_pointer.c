/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:18:43 by linliu            #+#    #+#             */
/*   Updated: 2025/05/11 23:28:48 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_pointer(void *ptr, const char *hex)
{
	int	count;
	int check;
	
	if (!ptr)
		return (write (1, "(nil)", 5));
	count = 0;
	check = write(1, "0x", 2);
	if (check == -1)
		return (-1);
	count += check;
	check = write_uint_base((unsigned long)ptr, hex, 16);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
