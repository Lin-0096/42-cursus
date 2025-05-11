/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:03:38 by linliu            #+#    #+#             */
/*   Updated: 2025/05/11 23:10:51 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{ 
	
	//close(1);
	printf("\ntest p---------------------------------------------------\n");
	int z = 1;
	int a = ft_printf("fake:hello %p\n", (void*) ULONG_MAX);
	int b = printf("real:hello %p\n", (void*) ULONG_MAX);
	int c = ft_printf("fake:hello %p\n", (void*) -ULONG_MAX);
	int d = printf("real:hello %p\n", (void*) -ULONG_MAX);
	int e = ft_printf("null pointer: %p\n", NULL);
	int f = printf("null pointer: %p\n", NULL);
	int g = ft_printf("null pointer: %p\n", &z);
	int h = printf("null pointer: %p\n", &z);
	printf("fake%d real:%d fake:%d real:%d fake%d real:%d fake:%d real:%d\n", a, b, c, d,e,f,g,h);

	printf("\ntest c---------------------------------------------------\n");
	ft_printf("character: %c\n", '@');
	printf("character: %c\n", '@');
	
	printf("\ntest x,X---------------------------------------------------\n");
	ft_printf("hexadecimal uppercase: %X\n", 0xBEEF);
	printf("hexadecimal uppercase: %X\n", 0xBEEF);
	ft_printf("hexadecimal lowercase: %x\n", UINT_MAX);
	printf("hexadecimal lowercase: %x\n", UINT_MAX);
	ft_printf("hexadecimal zero: %x\n", 0);
	printf("hexadecimal zero: %x\n", 0);
	ft_printf("hexadecimal negative: %X\n", -0xff);
	printf("hexadecimal negative: %X\n", -0xff);
	ft_printf("hexadecimal: %x\n", 0xc0de);
	printf("hexadecimal: %x\n", 0xc0de);
	
	printf("\ntest other---------------------------------------------------\n");
	ft_printf("fake: string\n");
	printf("real: string\n");
	ft_printf("fake: percent sign: 100%%");
	printf("real: percent sign: 100%%");
	int i  = ft_printf("\npercent null: 100%");
	int j  = ft_printf("\npercent exclude: 100%a\n");
	ft_printf("\n%d %d\n", i, j);
	// int i  = printf("\npercent null: 100%");
	// int j  = printf("\npercent exclude: 100%a\n");
	printf("\n%d %d\n", i, j);
	
	printf("\ntest i,d,uint------------------------------------------------\n");
	ft_printf("fake INT_MAX: %d\n", INT_MAX);
	printf("real INT_MAX: %d\n", INT_MAX);
	ft_printf("fake INT_MIN: %i\n", INT_MIN);
	printf("real INT_MIN: %d\n", INT_MIN);
	ft_printf("fake UINT_MAX: %u\n", UINT_MAX);
	printf("real UINT_MAX: %u\n", UINT_MAX);
	ft_printf("fake positive decimal: %i\n", 69);
	printf("real positive decimal: %i\n", 69);
	ft_printf("fake negative decimal: %d\n", -42);
	printf("real negative decimal: %d\n", -42);

	printf("\ntest s------------------------------------------------\n");
	ft_printf("fake string: %s\n", "hello");
	printf("real string: %s\n", "hello");
	ft_printf("fake null string: %s\n", (char*) NULL);
	printf("real null string: %s\n", (char*) NULL);
	ft_printf("fake null string: %s\n","");
	printf("real null string: %s\n", "");

	printf("\ntest write------------------------------------------------\n");
	close(1);
	ft_printf("This won't appear!\n");
	printf("This won't appear!\n");
				
}
