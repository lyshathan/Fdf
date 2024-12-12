/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:20:42 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 17:31:57 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}

/* int	main(int arc, char **arv)
{
	(void)arc;

	char	*content = strdup(arv[1]);
	t_list	*new;
	new = ft_lstnew(content);
	printf("%s\n", (char *)new->content);
	printf("%s\n", (char *)new->next);
	return 0;
} */