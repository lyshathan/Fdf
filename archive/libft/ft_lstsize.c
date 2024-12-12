/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:41:31 by lthan             #+#    #+#             */
/*   Updated: 2024/11/08 08:45:22 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/* int	main()
{
	t_list	*list;

	list = ft_lstnew(strdup("bonjour"));
	ft_lstadd_front(&list, ft_lstnew(strdup("hello")));
	ft_lstadd_front(&list, ft_lstnew(strdup("bye")));
	int i = 1;
	printf("size = %d\n", ft_lstsize(list));
	while (list)
	{
		printf("%d --> |%s|\n", i++, (char *)list->content);
		list = list->next;
	}
	return 0;
} */