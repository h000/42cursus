/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:16:11 by hpark             #+#    #+#             */
/*   Updated: 2020/04/21 18:16:14 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new_next;

	if (lst == 0 || !(newlst = ft_lstnew((*f)(lst->content))))
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, new_next);
	}
	return (newlst);
}
