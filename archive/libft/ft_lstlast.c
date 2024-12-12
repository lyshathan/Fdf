/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:46:14 by lthan             #+#    #+#             */
/*   Updated: 2024/11/08 08:50:56 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main()
{
	t_list	*list;

	list = ft_lstnew(strdup("bonjour"));
	ft_lstadd_front(&list, ft_lstnew(strdup("hello")));
	ft_lstadd_front(&list, ft_lstnew(strdup("bye")));

	printf("last = %s\n", (char *)ft_lstlast(list)->content);
	return 0;
} */