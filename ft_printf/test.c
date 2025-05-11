/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:03:38 by linliu            #+#    #+#             */
/*   Updated: 2025/05/11 12:27:04 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{ 
	int z = 1;
	
	//close(1);
	printf("\ntest p---------------------------------------------------\n");
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
	ft_printf("hexadecimal zero: %x\n", 0);
	ft_printf("hexadecimal negative: %X\n", -0xff);
	printf("hexadecimal negative: %X\n", -0xff);
	ft_printf("hexadecimal: %x\n", 0xc0de);
	printf("hexadecimal: %x\n", 0xc0de);
	
	printf("\ntest other---------------------------------------------------\n");
	ft_printf("string\n");
	ft_printf("percent sign: 100%%");
	int i  = ft_printf("\npercent null: 100%");
	int j  = ft_printf("\npercent exclude: 100%a\n");
	printf("\n%d %d\n", i, j);
	
	printf("\ntest i,d,uint------------------------------------------------\n");
	ft_printf("INT_MAX: %d\n", INT_MAX);
	ft_printf("INT_MIN: %i\n", INT_MIN);
	ft_printf("UINT_MAX: %u\n", UINT_MAX);
	ft_printf("positive decimal: %i\n", 69);
	ft_printf("negative decimal: %d\n", -42);

	printf("\ntest s------------------------------------------------\n");
	ft_printf("fake string: %s\n", "hello");
	printf("real string: %s\n", "hello");
	ft_printf("fake null string: %s\n", (char*) NULL);
	printf("real null string: %s\n", (char*) NULL);

	printf("\ntest write------------------------------------------------\n");
	close(1);
	ft_printf("This won't appear!\n");
	printf("This won't appear!\n");
}

