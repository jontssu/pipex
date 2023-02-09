/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:47:35 by jole              #+#    #+#             */
/*   Updated: 2022/11/07 19:19:57 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = 0;
	lst2 = ft_lstnew(f(lst->content));
	if (lst)
		lst = lst->next;
	while (lst && lst2)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&lst2, del);
			break ;
		}
		ft_lstadd_back(&lst2, tmp);
		lst = lst->next;
	}
	return (lst2);
}
