/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:45:30 by linliu            #+#    #+#             */
/*   Updated: 2025/04/24 13:35:55 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>
#include <string.h>


char test_func(unsigned int i, char c)
{
    if (i % 2 == 0)
    {
        if (c >= 'a' && c <= 'z') return (c - 32);
    }
    else
    {
        if (c >= 'A' && c <= 'Z') return (c + 32);
    }
    return c;
}

void test_func1(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
		*c = *c - 32;
}

int	main(void)
{
	printf("isalpha fake:%d\n", ft_isalpha(52));
	printf("real:%d\n", isalpha(52));
	printf("fake:%d\n", ft_isalpha('!'));
	printf("real:%d\n", isalpha('!'));
	printf("------------------------------------------------------------------------------------\n");

	printf("isdigit fake:%i\n", ft_isdigit(48));
	printf("real:%i\n", isdigit(48));
	printf("fake:%i\n", ft_isdigit('!'));
	printf("real:%i\n", isdigit('!'));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("isalnum fake:%d\n", ft_isalnum(50));
	printf("real:%d\n", isalnum(50));
	printf("fake:%d\n", ft_isalnum('!'));
	printf("real:%d\n", isalnum('!'));
	printf("fake:%d\n", ft_isalnum('5'));
	printf("real:%d\n", isalnum('5'));
	printf("------------------------------------------------------------------------------------\n");

	printf("isascii fake: %d\n", ft_isascii('!'));
	printf("real:%d\n", isascii('!'));
	printf("fake:%d\n", ft_isascii(-1));
	printf("real:%d\n", isascii(-1));
	printf("fake:%d\n", ft_isascii(127));
	printf("real:%d\n", isascii(127));
	printf("------------------------------------------------------------------------------------\n");

	printf("ft_isprint fake:%d\n", ft_isprint('~'));
	printf("isprint:%d\n", isprint('~'));
	printf("fake:%d\n", ft_isprint(' '));
	printf("real:%d\n", isprint(' '));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("strlen:fake:%ld\n", ft_strlen("hello"));
	printf("real:%ld\n", strlen("hello"));
	printf("fake:%ld\n", ft_strlen(""));
	printf("real:%ld\n", strlen(""));
	printf("------------------------------------------------------------------------------------\n");
	
	char str1[20] = "hello world";
	char str2[20] = "hello world";
	ft_memset(str1, 'Z', 4);
	memset(str2, 'Z', 4);
	printf("String after ft_memset(): %s\n", str1);
	printf("String after memset(): %s\n", str2);
	printf("------------------------------------------------------------------------------------\n");

	char str1[20] = "hello world";
	char str2[20] = "hello world";
	ft_bzero(str1,4);
	bzero(str2,4);
	printf("String after ft_bzero():%s\n", str1 + 4);
	printf("String after bzero():%s\n", str2 + 4);
	printf("------------------------------------------------------------------------------------\n");
	
	char dst1[20];
	char dst2[20];
	char src[20] = "hello world";
	ft_memcpy(dst1, src, 5);
	memcpy(dst2, src, 5);
	printf("ft_memcpy:%s\n", dst1);
	printf("memcpy:%s\n", dst2);
	printf("------------------------------------------------------------------------------------\n");
	
	char str[20] = "helloworld";
	ft_memmove(str+2, str, 3);
	printf("ft_memmove:%s\n", str);
	memmove(str+2, str, 3);
	printf("memmove:%s\n", str);

	char buffer1[50] = {0};
	char buffer2[50] = {0};
	char memmove_str[] = "Hello world! Memmove test string";
	memmove(buffer1, memmove_str, 7);
	ft_memmove(buffer2, memmove_str, 7);
	printf("ft_memmove:%s\n", buffer2);
	printf("memmove:%s\n", buffer1);
	printf("------------------------------------------------------------------------------------\n");
	
	char dst1[6];
	char src1[] = "abcdefg";
	size_t fake_len = ft_strlcpy(dst1, src1, 6);
	printf("ft_strlcpy strinf: %s\n",dst1);
	printf("ft_strlcpy:%zu\n", fake_len);
	
	char dst2[6];
	char src2[] = "abcdefg";
	size_t real_len = strlcpy(dst2, src2, 6);
	printf("real strlcpy strinf:%s\n",dst2);
	printf("real strlcpy:%zu\n", real_len);
	printf("------------------------------------------------------------------------------------\n");
	
	size_t size = 7;
	char dst1[7] = "hello";
	char dst2[7] = "hello";
	char src[] = "world";
	printf("ft_strlcat:%zu\n", ft_strlcat(dst1, src, size));
	printf("strlcat:%zu\n", strlcat(dst2, src, size));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("ft_toupper: %d\n", ft_toupper('a'));
	printf("toupper:%d\n", toupper('a'));
	printf("ft_toupper:%d\n", ft_toupper('a' - 1));
	printf("toupper:%d\n", ft_toupper('a' - 1));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("ft_tolower:%d\n", ft_tolower('A'));
	printf("tolower:%d\n", tolower('A'));
	printf("ft_tolower:%d\n", ft_tolower('A'-1));
	printf("tolower:%d\n", ft_tolower('A'-1));
	printf("------------------------------------------------------------------------------------\n");
	
	const char s[] = "hello,world";
	
	printf("ft_strchr:%s\n", ft_strchr(s, 'l'));
	printf("strchr:%s\n", strchr(s, 'l'));
	printf("ft_strchr:%s\n", ft_strchr(s, 'a'));
	printf("strchr:%s\n", strchr(s, 'a'));
	printf("------------------------------------------------------------------------------------\n");
	
	const char s[] = "abcdef";
	printf("ft_strrchr:%s\n", ft_strrchr(s, 'a'));
	printf("strrchr:%s\n", strrchr(s, 'a'));
	printf("ft_strrchr:%s\n", ft_strrchr(s, 'h'));
	printf("strrchr:%s\n", strrchr(s, 'h'));
	printf("------------------------------------------------------------------------------------\n");
	
	const char s1[] = "hello";
	const char s2[] = "hellop";
	printf("ft_strncmp:%d\n", ft_strncmp(s1, s2, 2));
	printf("strncmp:%d\n", strncmp(s1, s2, 2));
	printf("ft_strncmp:%d\n", ft_strncmp(s1, s2, 6));
	printf("strncmp:%d\n", strncmp(s1, s2, 6));
	printf("------------------------------------------------------------------------------------\n");

	const char s[] = "world";
	printf("ft_memchr:%p\n", ft_memchr(s,'r',4));
	printf("memchr:%p\n", memchr(s,'r',4));
	printf("ft_memchr:%p\n", ft_memchr(s,'o',4));
	printf("memchr:%p\n", memchr(s,'o',4));
	printf("ft_memchr:%p\n", ft_memchr(s,'o',6));
	printf("memchr:%p\n", memchr(s,'o',6));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("ft_memcmp:%d\n", ft_memcmp("hello", "hello", 5));
	printf("memcmp:%d\n", memcmp("hello", "hello", 5));
	
	printf("ft_memcmp:%d\n", ft_memcmp("banana", "anana", 10));
	printf("memcmp:%d\n", memcmp("banana", "anana", 10));
	
	printf("ft_memcmp:%d\n", ft_memcmp("", "hello", 5));
	printf("ft_memcmp:%d\n", memcmp("", "hello", 5));
	printf("------------------------------------------------------------------------------------\n");
	
	const char big[] = "helloworld";
	const char little[] = "lowo";
	size_t len = 6;
	printf("ft_strnstr:%s\n", ft_strnstr(big, little, len));
	printf("strnstr:%s\n", strnstr(big, little, len));
	
	const char big[] = "helloworld";
	const char little[] = "";
	size_t len = 6;
	printf("ft_strnstr:%s\n", ft_strnstr(big, little, len));
	printf("strnstr:%s\n", strnstr(big, little, len));

	const char big[] = "helloworld";
	const char little[] = "hive";
	size_t len = 6;
	printf("ft_strnstr:%s\n", ft_strnstr(big, little, len));
	printf("strnstr:%s\n", strnstr(big, little, len));
	printf("------------------------------------------------------------------------------------\n");

	printf("ft_atoi:%d\n", ft_atoi("9223372036854775808"));
	printf("atoi:%d\n", atoi(s"9223372036854775808"));
	printf("ft_atoi:%d\n", ft_atoi("-234"));
	printf("atoi:%d\n", atoi("-234"));
	printf("ft_atoi:%d\n", ft_atoi("-+234"));
	printf("atoi:%d\n", atoi("-+234"));
	printf("------------------------------------------------------------------------------------\n");

	printf("ft_calloc:%p\n", ft_calloc(2, 3));
	printf("calloc:%p\n", calloc(2, 3));
	printf("------------------------------------------------------------------------------------\n");

	char	*strdup_src = "String to duplicate";
	char	*res1 = "aaa", *res2 = "aaa";
	printf("before:%s | %s\n", res1, res2);
	res1 = ft_strdup(strdup_src);
	res2 = strdup(strdup_src);
	printf("ft_strdup:%s\n", res1);
	printf("strdup:%s\n", res2);
	free(res1);
	free(res2);
	printf("------------------------------------------------------------------------------------\n");
	
	char const s[] = "hello";
	printf("ft_substr:%s\n", ft_substr(s, 2, 3));
	printf("substr:%s\n", substr(s, 2, 3));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("ft_strjoin:%s\n", ft_strjoin("", "world"));
	printf("ft_strjoin:%s\n", ft_strjoin("hello", ""));
	printf("ft_strjoin:%s\n", ft_strjoin("hello", "world"));
	printf("------------------------------------------------------------------------------------\n");
	
	printf("%s\n", ft_strtrim("hello", "llo"));	
	printf("%s\n", ft_strtrim("helloll", "ll"));
	printf("%s\n", ft_strtrim("ohelloh", "oh"));
	printf("%s\n", ft_strtrim("ohelloh", "ho"));
	printf("%s\n", ft_strtrim("ohelloh", ""));
	printf("%s\n", ft_strtrim("-----------", "-"));
	printf("------------------------------------------------------------------------------------\n");
	
	int i = 0;
	char const s[] = "hello";
	char c = 'l';
	char **arr = ft_split(s,c);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	printf("------------------------------------------------------------------------------------\n");
	
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(0));
	printf("------------------------------------------------------------------------------------\n");
	
	char	*input = "abcdefghijklmnopqrstuvwxyz";
	printf("input:%s\n", input);
	printf("ft_strmapi:%s\n", ft_strmapi(input, test_func));
	printf("------------------------------------------------------------------------------------\n");

	char	input1[] = "zyxwvutsrqponmlkjihgfedcba";
	printf("input:%s\n", input1);
	ft_striteri(input1, test_func1);
	printf("ft_striteri:%s\n", input1);
	printf("------------------------------------------------------------------------------------\n");
	
	printf("ft_putchar_fd('A', 1):\n");
	ft_putchar_fd('A', 1);
	printf("ft_putchar_fd('+', 1):\n");
	ft_putchar_fd('+', 1);
	printf("\n------------------------------------------------------------------------------------\n");

	printf("ft_putstr_fd('Hello', 1):\n");
	ft_putstr_fd("Hello", 1);
	printf("ft_putstr_fd('Testing ft_putstr', 1):\n");
	ft_putstr_fd("Testing ft_putstr", 1);
	printf("\n------------------------------------------------------------------------------------\n");
	
	printf("ft_putendl_fd('Hello', 1):\n");
	ft_putendl_fd("Hello", 1);
	printf("\nft_putendl_fd('Test123', 1):\n");
	ft_putendl_fd("Test123", 1);
	printf("------------------------------------------------------------------------------------\n");
	
	printf("ft_putnbr_fd(123456, 1):\n");
	ft_putnbr_fd(123456, 1);
	printf("\nft_putnbr_fd(999999999, 1):\n");
	ft_putnbr_fd(999999999, 1);
	printf("\n");
	return 0;
}
