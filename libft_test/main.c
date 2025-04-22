#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_isalpha(52));
	printf("%d\n", isalpha(52));
}

#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("%i\n", ft_isdigit(48));
	printf("%i\n", isdigit(48));
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalnum(50));
}

#include <stdio.h>
int main(void)
{
	const char *s = "hello";
	printf("%ld\n", ft_strlen(s));
}

#include <stdio.h>
#include <string.h>
int main() 
{
   char str[20] = "hello world";
   ft_memset(str, 'Z', 4);
   printf("String after memset(): %s\n", str);
   return 0;
}

#include <stdio.h>
int main(void)
{
	char str[20] = "hello world";
	ft_bzero(str,4);
	printf("%s\n", str + 4);
}
#include <stdio.h>
int	main(void)
{
	char dst[20];
	char src[20] = "hello world";
	ft_memcpy(dst, src, 5);
	printf("%s\n", dst);
}
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[20] = "helloworld";
	ft_memmove(str+2, str, 3);
	printf("%s\n", str);
	memmove(str+2, str, 3);
	printf("%s\n", str);
}

#include <stdio.h>
int	main(void)
{
	size_t size = 6;
	char dst[size];
	char src[] = "abcdefg";
	size_t i = ft_strlcpy(dst, src, size);
	printf("%s\n",dst);
	printf("%zu\n", i);
}

#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	size_t size = 7;
	char dst1[7] = "hello";
	char dst2[7] = "hello";
	char src[] = "world";
	printf("%zu\n", ft_strlcat(dst1, src, size));
	printf("%zu\n", strlcat(dst2, src, size));
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s[] = "hello";
	int c = 0;
	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", strchr(s, c));
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s[] = "abcdef";
	int c = 97;
	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	const char s1[] = "hello";
	const char s2[] = "he";
	printf("%d\n", ft_strncmp(s1, s2, 2));
	printf("%d\n", strncmp(s1, s2, 2));
	 
}
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char s[] = "world";
	int c = 114;
	size_t i = 4;
	printf("%p\n", ft_memchr(s,c,i));
	printf("%p\n", memchr(s,c,i));
}

#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	const char big[] = "helloworld";
	const char little[] = "lowo";
	size_t len = 6;
	printf("%s\n", ft_strnstr(big, little, len));
	printf("%s\n", strnstr(big, little, len));	
}
#include <stdio.h>
int	main(void)
{
	const	char	str[] = "9223372036854775808";
	printf("%d\n", ft_atoi(str));
}

#include <stdio.h>

int	main(void)
{
	char const s[] = "hello";
	unsigned int start = 2;
	size_t len = 3;
	printf("%s\n", ft_substr(s, start, len));
}
#include <stdio.h>

int	main(void)
{
	char *s1 = "he";
	char *s2 = "";
	printf("%s\n", ft_strjoin(s1, s2));
}
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("hello", "llo"));	
	printf("%s\n", ft_strtrim("helloll", "ll"));
	printf("%s\n", ft_strtrim("ohelloh", "oh"));
	printf("%s\n", ft_strtrim("ohelloh", "ho"));
}
#include <stdio.h>
int	main(void)
{
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
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(0));
}