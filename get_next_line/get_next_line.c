/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:10:58 by linliu            #+#    #+#             */
/*   Updated: 2025/05/16 13:44:38 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	node_join(t_node **stash, char *buf)
{
	t_node	*new;
	t_node	*ptr;

	new->content = ft_strdup(buf); //! copy of buf
	new->next = NULL;
	if (!*stash)
		stash = new;
	else
	{
		while (!ptr->next)
			ptr = ptr->next;
		ptr->next = new;	
	}
}

static int	stash_len(t_node *stash)
{
	int	len;
	int	j;

	len = 0;
	while (stash)
	{
		j = 0;
		while (stash->content[j])
		{
			len++;
			if (stash->content[j] == '\n')
				break ;
			j++;
		}
		stash = stash->next;
	}
	return (len);
}

static char	*copy_stash(t_node *stash, int len)
{
	char	*line;
	int		i;
	int		j;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash && i < len)
	{
		j = 0;
		while (stash->content[j] && i < len)  //do i have to check it again?
		{
			line[i++] = stash->content[j];
			if (stash->content[j] == '\n')
				break ;
			j++;
		}
		stash = stash->next;
	}
	line[i] = '\0';
	return (line);
}

static void	cut_stash(t_node **stash, int len)
{
	
}

char	*get_next_line(int fd)
{
	static t_node	*stash;
	ssize_t			bytes_read;
	char			buf[BUFFER_SIZE + 1];
	int				len;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!new_line(stash))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ; //??do i have to free??
		buf[bytes_read] = '\0';
		node_join(&stash, buf);
	}
	if (!stash)//remember to check it
		return (NULL);
	len = stash_len(stash);
	line = copy_stash(stash, len);
	cut_stash(&stash, len); //remove ,free, deal with leftover
	return (line);
}
