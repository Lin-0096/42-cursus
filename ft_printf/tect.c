/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:03:38 by linliu            #+#    #+#             */
/*   Updated: 2025/05/08 15:20:00 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{ 
	int i = ft_printf("hello%a",1);
	printf("\n%i", i);
	
	/*ft_printf("string");
	ft_printf("\npercent sign: 100%%");
	ft_printf("\ncharacter: %c", '@');
	ft_printf("\nstring: %s", "hello");
	ft_printf("\nnull string: %s", (char*) NULL);
	ft_printf("\nzero: %d", 0);
	ft_printf("\npositive decimal: %i", 69);
	ft_printf("\nnegative decimal: %d", -42);
	ft_printf("\nhexadecimal: %x", 0xc0de);
	ft_printf("\nhexadecimal zero: %x", 0);
	ft_printf("\nhexadecimal uppercase: %X", 0xBEEF);
	printf("\nhexadecimal uppercase: %X", 0xBEEF);
	ft_printf("\nhexadecimal negative: %X", -0xff);
	printf("\nhexadecimal negative: %X", -0xff);
	ft_printf("valid pointer: %p", main);
	ft_printf("null pointer: %p", NULL);
	ft_printf("LONG_MIN pointer: %p", (void*) LONG_MIN);
	ft_printf("LONG_MAX pointer: %p", (void*) LONG_MAX);
	ft_printf("+ULONG_MAX pointer: %p", (void*) +ULONG_MAX);
	ft_printf("-ULONG_MAX pointer: %p", (void*) -ULONG_MAX);
	ft_printf("INT_MAX: %d", INT_MAX);
	ft_printf("INT_MIN: %i", INT_MIN);
	ft_printf("UINT_MAX: %u", UINT_MAX);
	ft_printf("UINT_MAX hexadecimal: %x", UINT_MAX);*/
}

