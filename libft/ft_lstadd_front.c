/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:31:15 by lthan             #+#    #+#             */
/*   Updated: 2024/11/08 08:41:37 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* int	main(int arc, char **arv)
{
	(void)arc;
	
	t_list	*list;
	t_list	*new;

	list = ft_lstnew(strdup(arv[1]));
	new = ft_lstnew(strdup(arv[2]));

	ft_lstadd_front(&list, new);

	printf("%s\n", (char *)list->content);
	printf("%s", (char *)list->next->content);
	return 0;
} */