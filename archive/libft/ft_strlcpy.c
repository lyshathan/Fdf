/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:44:15 by lthan             #+#    #+#             */
/*   Updated: 2024/11/05 14:24:21 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size <= 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	if (dst[i])
		dst[i] = 0;
	return (ft_strlen((char *)src));
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(int arc, char ** arv)
{
	(void)arc;

	char *dest = strdup(arv[1]);
	char *src = strdup(arv[2]);
	printf("%zu\n", ft_strlcpy(dest, src, atoi(arv[3])));
	printf("%s", dest);
	return (0);
} */