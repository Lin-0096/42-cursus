/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:03:38 by linliu            #+#    #+#             */
/*   Updated: 2025/05/12 10:21:17 by linliu           ###   ########.fr       */
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
	ft_printf("fake hexadecimal uppercase: %X\n", 0xBEEF);
	printf("real hexadecimal uppercase: %X\n", 0xBEEF);
	ft_printf("fake hexadecimal lowercase: %x\n", UINT_MAX);
	printf("real hexadecimal lowercase: %x\n", UINT_MAX);
	ft_printf("fake hexadecimal zero: %x\n", 0);
	printf("real hexadecimal zero: %x\n", 0);
	ft_printf("fake hexadecimal negative: %X\n", -0xff);
	printf("real hexadecimal negative: %X\n", -0xff);
	ft_printf("fake hexadecimal: %x\n", 0xc0de);
	printf("real hexadecimal: %x\n", 0xc0de);
	
	printf("\ntest other---------------------------------------------------\n");
	ft_printf("fake: string\n");
	printf("real: string\n");
	ft_printf("fake: percent sign: 100%%\n");
	printf("real: percent sign: 100%%\n");
	
	int i  = ft_printf("\npercent null: 100%");
	int j  = ft_printf("\npercent exclude: 100%a\n");
	ft_printf("\n%d %d\n", i, j);
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
