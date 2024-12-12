/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:24:33 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 15:14:06 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(int arc, char **arv)
{
	(void)arc;

	printf("%s\n", (char *)ft_memchr(arv[1], 'x', atoi(arv[2])));
	printf("%s\n", (char *)memchr(arv[1], 'x', atoi(arv[2])));
	return (0);
} */