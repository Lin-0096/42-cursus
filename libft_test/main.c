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
	printf("%zu\n", ft_strlcpy(dst, src, size));
}
