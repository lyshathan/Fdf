/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:55:18 by lthan             #+#    #+#             */
/*   Updated: 2024/11/06 10:51:57 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (((char *)s1)[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (((char *)s2)[j])
	{
		str[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

/* #include <stdio.h>
int	main (int arc, char ** arv)
{
	(void)arc;

	printf("%s\n", ft_strjoin(arv[1], arv[2]));
	return (0);
} */