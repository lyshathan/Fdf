/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:07:05 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 16:49:58 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (((char *)s)[len] == 0 && (char)c == 0)
		return (&((char *)s)[len]);
	while (len--)
	{
		if (((char *)s)[len] == (char)c)
			return (&((char *)s)[len]);
	}
	return (NULL);
}

/* #include <stdio.h>
int	main(int arc, char ** arv)
{
	(void)arc;

	printf("%s", ft_strrchr(arv[1], 'o'));
	return (0);
} */