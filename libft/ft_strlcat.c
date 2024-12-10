/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:38:10 by lthan             #+#    #+#             */
/*   Updated: 2024/11/05 14:38:11 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dst[i])
		dst[i] = '\0';
	return (src_len + dst_len);
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(int arc, char ** arv)
{
	(void)arc;

	char *dest = strdup(arv[1]);
	char *src = strdup(arv[2]);
	printf("%zu\n", strlcat(dest, src, atoi(arv[3])));
	printf("%s", dest);
	return (0);
} */