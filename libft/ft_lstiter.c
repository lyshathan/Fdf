/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:04:47 by lthan             #+#    #+#             */
/*   Updated: 2024/11/08 10:17:31 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void	print_content(void *content)
{
	write(1, "-->", 3);
	if(content)
		ft_putstr_fd((char *)content, 1);
	write(1, "\n", 1);
}

int	main()
{
	t_list	*list;
	t_list	*temp;

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
	
	ft_lstiter(list, &print_content);
	return 0;
}  */