/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:27:37 by doukim            #+#    #+#             */
/*   Updated: 2023/03/25 22:33:05 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*newcont;
	t_list	*ret;
	t_list	*to_add;

	ret = NULL;
	while (lst)
	{
		newcont = (*f)(lst -> content);
		to_add = ft_lstnew(newcont);
		if (!to_add)
		{
			ft_lstclear(&ret, del);
			(*del)(newcont);
			return (NULL);
		}
		ft_lstadd_back(&ret, to_add);
		lst = lst -> next;
	}
	return (ret);
}
