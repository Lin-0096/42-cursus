/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:47:23 by linliu            #+#    #+#             */
/*   Updated: 2025/04/23 16:07:47 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	t_list	*ptr;
	t_list	*tmp;
	
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr -> next;
		del (ptr -> content);
		free (ptr);
		ptr = tmp;
	}
	*lst = NULL;
}