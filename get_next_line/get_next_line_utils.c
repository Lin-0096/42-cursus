/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:47:04 by linliu            #+#    #+#             */
/*   Updated: 2025/05/19 15:48:22 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(t_node *stash)
{
	if (!stash)
		return (0);
	while (stash)
	{
		if (ft_strchr(stash->content, '\n'))
			return (1);
		stash = stash->next;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_stash(t_node **stash)
{
	t_node *ptr;

	if (!*stash || !stash)
		return ;
	ptr = *stash;
	while(*stash)
	{
		ptr = (*stash)->next;
		free ((*stash)->content);
		free (*stash);
		*stash = ptr;
	}
	*stash = NULL;
}