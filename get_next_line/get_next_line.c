/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:10:58 by linliu            #+#    #+#             */
/*   Updated: 2025/05/20 00:41:34 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	node_join(t_node **stash, char *buf)
{
	t_node	*new;
	t_node	*ptr;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->content = ft_strdup(buf); //! copy of buf,check!!
	if (!new->content)
    	return (free(new));
	new->next = NULL;
	if (!*stash)
		*stash = new;
	else
	{
		ptr = *stash;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;	
	}
}

static size_t	stash_len(t_node *stash)
{
	char	*content;
	size_t		len;

	len = 0;
	while (stash)
	{
		content = stash->content;
		if (!content) //check!!
			return (len);;
		while (*content)
		{
			len++;
			if (*content++ == '\n')
				return (len);
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
		while (stash->content[j] && i < len)  //check i<len
		{
			line[i++] = stash->content[j];
			if (stash->content[j++] == '\n')
			{
				line[i] = '\0';
				return (line);
			}
		}
		stash = stash->next;
	}
	line[i] = '\0';
	return (line);
}

void cut_stash(t_node **stash, size_t len)
{
	t_node	*tmp;
	t_node	*new_node;
	size_t		remain;
	size_t		content_len;
	char	*left;

	remain = len;
	tmp = *stash;
	left = NULL;
	while (tmp && remain > 0 && (content_len = ft_strlen(tmp->content)))
	{
		if (remain < content_len && (left = ft_strdup(tmp->content + remain)))
			break ;
		remain -= content_len;
		tmp = tmp->next;
	}
    free_stash(stash);
	if (!left)
		return ; 
	new_node = malloc(sizeof(t_node));
	if (!new_node) 
		return (free(left));
	new_node->content = left;
	new_node->next = NULL;
	*stash = new_node;
}

char	*get_next_line(int fd)
{
	static t_node	*stash;
	ssize_t			bytes_read;
	char			buf[BUFFER_SIZE + 1];
	size_t				len;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!new_line(stash))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_stash(&stash), NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		node_join(&stash, buf);
	}
	if (!stash)//remember to check it
		return (NULL);
	len = stash_len(stash);
	line = copy_stash(stash, len);//??
	cut_stash(&stash, len);
	return (line);
}
