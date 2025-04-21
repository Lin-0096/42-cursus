/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 00:20:38 by linliu            #+#    #+#             */
/*   Updated: 2025/04/22 00:31:40 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	t_list *ptr;
	int	count;
	
	ptr = lst;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}
