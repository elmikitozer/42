/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:23:52 by myevou            #+#    #+#             */
/*   Updated: 2023/11/06 17:28:30 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	size_t	size;

	size = ft_lstsize(lst);
	while (size)
	{
		lst = lst->next;
		size--;
	}
}

//t_list	*ft_lstlast(t_list *lst)
//{
//	while (lst)
//	{
//		if (!lst->next)
//			return (lst);
//		lst = lst->next;
//	}
//	return (lst);
//}
