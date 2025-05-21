/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:49:08 by linliu            #+#    #+#             */
/*   Updated: 2025/05/21 18:16:59 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	new_line(char *stash)
{
	if (!stash)
		return (0);
	while (*stash)
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

static char	*copy_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_strndup(stash, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*left;
	int		i;
	
	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i]) //!!if end of string,free and null
		return (free(stash), NULL);
	left = ft_strdup(stash + i);
	free (stash);//!! remember free whole string
	if (!left)
		return (NULL);
	return (left);	
}

static	char	*join_stash(char *stash, int fd)
{
	char		*buf;
	ssize_t		bytes;
	
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!new_line(stash))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static	char	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = join_stash(stash, fd);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = copy_line(stash);
	if (!line)
	return (free(stash), stash = NULL, NULL);
	stash = clean_stash(stash);
	return (line);
}
