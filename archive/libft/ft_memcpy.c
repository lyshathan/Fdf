/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:52:57 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 15:20:03 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(int arc, char **arv)
{
	(void)arc;

	char *dest = strdup(arv[1]);
	char *src = strdup(arv[2]);
	printf("%s", (char *)ft_memcpy(dest, src, atoi(arv[3])));
	return (0);
} */