/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:51:06 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 15:24:33 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (((char *)s)[i] == 0 && (char)c == 0)
		return (&((char *)s)[i]);
	return (NULL);
}

/* #include <stdio.h>
int	main(int arc, char ** arv)
{
	(void)arc;

	printf("%s", ft_strchr(arv[1], 'x'));
	return (0);
} */