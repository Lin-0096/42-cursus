/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lin <lin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:49:08 by linliu            #+#    #+#             */
/*   Updated: 2025/05/21 23:42:28 by lin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*new_string;

	if (!stash)
    	return (NULL);
	left = ft_strchr(stash, '\n');
	if (!left)
		return (free(stash), NULL); //!!remember free whole string
	left++;
	if (*left == '\0') //check if end of str
		return (free(stash), NULL);
	new_string = ft_strndup(left, ft_strlen(left));
	if (!new_string)
		return (free(stash), NULL);
	free (stash);//!! remember free whole string
	return (new_string);	
}

static	char	*join_stash(char *stash, int fd)
{
	char		*buf;
	ssize_t		bytes;
	
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
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
	if (!stash)
		return (free(stash), stash = NULL, NULL);
	line = copy_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = clean_stash(stash);
	return (line);
}
