/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:38:32 by lthan             #+#    #+#             */
/*   Updated: 2024/11/08 10:04:12 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		del(temp->content);
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

/* void	del_content(void *content)
{
	if(content)
		free(content);
}

int	main()
{
	t_list	*list;
	t_list	*temp;
	t_list	*deleted;

	list = ft_lstnew("one");
	ft_lstadd_back(&list, ft_lstnew(strdup("two")));
	ft_lstadd_back(&list, ft_lstnew(strdup("three")));
	ft_lstadd_back(&list, ft_lstnew(strdup("four")));

	temp = list;
	int i = 1;
	printf("Initial list :\n");
	while (temp)
	{
		printf("node #%d = |%s|\n", i++, (char *)temp->content);
		temp = temp->next;
	}
	
	deleted = list->next->next;
	printf("\nwant to delete node #3 = |%s|\n\n", (char *)deleted->content);
	ft_lstclear(&deleted, &del_content);

	printf("New list :\n");
	i = 1;
 	while (list)
	{
		printf("node #%d = |%s|\n", i++, (char *)list->content);
		list = list->next;
	}
	return 0;
} */