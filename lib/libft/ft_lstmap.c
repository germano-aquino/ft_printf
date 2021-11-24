/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:32:14 by grenato-          #+#    #+#             */
/*   Updated: 2021/08/21 16:35:30 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*newLst;
	t_list	*iter;

	if (!lst)
		return (0);
	newLst = NULL;
	while (lst)
	{
		iter = ft_lstnew(f(lst->content));
		if (!iter)
			ft_lstclear(&iter, del);
		else
			ft_lstadd_back(&newLst, iter);
		lst = lst->next;
	}
	return (newLst);
}
