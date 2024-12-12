/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:17:57 by lthan             #+#    #+#             */
/*   Updated: 2024/11/12 10:14:09 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!f || !del || !lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = malloc(sizeof(t_list));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem->next = NULL;
		new_elem->content = f(lst->content);
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

/* void	*first_char_x(void *content)
{
	((char *)content)[0] = '_';
	return ((void *)content);
}

void	del_content(void *content)
{
	if (content)
		free(content);
}

int	main()
{
	t_list	*list;
	t_list	*temp;
	t_list	*new_list;

	list = ft_lstnew(strdup("one"));
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
	
	new_list = ft_lstmap(list, &first_char_x, &del_content);

	printf("\nNew list :\n");
	i = 1;
	while (new_list)
	{
		printf("node #%d = |%s|\n", i++, (char *)new_list->content);
		new_list = new_list->next;
	}

	printf("\nVerif initial list :\n");
	i = 1;
	while (list)
	{
		printf("node #%d = |%s|\n", i++, (char *)list->content);
		list = list->next;
	}
	return 0;
} */