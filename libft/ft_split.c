/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:39:32 by linliu            #+#    #+#             */
/*   Updated: 2025/04/22 11:57:25 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	issep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (!issep(*s, c) && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (issep(*s, c))
			flag = 0;
		s++;
	}
	return (count);
}

static int	sublen(char const *s, char c)
{
	int	i;

	i = 0;
	while (!issep(*s, c) && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	char	**arr;

	a = 0;
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (*s)
	{
		if (!issep(*s, c))
		{
			arr[a] = ft_substr(s, 0, sublen(s, c));
			s += sublen(s, c);
			a++;
		}
		else
			s++;
	}
	arr[a] = NULL;
	return (arr);
}
