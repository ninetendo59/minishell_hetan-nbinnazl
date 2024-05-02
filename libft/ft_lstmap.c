/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:32:40 by hetan             #+#    #+#             */
/*   Updated: 2023/05/08 22:32:42 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lsnew;
	t_list	*ndnew;
	t_list	*ndpre;

	if (!lst || !f || !del)
		return (NULL);
	ndnew = ft_lstnew((*f)(lst->content));
	if (!ndnew)
		return (NULL);
	lsnew = ndnew;
	ndpre = ndnew;
	lst = lst->next;
	while (lst)
	{
		ndnew = ft_lstnew((*f)(lst->content));
		if (!ndnew)
		{
			ft_lstclear(&lsnew, del);
			return (NULL);
		}
		ndpre->next = ndnew;
		ndpre = ndnew;
		lst = lst->next;
	}
	return (lsnew);
}
