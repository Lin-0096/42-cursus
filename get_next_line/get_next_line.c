/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:10:58 by linliu            #+#    #+#             */
/*   Updated: 2025/05/16 16:46:53 by linliu           ###   ########.fr       */
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
	new->content = ft_strdup(buf); //! copy of buf
	new->next = NULL;
	if (!*stash)
		*stash = new;
	else
	{
		ptr = *stash;
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
		while (stash->content[j] && i < len)  //check i<len
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
	t_node	*last; //refactor!
	int		content_len;
	char	*left;
	int		i;
	t_node	*new_node;

	last = *stash;
	while(last->next)
		last = last->next;
	content_len = ft_strlen(last->content);
	left = malloc(sizeof(char) * (content_len + 1));
	if (!left)
		return ;
	i = 0;
	while (i < content_len)
	{
		left[i] = last->content[i];
		i++;
	}
	left[i] = '\0';
	free_stash(stash);
	if(left)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->content = left;
		new_node->next = NULL;
		*stash = new_node;
	}
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
		{
			if (bytes_read < 0)
				free_stash(&stash);
			break ; 
		}
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
