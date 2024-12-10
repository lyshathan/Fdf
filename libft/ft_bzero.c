/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:45:14 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 14:57:04 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return ;
}

/* #include <stdlib.h>
int	main(int arc, char **arv)
{
	(void)arc;

	int len = strlen(arv[1]);
	char *str = strdup(arv[1]);
	ft_bzero(str, atoi(arv[2]));
	int i = 0;
	while (i < len)
	{
		printf("char %d --> %c\n", i, str[i]);
		i++;
	}
	return (0);
} */