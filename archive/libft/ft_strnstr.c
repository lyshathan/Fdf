/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:47:31 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 16:55:00 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (ft_strlen(little) == 0 || *little == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (((char *)big)[i] && i <= len)
	{
		j = i;
		k = 0;
		while ((((char *)little)[k] || ((char *)big)[j])
			&& ((char *)big)[j] == ((char *)little)[k])
		{
			j++;
			k++;
		}
		if (((char *)little)[k] == 0 && j <= len)
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(int arc, char **arv)
{
	(void)arc;

	printf("%s\n", ft_strnstr(arv[1], arv[2], atoi(arv[3])));
	return (0);
} */