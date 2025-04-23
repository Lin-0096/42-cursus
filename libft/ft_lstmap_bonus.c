/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:17:54 by linliu            #+#    #+#             */
/*   Updated: 2025/04/23 17:14:31 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*arr;
	
	if (!lst || !f || !del)
		return (NULL);
	arr = malloc(sizeof(t_list));
	if (!arr)
		return (NULL);
	while (arr)
	{
		arr -> content = f(lst -> content);
	}
}
