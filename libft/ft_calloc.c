/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:28:32 by linliu            #+#    #+#             */
/*   Updated: 2025/04/20 21:28:41 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t i;
	void *ptr;
	
	i = count * size;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}
