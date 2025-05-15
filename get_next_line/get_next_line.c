/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:10:58 by linliu            #+#    #+#             */
/*   Updated: 2025/05/15 17:24:21 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	new_line(t_node *stash)
{
	while (stash)
	{
		if (ft_strchr(stash->content, '\n'))
			return (1);
		stash = stash->next;
	}
	return (0);
}

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
		while(!ptr->next)
			ptr = ptr->next;
		ptr->next = new;		
	}
}
static int	stash_len(t_node *stash)
{
	
}

static char	*copy_stash(t_node *stash, int len)
{
	
}

static void	cut_stash(t_node *stash, int len)
{
	
}

char	*get_next_line(int fd)
{
	static t_node	*stash;
	ssize_t			bytes_read;
	char			buf[BUFFER_SIZE + 1];
	int 			len;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = NULL;
	while(!new_line(stash))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		node_join(&stash, buf);
	}
	if (!stash)
		return (NULL);
	len = stash_len(stash);//calculate the total number of characters up to the first '\n'
	line = copy_stash(stash, len);//Allocates a new string and copies len characters from the stash
	cut_stash(stash, len); //remove ,free, deal with leftover
	return (line);
}
