/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:49:08 by linliu            #+#    #+#             */
/*   Updated: 2025/05/20 13:54:27 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char 		buf[BUFFER_SIZE + 1];
	int 		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
}