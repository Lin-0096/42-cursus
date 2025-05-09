/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:51:27 by linliu            #+#    #+#             */
/*   Updated: 2025/05/09 17:21:48 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	write_char(char c);
int	write_str(const char *s);
int	write_int(int n);
int	write_uint_hex(unsigned long n, const char *hex, unsigned long base);
int	write_pointer(unsigned long ptr, const char *hex);

#endif