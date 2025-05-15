/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:11:26 by linliu            #+#    #+#             */
/*   Updated: 2025/05/15 15:50:40 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_strchr(char *content, int c);

#endif
