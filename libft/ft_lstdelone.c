/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:01:52 by lthan             #+#    #+#             */
/*   Updated: 2024/11/14 14:00:43 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del((void *)lst->content);
	free(lst);
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
	t_list	*memory;
	t_list	*deleted;

	list = ft_lstnew("one");
	ft_lstadd_back(&list, ft_lstnew(strdup("two")));
	ft_lstadd_back(&list, ft_lstnew(strdup("three")));
	ft_lstadd_back(&list, ft_lstnew(strdup("four")));
	ft_lstadd_back(&list, ft_lstnew(strdup("five")));

	temp = list;
	int i = 1;
	printf("Initial list :\n");
	while (temp)
	{
		printf("node #%d = |%s|\n", i++, (char *)temp->content);
		temp = temp->next;
	}
	
	deleted = list->next->next;
	memory = list->next->next->next;
	printf("\nwant to delete node #3 = |%s|\n\n", (char *)deleted->content);
	ft_lstdelone(deleted, &del_content);

	printf("New list :\n");
	i = 1;
 	while (i < 3)
	{
		printf("node #%d = |%s|\n", i++, (char *)list->content);
		list = list->next;
	}
	printf("!!!node #%d deleted!!!\n", i++);
	while (memory)
	{
		printf("node #%d = |%s|\n", i++, (char *)memory->content);
		memory = memory->next;
	}

	printf("\nTry to print node #3 :\n");
	list = list->next;
	printf("node #3 = |%s|\n", (char *)list->content);
	return 0;
} */