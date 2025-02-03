/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:20:01 by jadalid-          #+#    #+#             */
/*   Updated: 2025/01/31 20:15:15 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*cont;

	if (!lst || !del)
		return (0);
	new_list = NULL;
	while (lst != NULL)
	{
		cont = f(lst->content);
		if (f)
			new_node = ft_lstnew(cont);
		else
			new_node = ft_lstnew(lst->content);
		if (!new_node)
		{
			del(cont);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
