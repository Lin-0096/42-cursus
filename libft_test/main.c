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
