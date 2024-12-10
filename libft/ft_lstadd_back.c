/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:51:38 by lthan             #+#    #+#             */
/*   Updated: 2024/11/08 09:01:19 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/* int	main()
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew(strdup("bonjour"));
	ft_lstadd_front(&list, ft_lstnew(strdup("hello")));
	ft_lstadd_front(&list, ft_lstnew(strdup("bye")));

	new = ft_lstnew(strdup("last"));

	ft_lstadd_back(&list, new);
	int i = 1;
	while (list)
	{
		printf("%d --> |%s|\n", i++, (char *)list->content);
		list = list->next;
	}
	return 0;
} */