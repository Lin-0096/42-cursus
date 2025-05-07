/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:26:53 by linliu            #+#    #+#             */
/*   Updated: 2025/05/07 12:03:28 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_str(const char *s)
{
	int	len;
	
	if (!s)
		return (-1);
	len = 0;
	while (s[len])
		len++;
	return (write (1, s, len));
}
