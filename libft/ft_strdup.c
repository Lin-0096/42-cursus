/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:27:36 by linliu            #+#    #+#             */
/*   Updated: 2025/04/20 21:27:58 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;
	size_t len;
	
	len = ft_strlen(s1);
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	dst = (char *)ft_memcpy(dst, s1, len);
	return (dst);
}
