/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:36:10 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 16:52:28 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s11;
	char	*s22;

	if (n <= 0)
		return (0);
	s11 = (char *)s1;
	s22 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] != s22[i])
			return ((int)(unsigned char)s11[i] - (unsigned char)s22[i]);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(int arc, char **arv)
{
	(void)arc;

	printf("%d\n", ft_memcmp(arv[1], arv[2], atoi(arv[3])));
	printf("%d\n", memcmp(arv[1], arv[2], atoi(arv[3])));
	return (0);
} */